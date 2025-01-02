#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[610], b[610], N, i, cnt, ans, ans2, j, x;
char c[310];
int chu(int a[]) {
  int x = 0, i;
  for (i = a[0]; i >= 1; --i) {
    x = x * 10 + a[i];
    a[i] = x / 12;
    x %= 12;
  }
  while (a[0] > 1 && !a[a[0]]) a[0]--;
  return x;
}
void cheng(int a[]) {
  int i;
  for (i = 1; i <= a[0]; ++i) a[i] *= 12;
  for (i = 1; i <= a[0] || a[i]; ++i) a[i + 1] += a[i] / 10, a[i] %= 10;
  a[0] = i - 1;
}
void add(int a[], int b[]) {
  int i, l = max(a[0], b[0]);
  for (i = 1; i <= l; ++i) a[i] += b[i];
  for (i = 1; i <= l || a[i]; ++i) a[i + 1] += a[i] / 10, a[i] %= 10;
  a[0] = i - 1;
}
void jian(int a[], int b[]) {
  int i;
  for (i = 1; i <= a[0]; ++i) a[i] -= b[i];
  for (i = 1; i <= a[0]; ++i)
    if (a[i] < 0) a[i] += 10, a[i + 1]--;
  while (a[0] > 1 && !a[a[0]]) a[0]--;
}
int main() {
  scanf("%s", c + 1);
  a[0] = strlen(c + 1);
  for (i = 1; i <= a[0]; ++i) a[a[0] - i + 1] = c[i] - 48;
  while (a[0] > 1 || a[1]) {
    b[++N] = chu(a);
    if (b[N] > 2) return puts("NO"), 0;
  }
  for (i = 1; i <= N; ++i) cnt += b[i];
  if (cnt != 2) return puts("NO"), 0;
  for (x = 1; x <= N; ++x)
    if (b[x]) break;
  if (x == N)
    ans = N * 2 - 1;
  else
    ans = (N - x + 1) + (x - 1) * 2;
  ans2 = min((ans + 1) / 2, 1000);
  printf("YES\n1\n%d\n%d\n", ans, ans2 - 1);
  a[0] = a[1] = 1;
  for (i = 1; i <= ans / 2; ++i) cheng(a);
  memcpy(b, a, sizeof(b));
  if (!(ans & 1)) chu(b);
  for (i = 1; i <= ans2; ++i) {
    add(a, b);
    if (x != (ans + 1) / 2 - i + 1) {
      for (j = a[0]; j >= 1; --j) printf("%d", a[j]);
      puts("");
    }
    jian(a, b);
    cheng(a);
    chu(b);
  }
}