//
// Created by ASUS on 2025/10/16.
//

#ifndef LIST_H
#define LIST_H
using namespace std;
#include "node.h"   //包含节点模板

template<class ElemType>
class Linklist{
    Node<ElemType>*head;
    int count;
    Node<ElemType>* temPtr;
public:
    Linklist();//默认构造函数
    ~Linklist();//析构函数
    int Length();//读取链表的长度
    bool isEmpty()const;//判断是否为空；
    void Traverse();//遍历整个链表
    ElemType GetElem(int position);//返回position位置的值；
    Node<ElemType>* GetElemPtr(int position);//返回指向某个位置的节点的指针
    bool SetElem(int position,const ElemType data);//在指定位置设置某一个值
    bool Delete(int position);//删除某一个位置的节点
    bool Insert(int position,const ElemType e);
    void Clear();//清空整个链表
};

template<class ElemType>
Linklist<ElemType>::Linklist() {
    head=new Node<ElemType>;//默认构造创建一个空节点来当作头节点，返回node*指针给head
    head->next=NULL;
    count=0;
}//创建只含有一个头节点的空链表

template<class ElemType>
Linklist<ElemType>::~Linklist() {
      Clear();
}//清空整个链表

template<class ElemType>
bool Linklist<ElemType>::isEmpty()const {
    Node<ElemType>* temPtr=head->next;
    if (temPtr!=NULL) {
        return false;
    }else return true;
}//判断是否为空链表，除了初始创建空链表的时候，其他所有操作都需要首先判断链表是否为空；

template<class ElemType>
int Linklist<ElemType>::Length(){
    count=0;
    temPtr=head->next;
    if (isEmpty()) {
        return count;
    }//如果链表为空，直接就返回0;
    while (temPtr!=NULL) {
        count++;
        temPtr=temPtr->next;//只要指针域不是NULL，就一直向后移动指针。
    }return count;
}

template<class ElemType>
void Linklist<ElemType>::Traverse(){
    cout<<"此时链表中的数据为：";
    for (temPtr=head->next;temPtr!=NULL;temPtr=temPtr->next) {
        cout<<temPtr->data<<" ";
    }cout<<endl;
}

template<class ElemType>
Node<ElemType>* Linklist<ElemType>::GetElemPtr(int position) {
    if (position<1||position>Length()) {
        cout<<"输出的位置不在链表内！"<<endl;
        return nullptr;//position非法时返回一个空指针
    }
    Node<ElemType>* p=head->next;
    for (int i=1;i<position;i++) {
        p=p->next;
    }return p;
}//获取指向指定位置节点的指针

template<class ElemType>
ElemType Linklist<ElemType>::GetElem(int position) {
     if (position<1||position>Length()) {
         cout<<"非法位置"<<endl;
         return ElemType();
     }
    temPtr=GetElemPtr(position);
    return temPtr->data;
}//获取指定位置的数据

template<class ElemType>
bool Linklist<ElemType>::SetElem(int position, const ElemType data) {
    if (position>=1&&position<=Length()) {
        temPtr=GetElemPtr(position);
        temPtr->data=data;
        return true;
    }else return false;
}//修改指定位置的data

template<class ElemType>
bool Linklist<ElemType>::Delete(int position) {
    if (position<1||position>Length()) {
        return false;//非法输入
    }
     Node<ElemType>* prev;
    if (position==1) {
        prev=head;
    }else {
        prev=GetElemPtr(position-1);
    }
    Node<ElemType>* toDelete=prev->next;
    prev->next=prev->next->next;
    delete toDelete;
    count--;
    return true;
}//删除指定位置的节点，释放其指针；

template<class ElemType>
bool Linklist<ElemType>::Insert(int position,const ElemType e) {
    if (position<1||position>Length()+1) {
        return false;
    }
    temPtr=(position==1)?head:GetElemPtr(position-1);
    Node<ElemType>* newPtr=new Node<ElemType>(temPtr->next,e);
    temPtr->next=newPtr;
    return true;
}//在第position个位置插入一个节点

template<class ElemType>
void Linklist<ElemType>::Clear() {
    Node<ElemType>* currPtr = head->next;
    while (currPtr != nullptr) {
        Node<ElemType>* nextPtr = currPtr->next;  // 保存下一个节点
        delete currPtr;  // 释放当前节点
        currPtr = nextPtr;
    }
    head->next = nullptr;  // 头节点next置空
    count = 0;  // 长度归零
}

#endif //LIST_H