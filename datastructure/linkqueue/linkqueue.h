//
// Created by ASUS on 2025/10/26.
//

#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include <iostream>
#include "node.h"
using namespace std;

template<class ElemType>
class LinkQueue {
private:
    Node<ElemType> *front;
    Node<ElemType> *rear;
    int count;
public:
    LinkQueue();
    virtual~LinkQueue();
    int Length()const;
    bool Empty()const;
    void Clear();
    void Traverse()const;
    bool OutQueue(ElemType& e);
    bool OutQueue();
    bool GetHead(ElemType& e)const;
    bool InQueue(const ElemType& e);
    LinkQueue(const LinkQueue<ElemType>&source);
    LinkQueue<ElemType>& operator=(const LinkQueue<ElemType>&source);
};

template<class ElemType>
LinkQueue<ElemType>::LinkQueue() {
    front=rear=new Node<ElemType>;//创建了一个空节点，next=NULL
    count=0;
}

template<class ElemType>
LinkQueue<ElemType>::~LinkQueue() {
    Clear();//清空队列
    delete front;
}

template<class ElemType>
int LinkQueue<ElemType>::Length()const {
    return count;
}

template<class ElemType>
bool LinkQueue<ElemType>::Empty()const {
    return count == 0;
}

template<class ElemType>
void LinkQueue<ElemType>::Clear() {
    while (!Empty()) {
        OutQueue();//通过出队来删除节点
    }
}

template<class ElemType>
void LinkQueue<ElemType>::Traverse()const {
    cout<<"队列中的情况为：";
    Node<ElemType>*curr=front->next;
    while (curr!=nullptr) {//empty的依据是count值，count不变，死循环，不能使用！Empty来判断
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    while(Empty()) {
        cout<<"空";
        return;
    }cout<<endl;
}

template<class ElemType>
bool LinkQueue<ElemType>::OutQueue(ElemType &e) {
    if (!Empty()) {
        Node<ElemType>* temp=front->next;
        front->next=temp->next;
        e=temp->data;
        delete temp;
        count--;
        return true;
    }else return false;
}

template<class ElemType>
bool LinkQueue<ElemType>::OutQueue() {
    if (!Empty()) {
        Node<ElemType>* temp=front->next;
        front->next=temp->next;
        delete temp;
        count--;
        return true;
    }else return false;
}

template<class ElemType>
bool LinkQueue<ElemType>::GetHead(ElemType &e) const {
    if (!Empty()) {
        e=front->next->data;
        return true;
    }else return false;
}

template<class ElemType>
bool LinkQueue<ElemType>::InQueue(const ElemType&e) {
    if ((new Node<ElemType>(e,NULL))!=NULL) {
        Node<ElemType>* temp=rear;
        rear=new Node<ElemType>(e,NULL);
        temp->next=rear;
        count++;
        return true;
    }
    else return false;//动态内存耗尽，无法入队
}

template<class ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType>& source) {//拷贝构造函数主要用来创建新对象，不需要清空本体，考虑自我复制
    for (Node<ElemType>* curr=source.front->next;curr!=NULL;curr=curr->next) {
        //data=curr->data;
        //next=curr->next;这两种复制方法错误，没有更新尾指针
        InQueue(curr->data);
        //使用curr保证front不被修改
    }
}

template<class ElemType>
LinkQueue<ElemType>& LinkQueue<ElemType>::operator=(const LinkQueue<ElemType>& source) {
    if (this!=&source) {//赋值运算可能把一个对象赋值到已有的对象
        Clear();//清空被赋值对象
        for (Node<ElemType>* curr=source.front->next;curr!=NULL;curr=curr->next) {
            InQueue(curr->data);
        }
    }
    return *this;
}
#endif //LINKQUEUE_H
