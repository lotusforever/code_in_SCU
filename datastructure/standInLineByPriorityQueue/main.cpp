#include <iostream>
#include "node.h"
#include "priorityQueue.h"
using namespace std;

void printEnum() {
    cout<<"=====欢迎使用医院挂号系统：=============================" << endl;
    cout<<"1.排队---输入病人的病历号，加入病人排队队列中"<<endl;
    cout<<"2.就诊---当前疗程结束，队首的病人就诊"<<endl;
    cout<<"3.查看排队---从队首到队尾列出所有的排队病人的病历号"<<endl;
    cout<<"4.重症患者优先诊疗---输入重症患者的病历号，直接拍到队首优先就诊"<<endl;
    cout<<"5.下班---退出挂号系统"<<endl;
    cout<<"===================================================="<<endl;
    cout<<endl;
    //cout<<"请输入指令：";
}

int main() {
    HospitalRegistration<int> pq;
    printEnum();
    while (true) {
        cout<<"请输入正确指令：";
        int number=0;
        cin>>number;
        int e;
        switch (number) {
            case 1:
                cout<<"请输入病人病历号:";
                cin>>e;
                pq.Register(e);
                cout<<"病人"<<e<<"挂号成功"<<endl;
                cout<<endl;
                break;
            case 2:
                pq.GetHead(e);
                pq.Cure();
                cout<<"病人"<<e<<"成功就诊"<<endl;
                cout<<endl;
                break;
            case 3:
                pq.Display();
                cout<<endl;
                break;
            case 4:
                cout<<"请输入病人病历号:";
                cin>>e;
               // cout<<endl;
                pq.PriorRegister(e);
                cout<<"病人"<<e<<"优先挂号成功，将优先获得治疗"<<endl;
                cout<<endl;
                break;
            case 5:
                cout<<"正在退出挂号系统，谢谢使用！"<<endl;
                return 0;
            default:
                break;
        }
    }
    system("pause");
    return 0;
}