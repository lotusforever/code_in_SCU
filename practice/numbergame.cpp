#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    
    int survivor = 0;
    for (int i = 2; i <= n; i++)
    {
        survivor = (survivor + m) % i;
    }
    cout << survivor + 1 << endl;

    return 0;
}