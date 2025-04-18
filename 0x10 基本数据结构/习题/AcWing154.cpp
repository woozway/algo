#include <iostream>
using namespace std;
const int N = 1000006;
int n, k, a[N], q[N];

int main() {
  cin >> n >> k;
  for (int i=1; i<=n; i++) cin >> a[i];

  int l = 0, r = -1; // l<=r表示队列q中有元素
  for (int i=1; i<=n; i++) {
    while (l<=r && q[l]<=i-k) l++;
    while (l<=r && a[q[r]]>=a[i]) r--;
    q[++r] = i; // 入队后，这里q是单调队列
    // 注意这里是入队之后找最小/大值，因为入队前后q[l]可能会变，区别于AcWing135
    if (i >= k) printf("%d ", a[q[l]]);
  }
  puts("");
  
  l = 0, r = -1; // 和队中求minn对称的方式求maxn
  for (int i=1; i<=n; i++) {
    while (l<=r && q[l]<=i-k) l++;
    while (l<=r && a[q[r]]<=a[i]) r--;
    q[++r] = i;
    if (i >= k) printf("%d ", a[q[l]]);
  }
  return 0;
}