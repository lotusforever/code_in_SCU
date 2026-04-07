//
// Created by ASUS on 2025/11/20.
//

#ifndef NODE_H
#define NODE_H
template<class ElemType>
class Node{
public:
    ElemType data;
    //Node<ElemType> *parent;//双亲节点的指针
    Node<ElemType> *leftchild;
    Node<ElemType> *rightchild;

public:
    Node();//默认构造函数,创建一个空节点
    Node(const ElemType&data,Node<ElemType>* leftchild=nullptr,Node<ElemType>* rightchild=nullptr);//有参构造
};

template<class ElemType>
Node<ElemType>::Node() {
    data=ElemType();
    //parent=nullptr;
    leftchild=nullptr;
    rightchild=nullptr;
}//默认构造节点为空
template< class ElemType>
Node<ElemType>::Node(const ElemType&data,Node<ElemType>* leftchild,Node<ElemType>* rightchild)
                    :data(data),leftchild(leftchild),rightchild(rightchild){}//在指定位置创建一个node节点
#endif //NODE_H