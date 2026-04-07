//
// Created by ASUS on 2025/10/30.
//

#ifndef NOD_H
#define NOD_H
using namespace std;

template <class ElemType>
class LinkStack;//声明有一个LIKNstack模板类

template <class ElemType>
class Node
{
    friend class LinkStack<ElemType>;
protected:
    Node<ElemType> *next;
    ElemType data;

public:
    Node();                                        // 默认构造函数
    Node(const ElemType &e, Node<ElemType> *next); // 有参构造函数
    virtual ~Node();                               // 析构函数
};

template <class ElemType>
Node<ElemType>::Node()
{
    next = NULL;
}

template <class ElemType>
Node<ElemType>::Node(const ElemType &e, Node<ElemType> *next)
{
    data = e;
    this->next = next;
}

template <class ElemType>
Node<ElemType>::~Node() = default;
#endif //NOD_H
