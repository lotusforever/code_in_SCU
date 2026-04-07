def add(a: float, b: float):
    return a + b

def mul(a: float, b: float):
    return a * b

def minus(a: float, b: float): # 新增的减法
    return a - b

def compare(a: float, b: float):
    if a > b:
        return f'{a} is greater than {b}'
    elif a < b:
        return f'{b} is greater than {a}'
    else:
        return f'{a} is equal to {b}'

def count_letter_in_string(a: str, b: str):
    string = a.lower()
    letter = b.lower()
    count = string.count(letter)
    return (f"The letter '{letter}' appears {count} times in the string.")

tools = [
    {
        'type': 'function',
        'function': {
            'name': 'add',
            'description': 'Compute the sum of two numbers',
            'parameters': {
                'type': 'object',
                'properties': {
                    'a': {'type': 'integer', 'description': 'A number'},
                    'b': {'type': 'integer', 'description': 'A number'},
                },
                'required': ['a', 'b'],
            },
        }
    },
    {
        'type': 'function',
        'function': {
            'name': 'mul',
            'description': 'Calculate the product of two numbers',
            'parameters': {
                'type': 'object',
                'properties': {
                    'a': {'type': 'integer', 'description': 'A number'},
                    'b': {'type': 'integer', 'description': 'A number'},
                },
                'required': ['a', 'b'],
            },
        }
    },
    {
        'type': 'function',
        'function': {
            'name': 'minus',
            'description': 'Calculate the difference between two numbers',
            'parameters': {
                'type': 'object',
                'properties': {
                    'a': {'type': 'integer', 'description': 'A number'},
                    'b': {'type': 'integer', 'description': 'A number'},
                },
                'required': ['a', 'b'],
            },
        }
    },
    {
        'type': 'function',
        'function': {
            'name': 'count_letter_in_string',
            'description': 'Count letter number in a string',
            'parameters': {
                'type': 'object',
                'properties': {
                    'a': {'type': 'string', 'description': 'source string'},
                    'b': {'type': 'string', 'description': 'letter'},
                },
                'required': ['a', 'b'],
            },
        }
    },
    {
        'type': 'function',
        'function': {
            'name': 'compare',
            'description': 'Compare two number, which one is bigger',
            'parameters': {
                'type': 'object',
                'properties': {
                    'a': {'type': 'number', 'description': 'A number'},
                    'b': {'type': 'number', 'description': 'A number'},
                },
                'required': ['a', 'b'],
            },
        }
    }
]