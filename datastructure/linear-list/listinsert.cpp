#include <iostream>
using namespace std;
#define MAXSIZE 20
typedef struct {
    int data[MAXSIZE];
    int length;
}SqList;//定义一个顺序存储结构
int GetElem(SqList L,int i,int* e) {
    if (L.length==0||i<1||i>L.length) {
        return -1;
    }//要排除线性表长度为零、下标越界的风险
    *e=L.data[i-1];
    return 1;
}//在顺序表L找到第i个元素并返回给指针e。

//在Sqlist的第i个位置插入一个元素；
int ListInsert(SqList& L,int i,int num) {
    int k;
    if (L.length==MAXSIZE)
        return -1;//叔祖已满，无法添加
    if (i<1||i>L.length+1)/*防止在最后一位的后面隔空添加，只能紧挨着尾插*/
    {
        return -1;
    }
    if (i==L.length+1) {
        L.data[i-1]=num;
        L.length++;
    }//尾插
    if (i<=L.length) {
        for (k=L.length-1;k>=i-1;k--) {
            L.data[k+1]=L.data[k];
        }L.data[i-1]=num;
        L.length++;
    }//中间插入
    return 1;
}
int main() {
    SqList L={{1,2,3,4,5,6,7,8,9},9};
    int* e=new int;
    GetElem(L,3,e);
    cout<<*e<<endl;
    ListInsert(L,10,10);
    cout<<L.data[9]<<endl;
    ListInsert(L,3,6);
    cout<<L.data[2]<<endl;
    return 0;
}