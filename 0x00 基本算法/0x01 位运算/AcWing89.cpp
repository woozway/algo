#include <iostream>
using namespace std;

int power(int a, int b, int p) {
  int ans = 1 % p;
  for (; b; b>>=1) {
    if (b&1) ans = (long long)ans * a % p;
    a = (long long)a * a % p;
  }
  return ans;
}

int main() {
  int a, b, p;
  cin >> a >> b >> p;
  cout << power(a, b, p);
  return 0;
}