#include <iostream>
using namespace std;

const int table_size=16;
const int divisor=13;
bool found = false;

int harshTable[table_size];//构建16位哈希表

int harsh(int key) {
    return key%divisor;
}//哈希函数，除留余数法

void insert(int key) {
    int index=harsh(key);//计算初始地址
    int i=0;
    while (harshTable[(index+i)%table_size]!=-1) {
        i++;
    }//线性探测再散列；
    harshTable[(index+i)%table_size]=key;
}

int search(int key) {
    int index=harsh(key);
    int i=0;
    while (harshTable[(index+i)%table_size]!=-1) {
        if (harshTable[(index+i)%table_size]==key) {
            return i+1;//比较成功，返回查找次数
            found=true;
        }
        i++;
        if (i>=table_size) {
            break;
        }
    }return i+1;//比较失败，返回比较次数
}

void printHash() {
    cout<<"哈希表存储状态('^'代表该位置没有存入关键值)：";
    for (int i=0;i<table_size;i++) {
        if (harshTable[i]==-1) {
            cout<<"^"<<" ";
        }
        else {
            cout<<harshTable[i]<<" ";
        }
    }
    cout<<endl;
}

int main() {
    for (int i=0;i<table_size;i++) {
        harshTable[i]=-1;//-1表示该位置还没有填入key
    }

    int elem[]={19,14,23,1,68,20,84,27,55,11,10,79};
    int n=sizeof(elem)/sizeof(elem[0]);

    for (int i=0;i<n;i++) {
        insert(elem[i]);
    }

    printHash();//输出初始哈希表存储结构

    int goal;
    cout<<"请输入要查找的关键值:";
    cin>>goal;

    int count=search(goal);

    if (found) {
        cout<<"查找成功，比较次数："<<count<<endl;
    }else {
        cout<<"查找失败，比较次数："<<count<<endl;
    }

    system("pause");
    return 0;
}