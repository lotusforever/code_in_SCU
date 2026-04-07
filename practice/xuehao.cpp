#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int todec(string num,int base){
    int result=0;
    int count = 0;
    for (auto it = num.begin(); it != num.end();it++){
        result += (*it) * pow(base, count++);
    }
    return result;
}

string togoal(int dec,int base){
    if(dec==0)
        return "0";

    string result = "";
    while (dec > 0)
    {
        int digit = dec % base;
        char c;
        if (digit < 10)
        {
            c = '0' + digit;
        }
        else
        {
            c = 'A' + (digit - 10);
        }
        result = c + result;
        dec /= base;
    }
    return result;
}

int main(){
    int k, q;
    string x, m;
    cin >> k;
    cin >> x;
    cin >> q;
    //int A = 0, B = 11, C = 12, D = 13, E = 14, F = 15;
    int dec = todec(x, k);
    m = togoal(dec, q);
    cout << m;

    return 0;
}