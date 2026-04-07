#include <iostream>
#include "node.h"
#include "binaryTree.h"
using namespace std;

int main() {
    BinaryTree<int> BT;
    Node<int>* parent=BT.getRoot();
    BT.addElem(5,nullptr,nullptr,parent,-1);//根节点左孩子5
    BT.addElem(3,nullptr,nullptr,parent,1);//根节点右孩子3
    BT.addElem(7,nullptr,nullptr,parent->leftchild,1);//左孩子的右孩子7
    BT.addElem(9,nullptr,nullptr,parent->rightchild,-1);//右孩子的左孩子9
    BT.addElem(8,nullptr,nullptr,parent->rightchild->leftchild,-1);//右孩子的左孩子的左孩子8
    BT.addElem(3,nullptr,nullptr,parent->rightchild->rightchild,1);//右孩子的左孩子的右孩子3
/*
         0
        / \
       /   \
      /     \
     /       \
    5         3
     \       /
      7     9
           / \
          8   3
*/


    cout<<"二叉树在main.cpp注释中已画出，可参考"<<endl;
    cout<<"中序遍历：";
    BT.Inorder(parent);
    cout<<endl;
    cout<<"先序遍历：";
    BT.Preorder(parent);
    cout<<endl;
    cout<<"后序遍历：";
    BT.Postorder(parent);
    cout<<endl;

    system("pause");
    return 0;
}