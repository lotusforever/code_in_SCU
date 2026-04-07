//
// Created by ASUS on 2025/10/16.
//

#ifndef NODE_H
#define NODE_H
template<class ElemType>
class Node{
public:
    ElemType data;
    Node<ElemType> *next;
public:
    Node();//默认构造函数,创建一个空节点
    Node(Node<ElemType>* next=nullptr,ElemType data);//有参构造
};

template<class ElemType>
Node<ElemType>::Node() {
    next=NULL;
}//默认构造的节点为空
template< class ElemType>
Node<ElemType>::Node(Node<ElemType> *next,const ElemType data) {
    this->next=next;
    this->data=data;
}//在指定位置创建一个node节点

#endif //NODE_H
