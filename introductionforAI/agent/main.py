import os
from dotenv import load_dotenv
from core import Agent
from tools import tools

# 加载环境变量
load_dotenv()
API_KEY = os.getenv('SF_API_KEY')
BASE_URL = "https://api.siliconflow.cn/v1"

if __name__ == "__main__":
    # 1. 创建 Agent 实例
    try:
        agent = Agent(
            api_key=API_KEY,
            base_url=BASE_URL,
            # 关键修改：使用了支持工具调用的通用大模型
            model="Qwen/Qwen2.5-72B-Instruct",
            tools= tools,
            verbose=True  # 设置为 True 可以看到工具调用信息
        )
    except NameError as e:
        print(f"错误：Agent 类或相关辅助函数未定义/导入。请检查代码结构。详细: {e}")
        exit()

    print("输入 'exit' 退出。")
    print("---------------------------------------")

    # 2. 开始交互式对话循环
    while True:
        # 使用彩色输出区分用户输入和AI回答
        prompt = input("\033[94mUser: \033[0m")  # 蓝色显示用户输入提示
        if prompt.lower() == "exit":
            break
        # 3. 获取 AI 回复
        try:
            response = agent.function_call_playground(prompt)
            print("\033[92mAssistant: \033[0m", response, "\n")  # 绿色显示AI助手回答
        except Exception as e:
            # 捕获服务器繁忙等错误，防止程序直接崩溃退出
            print(f"\033[91m请求出错 (请重试): {e}\033[0m\n")