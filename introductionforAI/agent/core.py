from openai import OpenAI
# 必须导入 tools 中的具体函数，否则 eval 无法找到它们
from tools import add, compare, count_letter_in_string, mul, minus
import json

SYSTEM_PROMPT = """
你是一个叫JUN人工智能助手。你的输出应该与用户的语言保持一致。
当用户的问题需要调用工具时，你可以从提供的工具列表中调用适当的工具函数。
不需要调用工具时，请直接回答用户的问题。
"""

class Agent:
    def __init__(self, api_key: str, base_url: str, model: str, tools: list, verbose: bool = False):
        self.client = OpenAI(api_key=api_key, base_url=base_url)
        self.tools = tools
        self.model = model
        self.messages = [{"role": "system", "content": SYSTEM_PROMPT}]
        self.verbose = verbose

    def function_call_playground(self, prompt):
        # 1. 添加用户消息
        self.messages.append({'role': 'user', 'content': prompt})

        # 2. 第一次调用模型，看是否需要工具
        response = self.client.chat.completions.create(
            model=self.model,
            messages=self.messages,
            temperature=0.01,
            top_p=0.95,
            stream=False,
            tools=self.tools
        )

        message = response.choices[0].message

        # 判断模型是否想要调用工具
        if message.tool_calls:
            # --- 情况 A: 模型决定调用工具 ---
            func_name = message.tool_calls[0].function.name
            func_args = json.loads(message.tool_calls[0].function.arguments)

            if self.verbose:
                print(f"DEBUG: Calling tool {func_name} with {func_args}")

            # 执行工具函数
            try:
                # 注意：这里使用 eval 必须确保函数已在当前文件导入
                func_out = eval(f'{func_name}(**{func_args})')
            except Exception as e:
                func_out = str(e)

            # 将工具调用过程和结果加入历史
            self.messages.append(message)
            self.messages.append({
                'role': 'tool',
                'content': f'{func_out}',
                'tool_call_id': message.tool_calls[0].id
            })

            # 3. 把工具结果给模型，让它生成最终回答
            response_second = self.client.chat.completions.create(
                model=self.model,
                messages=self.messages,
                temperature=0.01,
                top_p=0.95,
                stream=False,
                tools=self.tools
            )
            final_content = response_second.choices[0].message.content

        else:
            # --- 情况 B: 模型不需要工具，直接闲聊 ---
            final_content = message.content
            self.messages.append(message)

        return final_content