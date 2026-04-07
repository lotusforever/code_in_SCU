//
// Created by ASUS on 2025/11/20.
//
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <stack>
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
    void NonCurInorder(Node<ElemType>*)const;//中序遍历
    void NonCurPreorder(Node<ElemType>*)const;//先序遍历
    void NonCurPostorder(Node<ElemType>*)const;//后序遍历
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
void BinaryTree<ElemType>::NonCurInorder(Node<ElemType>* root) const{
     if (root==nullptr) {
         return;
     }
    stack<Node<ElemType>*> s;
    Node<ElemType>* curr=root;
    while (!s.empty()||curr!=nullptr){
        while (curr!=nullptr) {
            s.push(curr);
            curr=curr->leftchild;//一直向左访问
        }//一直向左访问
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->rightchild;//访问右孩子;
    }

}//中序遍历

template<class ElemType>
void BinaryTree<ElemType>::NonCurPreorder(Node<ElemType>* root) const{
     if (root==nullptr) {
         return;
     }
    stack<Node<ElemType>*> s;
    s.push(root);
    while (!s.empty()) {
        Node<ElemType>* curr=s.top();//获取栈顶元素
        s.pop();
        cout<<curr->data<<" ";
        if (curr->rightchild) {
            s.push(curr->rightchild);
        }
        if (curr->leftchild) {
            s.push(curr->leftchild);
        }//先压入右孩子，再压入左孩子，出栈就是先左后右
    }
}//先序遍历

template<class ElemType>
void BinaryTree<ElemType>::NonCurPostorder(Node<ElemType>* root) const{
     if (root==nullptr) {
         return;
     }

    stack<Node<ElemType>*> s1, s2;
    s1.push(root);

    // 第一遍遍历：根-右-左
    while (!s1.empty()) {
        Node<ElemType>* curr= s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->leftchild) s1.push(curr->leftchild);
        if (curr->rightchild) s1.push(curr->rightchild);
    }

    // 第二遍：反转得到左-右-根
    while (!s2.empty()) {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}//后序遍历


#endif //BINARYTREE_H
