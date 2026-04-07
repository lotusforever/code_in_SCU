//顺序表模板化实现方法及其示例
#include <algorithm>
#include <iostream>
using namespace std;
template <class ElemType>
class SqList {
public:
    int maxsize;//声明顺序表的最大容量
    int count;//声明顺序表中的元素个数
    ElemType* elems;
public:
    SqList(int size);
    ~SqList();
    int Length() const;//求线性表的长度（不是容量）
    bool isEmpty() const;//判断是否是空的顺序表
    void Clear();//将线性表清空
    void Traverse(void(*visit)(const ElemType&)) const;//遍历顺序表
    void Traverse(ElemType *elems) const;
    bool GetElem(int position,ElemType&e) const;//返回指定位置的元素到e中
    bool SetElem(int position,ElemType&e);//设置指定位置的元素的值
    bool DeleteElem(int position);//删除元素
    bool DeleteElem(int position,ElemType&e);//删除元素
    bool Insert(int position,const ElemType&e);//向指定位置插入元素
    SqList(const SqList<ElemType>&source);//复制构造函数
    SqList<ElemType>& operator=(const SqList<ElemType>& source);//重载运算符
};
template<class ElemType>
SqList<ElemType>::SqList(int size) {
 //对顺序表进行初始化，声明长度、元素个数
    maxsize=size;
    count=0;
    elems=new ElemType[maxsize];
}
template<class ElemType>
SqList<ElemType>::~SqList() {
    delete []elems;//释放存储空间
}
template<class ElemType>
int SqList<ElemType>::Length()const {
    return count;
}
template<class ElemType>
bool SqList<ElemType>::isEmpty() const {
    if (count==0)
        return true;
    else
        return false;
}//判断顺序表是否为空
template<class ElemType>
void SqList<ElemType>::Clear() {
    count=0;
}//清空顺序表：将顺序表长度赋值为0
template<class ElemType>
void SqList<ElemType>::Traverse(ElemType *elems) const {
    for (int i=0;i<count;i++) {
        cout<<elems[i]<<" ";
    }cout<<endl;
}//通过指针遍历输出顺序表的每一个元素

template<class ElemType>
bool SqList<ElemType>::GetElem(int position, ElemType &e) const {
    if (position<1 && position>count) {
        return false;
    }
    e=elems[position-1];
    return true;
}//获取指定位置的值，返回到e中

template<class ElemType>
bool SqList<ElemType>::SetElem(int position,ElemType &e) {
    if (position>0&&position<=count) {
        elems[position-1]=e;
        return true;
    }else{return false;};
}//更改指定位置的值

template<class ElemType>
bool SqList<ElemType>::DeleteElem(int position) {
    if (position<0||position>count) {
        return false;
    }
    for (int i=position;i<count-1;i++) {
        elems[i]=elems[i+1];
    }count--;
    return true;
}
template<class ElemType>
bool SqList<ElemType>::DeleteElem(int position,ElemType&e) {
    if (position<0||position>count) {
        return false;
    }
    e=elems[position-1];
    for (int i=position;i<count-1;i++) {
        elems[i-1]=elems[i];
    }count--;
    cout<<"成功删除"<<e<<endl;
    return true;
}//删除指定元素，用e保存被删除元素
template<class ElemType>
bool SqList<ElemType>::Insert(int position,const ElemType&e) {
    if (position<0||position>count+1) {
        return false;
    }
    if (++count>maxsize) {
        return false;
    }
    for (int i=position;i<count-1;i++) {
         elems[i]=elems[i-1];
    }elems[position-1]=e;
    count++;
    return true;
}//向指定位置插入元素
//SqList<ElemType>::
//SqList<ElemType>::
int main()
{
    SqList<int> L(20);
    L.Insert(1,1);L.Insert(2,2);L.Insert(3,3);L.Insert(4,3);L.Insert(5,5);L.Insert(6,6);L.Insert(7,7);L.Insert(8,8);L.Insert(9,9);L.Insert(10,10);
    //尾插10个元素进去，依次为1，2，3，3，5，6，7，8，9，10
    L.Traverse(L.elems);
    int val=4;
    L.SetElem(4,val);
    L.Traverse(L.elems);
    int e;
    L.GetElem(4,e);
    cout<<L.isEmpty()<<endl;
    cout<<L.Length()<<endl;
    L.~SqList();
    return 0;
}