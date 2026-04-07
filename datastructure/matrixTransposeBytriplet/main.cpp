#include <iostream>
#include <vector>
using namespace std;

struct Triplet {
    int row;
    int col;
    int value;
    Triplet(int row, int col, int value) {
        this->row = row;
        this->col = col;
        this->value = value;
    }
};

class SparseMatrix{
private:
    int row;
    int col;
    int count;
    vector<Triplet> triplet;
public:
    SparseMatrix(int row, int col) {
        this->row = row;
        this->col = col;
        this->count = 0;
    }

    void addValue(int row,int col,int value) {
        if (row<=0||col<=0||row>this->row||col>this->col) {
            throw out_of_range("稀疏矩阵下表越界");
        }
        if (value==0) {
            return;//值为0相当于没有压入新的元素
        }
        triplet.push_back(Triplet(row,col,value));
        count++;
    }

    void Tranpose() {
        for (vector<Triplet>::iterator it=triplet.begin();it!=triplet.end();it++) {
            int temp=it->row;
            it->row=it->col;
            it->col=temp;//交换行和列，达到转置的效果
        }
        int temp=row;
        row=col;
        col=temp;//交换行数和列数
    }

    void display() {
        cout<<"the SparseMatrix is:"<<endl;
        for (auto it=triplet.begin();it!=triplet.end();it++) {
            cout<<"("<<it->row<<","<<it->col<<","<<it->value<<")"<<" "<<endl;
        }
    }
};

int main() {
    SparseMatrix matrix(6,5);
    //matrix.addValue(8,8,8);测试代码，越界后能成功报错
    matrix.addValue(1,1,3);
    matrix.addValue(2,4,6);
    matrix.addValue(5,5,7);
    matrix.addValue(3,2,5);

    matrix.addValue(6,4,1);
    matrix.addValue(2,5,8);
    matrix.display();
    matrix.Tranpose();
    cout<<"after tranpose";
    matrix.display();

    system("pause");
    return 0;
}