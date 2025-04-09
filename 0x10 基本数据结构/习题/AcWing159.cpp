#include <iostream>
#include <cstring>
using namespace std;
const int N = 10010, M = 80;
int n, m, nxt[N];
char s[N][M];
bool st[M]; // st[i]=1说明长度为i的循环节可行

int main() {
  cin >> n >> m;
  memset(st, 1, sizeof st);
  for (int i=1; i<=n; i++) { // 判断每个字符串中宽度j的循环节是否可行
    scanf("%s", s[i]);
    for (int j=1; j<=m; j++)
      if (st[j])
        for (int k=j; k<m; k+=j) {
          for (int u=0; u<j && k+u<m; u++)
            if (s[i][u] != s[i][k+u]) {
              st[j] = 0;
              break;
            }
          if (!st[j]) break;
        }
  }
  int width;
  for (int i=1; i<=m; i++)
    if (st[i]) {
      width = i;
      break;
    }
  for (int i=1; i<=n; i++) s[i][width] = 0;
  for (int i=2, j=0; i<=n; i++) { // 对列做kmp算法
    while (j && strcmp(s[i], s[j+1])) j = nxt[j];
    if (!strcmp(s[i], s[j+1])) j++;
    nxt[i] = j;
  }
  int height = n - nxt[n];
  cout << width*height << endl;
  return 0;
}