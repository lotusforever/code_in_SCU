//
// Created by ASUS on 2025/10/26.
//

#ifndef NODE_H
#define NODE_H

template<class Elemtype>
class LinkQueue;
template <class ElemType>
class Node {
    friend class LinkQueue<ElemType>;
protected:
    ElemType data;
    Node<ElemType> *next;
public:
    Node();
    Node(const ElemType& data,Node<ElemType>* next);
    virtual ~Node();
};

template<class ElemType>
Node<ElemType>::Node() {
    next=NULL;
}

template<class ElemType>
Node<ElemType>::Node(const ElemType&data,Node<ElemType>* next) {
    this->data = data;
    this->next = next;
}//参数data可以加const表示不会在函数内修改data，Node<ElemType>*next前加const表示指针指向的内容不可改
//Node<ElemType>*       = const Node<ElemType>*;
// 非 const 指针       ←  const 指针

template<class ElemType>
Node<ElemType>::~Node() {
    next = NULL;
}
#endif //NODE_H
