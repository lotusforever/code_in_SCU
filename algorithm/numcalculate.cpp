#include <iostream>
using namespace std;

int num(int count) {
  int res = 0;
  if (count == 1) return 1;
  if (count >= 2) {
    for (int i = 1; i <= count / 2; i++) {
      res += num(i);
    }
    res++;
    return res;
  }
  return 0;
}

int main() {
  int a;
  cin >> a;
  cout << num(a) << endl;

  return 0;
}
