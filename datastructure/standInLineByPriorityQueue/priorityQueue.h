//
// Created by ASUS on 2025/12/19.
//

#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include <iostream>
#include "node.h"
using namespace std;

template<class ElemType>
class HospitalRegistration {
private:
    Node<ElemType> *front;
    Node<ElemType> *rear;
    int count;
public:
    HospitalRegistration();
    virtual~HospitalRegistration();
    void Clear();
    bool Empty()const;
    void Display()const;
    bool GetHead(ElemType& e)const;
    bool Cure();
    bool Register(const ElemType& e);
    bool PriorRegister(const ElemType& e);//病重病人优先插队
};

template<class ElemType>
HospitalRegistration<ElemType>::HospitalRegistration() {
    front=rear=new Node<ElemType>;//创建了一个空节点，next=NULL
    count=0;
}

template<class ElemType>
HospitalRegistration<ElemType>::~HospitalRegistration() {
    Clear();//清空队列
    delete front;
}



template<class ElemType>
bool HospitalRegistration<ElemType>::Empty()const {
    return count == 0;
}
template<class ElemType>
bool HospitalRegistration<ElemType>::GetHead(ElemType &e) const {
    if (!Empty()) {
        e=front->next->data;
        return true;
    }else return false;
}
template<class ElemType>
void HospitalRegistration<ElemType>::Clear() {
    while (!Empty()) {
        Cure();//通过出队来删除节点
    }
}

template<class ElemType>
void HospitalRegistration<ElemType>::Display()const {
    cout<<"当前排队情况为：";
    Node<ElemType>*curr=front->next;
    while (curr!=nullptr) {//empty的依据是count值，count不变，死循环，不能使用！Empty来判断
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    while(Empty()) {
        cout<<"空"<<endl;;
        return;
    }cout<<endl;
}


template<class ElemType>
bool HospitalRegistration<ElemType>::Cure() {
    if (!Empty()) {
        Node<ElemType>* temp=front->next;
        front->next=temp->next;
        delete temp;
        count--;
        return true;
    }else return false;
}

template<class ElemType>
bool HospitalRegistration<ElemType>::Register(const ElemType&e) {
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
bool HospitalRegistration<ElemType>::PriorRegister(const ElemType&e) {
    if (front!=nullptr) {
        Node<ElemType>* temp=new Node<ElemType>(e,front->next);
        front->next=temp;
        count++;
        return true;
    }
    else return false;
}

#endif
