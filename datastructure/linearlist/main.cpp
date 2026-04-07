#include <iostream>
#include "node.h"
#include "linklist.h"
using namespace std;

int main() {
    Linklist<int> mylist;
    mylist.Insert(1,1);
    mylist.Insert(2,2);
    mylist.Insert(3,3);
    mylist.Insert(4,4);
    mylist.Insert(5,5);
    mylist.Insert(6,6);
    cout<<"长度为："<<mylist.Length()<<endl;
    mylist.Traverse();
    mylist.SetElem(5,9);
    mylist.GetElem(5);
    cout<<"修改后";
    mylist.Traverse();
    mylist.Delete(5);
    cout<<"删除第5个节点后";
    mylist.Traverse();
    mylist.Clear();
    cout<<"清空后的链表：(不输出内容即代表链表位空)";
    mylist.Traverse();
    cout<<endl;
    system("pause");
    return 0;
}