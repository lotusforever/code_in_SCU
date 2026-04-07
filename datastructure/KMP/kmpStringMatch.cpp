#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int* getNextarray(string s){
    int m = s.length();
    int *next = new int[m];
    if(m==1){
       next[0] = -1;
       return next;
    }
    next[0] = -1;
    next[1] = 0;
    int i = 2, cn = 0;
    while(i<m){
        if(s[i-1]==s[cn]){
            next[i++] = ++cn;
        }else if(cn>0){
            cn = next[cn];
        }else{
            next[i++] = 0;
        }
    }
    return next;
}

int kmp(string s1, string s2,int* next)
{
    int m = s1.length(), n = s2.length(), x = 0, y = 0;
    //next = new int[m];
    while (x < m && y < n)
    {
        if (s1[x] == s2[y])
        {
            x++;
            y++;
        }
        else if (y == 0)
        {
            x++;
        }
        else
        {
            y = next[y];
        }
    }
    return y == n ? x - y : -1;
}

int main()
{
    string s1 = "sadghjksadgjdg";
    string s2 = "sadgj";
    int *next = getNextarray(s2);
    int status=kmp(s1, s2, next);
    cout <<status<< endl;
    return 0;
}