#include <iostream>
#include "node.h"
#include "doubledatalinklist.h"
using namespace std;
void claculate(int coef,int expon) {
   if (coef==0) {
       cout<<"";
   }
   else if (coef!=0&&expon==0) {
        cout<<coef*1;
    }
    else {
        cout<<coef<<"x^"<<expon;
    }
}
int main() {
    //两个操作数中的数据都是按照指数大小降序排列
    Linklist<int> list1;
    list1.Insert(1,3,18);
    list1.Insert(2,-12,9);
    list1.Insert(3,4,2);
    int pos1=1;
    Node<int>* p1=list1.GetElemPtr(pos1);
    Linklist<int> list2;
    cout<<"f(x)=";
    int count1=0;
    while (p1!=NULL) {
        if (count1!=0&&p1->coef>0) {
            cout<<"+";
        }
        claculate(p1->coef,p1->expon);
        count1++;
        p1=p1->next;
    }cout<<endl;
    list2.Insert(1,5,13);
    list2.Insert(2,7,9);
    list2.Insert(3,-3,1);
    list2.Insert(4,1,0);
    int pos2=1;
    Node<int>* p2=list2.GetElemPtr(pos2);
    cout<<"g(x)=";
    int count2=0;
    while (p2!=NULL) {
        if (count2!=0&&p2->coef>0) {
            cout<<"+";
        }
        claculate(p2->coef,p2->expon);
        count2++;
        p2=p2->next;
    }cout<<endl;
    cout<<"f(x)+g(x)=";
    int count=0;
    p1=list1.GetElemPtr(pos1);
    p2=list2.GetElemPtr(pos2);
    while (p1!=NULL&&p2!=NULL) {
        if (p1->expon>p2->expon) {
            if (count!=0&&p1->coef>0) {
                cout<<"+";
            }
            claculate(p1->coef,p1->expon);
            p1=p1->next;
            count++;
        }
        else if (p1->expon<p2->expon){
            if (count!=0&&p2->coef>0) {
                cout<<"+";
            }
            claculate(p2->coef,p2->expon);
            p2=p2->next;
            count++;
        }
        else {
            if (count!=0&&p1->coef+p2->coef>0) {
                cout<<"+";
            }

            claculate(p1->coef+p2->coef,p1->expon);
            p1=p1->next;
            p2=p2->next;
            count++;
        }
    }
    while (p1!=NULL&&p2==NULL) {
       if (count!=0&&p1->coef>0) {
        cout<<"+";
       }
       claculate(p1->coef,p1->expon);
       count++;
       p1=p1->next;
    }
    while (p1==NULL&&p2!=NULL) {
        if (count!=0&&p2->coef>0) {
            cout<<"+";
        }
        claculate(p2->coef,p2->expon);
        count++;
        p2=p2->next;
    }
    cout<<endl;
    return 0;
}