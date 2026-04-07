//
// Created by ASUS on 2025/11/20.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <stdexcept>
using namespace std;
#include "node.h"   //包含节点模板

template<class ElemType>
class BinaryTree{
    Node<ElemType>*root;
public:
    BinaryTree();//默认构造函数
    virtual~BinaryTree();//析构函数
    bool isEmpty()const;//判断二叉树是否为空；
    bool addElem(ElemType data,Node<ElemType>* leftchild,Node<ElemType>* rightchild,Node<ElemType>*parent,int Tag);
    //节点的值，左右孩子指针，双亲指针表明元素添加到哪里，Tag标注是添加为左孩子还是右孩子
    void Inorder(Node<ElemType>*)const;//中序遍历
    void Preorder(Node<ElemType>*)const;//先序遍历
    void Postorder(Node<ElemType>*)const;//后序遍历
    Node<ElemType>* getRoot()const {
        return root;
    }
};

template<class ElemType>
BinaryTree<ElemType>::BinaryTree() {
    root=new Node<ElemType>(ElemType());//默认构造创建根节点，给定默认初始值，返回node*指针给root
}//创建只含有一个根节点的二叉树

template<class ElemType>
BinaryTree<ElemType>::~BinaryTree() {
      delete root;
}//清空整个二叉树

template<class ElemType>
bool BinaryTree<ElemType>::isEmpty()const {
    return root==nullptr;
}//判断是否是空的二叉树

template<class ElemType>
bool BinaryTree<ElemType>::addElem(ElemType data,Node<ElemType>* leftchild,Node<ElemType>* rightchild,Node<ElemType>*parent,int Tag) {
    if (parent==nullptr) {
        return false;
    }
    if (Tag!=-1&&Tag!=1) {
       return false;
    }
    if (parent->leftchild!=nullptr&&Tag==-1) {
        return false;
    }//添加左孩子，左孩子指针不为空
    if (parent->rightchild!=nullptr&&Tag==1) {
        return false;
    }//添加右孩子，右孩子指针不为空
    if (Tag==-1) {
        parent->leftchild=new Node<ElemType>(data);//默认左右孩子为空指针
        return true;
    }else {
        parent->rightchild=new Node<ElemType>(data);
        return true;
    }
}

template<class ElemType>
void BinaryTree<ElemType>::Inorder(Node<ElemType>* root) const{
     if (root==nullptr) {
         return;
     }
    Inorder(root->leftchild);
    cout<<root->data<<" ";
    Inorder(root->rightchild);
}//中序遍历

template<class ElemType>
void BinaryTree<ElemType>::Preorder(Node<ElemType>* root) const{
     if (root==nullptr) {
         return;
     }
    cout<<root->data<<" ";
    Preorder(root->leftchild);
    Preorder(root->rightchild);
}//先序遍历

template<class ElemType>
void BinaryTree<ElemType>::Postorder(Node<ElemType>* root) const{
     if (root==nullptr) {
         return;
     }
    Postorder(root->leftchild);
    Postorder(root->rightchild);
    cout<<root->data<<" ";
}//后序遍历


#endif //BINARYTREE_H
