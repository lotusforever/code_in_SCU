#include <iostream>
using namespace std;

struct CrossNode {
    int row;
    int col;
    int value;
    CrossNode* right;
    CrossNode* down;
    CrossNode(int r=-1, int c=-1, int v=0):row(r),col(c),value(v),right(nullptr),down(nullptr){}
};

class SparseMatrix {
private:
    int row;
    int col;
    CrossNode** rowHead;//行头指针数组
    CrossNode** colHead;//列头指针数组
public:
    SparseMatrix(int r, int c){
        row = r;
        col = c;
        if (r<=0||c<=0) {
            throw invalid_argument("Invalid matrix size");
        }

        //初始化行链表头节点
        rowHead=new CrossNode*[r+1];
        for (int i=0;i<=r;i++) {
            rowHead[i]=new CrossNode(i,-1,0);//i表示行数，-1表示是行链表的头节点，0为默认值
        }

        //初始化列列表头节点
        colHead=new CrossNode*[c+1];
        for (int i=0;i<=c;i++) {
            colHead[i]=new CrossNode(-1,i,0);//-1表示是列链表的头节点，i表示列数，0为默认值
        }
    }

    void insert(int r,int c,int v) {
        if (r<=0||c<=0) {
            throw out_of_range("矩阵参数越界");
        }

        if (v==0) {
            //相当于要删除该元素；
            remove(r,c);
            return;
        }

        CrossNode* rowPrev=rowHead[r];
        while (rowPrev->right!=nullptr&&rowPrev->right->col<c) {
            rowPrev=rowPrev->right;
        }//在第r行寻找要插入位置（前提是该位置还没有元素，即为0）

        CrossNode* colPrev=colHead[c];
        while (colPrev->down!=nullptr&&colPrev->down->row<r) {
            colPrev=colPrev->down;
        }//在第c列寻找要插入的位置（前提是该位置还没有元素，即为0）

        if (rowPrev->right!=nullptr&&rowPrev->right->col==c) {
            rowPrev->right->value=v;
            return;
        }//对于已经存在的元素直接赋值

        CrossNode* newNode=new CrossNode(r,c,v);
        newNode->right=rowPrev->right;
        rowPrev->right=newNode;
        //创建行节点

        newNode->down=colPrev->down;
        colPrev->down=newNode;
        //创建列节点
    }

    void remove(int r,int c) {
        if (r<=0||c<=0) {
            throw invalid_argument("矩阵下标越界");
        }
        CrossNode* rowPrev=rowHead[r];
        while (rowPrev->right!=nullptr&&rowPrev->right->col<c) {
            rowPrev=rowPrev->right;
        }
        if (rowPrev->right==nullptr||rowPrev->right->col!=c) {
            return;
        }

        CrossNode* colPrev=colHead[c];
        while (colPrev->down!=nullptr&&colPrev->down->row<r) {
            colPrev=colPrev->down;
        }

        CrossNode* toRemove=colPrev->down;
        rowPrev->right=toRemove->right;//行删除
        colPrev->down=toRemove->down;//列删除
        delete toRemove;
    }

    int get(int r,int c) {
        if (r<=0||c<=0) {
            throw out_of_range("越界");
        }
        CrossNode* rowPrev=rowHead[r]->right;
        while (rowPrev!=nullptr&&rowPrev->col!=c) {
            rowPrev=rowPrev->right;
        }
        if (rowPrev!=nullptr&&rowPrev->col==c) {
            return rowPrev->value;
        }
        return 0;
    }
    void display() {
        cout<<"稀疏矩阵："<<endl;
        for (int i=1;i<=row;i++) {
            for (int j=1;j<=col;j++) {
                cout<<get(i,j)<<" ";
            }cout<<endl;
        }cout<<endl;
    }
};

int main() {
    SparseMatrix a(5,6);
    a.insert(5,1,1);
    a.insert(5,2,2);
    a.insert(1,2,3);
    a.insert(4,3,4);
    a.display();
    a.insert(5,2,0);
    cout<<"在（5，2）插入0后";
    a.display();
    a.remove(5,1);
    cout<<"删除（5，1）后";
    a.display();
    system("pause");

    return 0;
}