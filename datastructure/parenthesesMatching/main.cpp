#include <iostream>
#include <string>
#include "node.h"
#include "linkstack.h"
using namespace std;

void matchParentheses(const string& expression) {
    LinkStack<char> stack;
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.Push(ch);
        }
        else if (ch == ')') {
            if (stack.Empty()) {
                cout << "括号不匹配" << endl;
                return;
            }
            char e;
            stack.Pop(e);
            if (e != '(') {
                cout << "括号不匹配" << endl;
                return;
            }
        }
        else if (ch == '}') {
            if (stack.Empty()) {
                cout << "括号不匹配" << endl;
                return;
            }
            char e;
            stack.Pop(e);
            if (e != '{') {
                cout << "括号不匹配" << endl;
                return;
            }
        }
        else if (ch == ']') {
            if (stack.Empty()) {
                cout << "括号不匹配" << endl;
                return;
            }
            char e;
            stack.Pop(e);
            if (e != '[') {
                cout << "括号不匹配" << endl;
                return;
            }
        }
    }

    if (stack.Empty()) {
        cout << "括号匹配" << endl;
    } else {
        cout << "括号不匹配" << endl;
    }
}
int main()
{
    string expression1="((x^2 +((2*x)+(3*5))+ [3x - {x}]) * {x - [1]})";
    cout<<"表达式1：";
    matchParentheses(expression1);

    string expression2="{[ (x + 1)^2 ] * [ x^3 - {2x - (x - 1) ]}";
    cout<<"表达式2：";
    matchParentheses(expression2);
    return 0;
}