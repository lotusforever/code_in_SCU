#include <iostream>
#include "node.h"
#include "linkstack.h"
using namespace std;

int main()
{
    LinkStack<int> ls;
    ls.Push(1);
    ls.Push(2);
    ls.Push(3);
    ls.Push(4);
    ls.Push(5);
    ls.Push(6);
    ls.Traverse();
    cout << "ls的长度为：" << ls.Length() << endl;
    ls.Pop();
    cout << "删除一个栈顶元素后";
    ls.Traverse();
    int e;
    ls.Top(e);
    cout << "此时栈顶元素为：";
    cout<<e<<endl;
    LinkStack<int> ls1(ls);  // 测试拷贝构造
    LinkStack<int> ls2 = ls; // 测试赋值运算符重载
    cout << "对于ls1";
    ls1.Traverse();
    cout << "对于ls2";
    ls2.Traverse();
    ls1.Clear();
    ls2.Clear();
    ls.Clear();
    ls.Traverse(); // 检验是否清空成功
    return 0;
}
