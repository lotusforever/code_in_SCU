//
// Created by ASUS on 2025/10/23.
//

#ifndef NODE_H
#define NODE_H
#include <iterator>
#include <bits/ranges_base.h>

template<class ElemType>
class Node{
public:
    ElemType coef;
    ElemType expon;
    Node<ElemType> *next;
public:
    Node();//默认构造函数,创建一个空节点
    Node(Node<ElemType>* next,const ElemType& coef,const ElemType& expon);//有参构造
};

template<class ElemType>
Node<ElemType>::Node() {
    next=NULL;
}//默认构造的节点为空
template<class ElemType>
Node<ElemType>::Node(Node<ElemType> *next,const ElemType& coef,const ElemType& expon) {
    this->next=next;
    this->coef=coef;
    this->expon=expon;
}//在指定位置创建一个node节点
#endif //NODE_H
