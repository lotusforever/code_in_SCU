#include <iostream>
#include "node.h"
#include "linkqueue.h"
using namespace std;
int main() {
    LinkQueue<int>lq;
    lq.InQueue(1);
    lq.InQueue(2);
    lq.InQueue(3);
    lq.InQueue(4);
    lq.InQueue(5);
    lq.Traverse();
    cout<<"长度："<<lq.Length()<<endl;
    lq.OutQueue();
    cout<<"出队后";
    lq.Traverse();
    int e=0;
    lq.OutQueue(e);
    cout<<"再次出队所得到的元素:";
    cout<<e<<endl;
    lq.Traverse();
    int q=0;
    lq.GetHead(q);
    cout<<"此时队首元素为："<<q<<endl;
    lq.Clear();
    cout<<"清空队列后";
    lq.Traverse();
}