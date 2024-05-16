#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef pair<int, int> pii;

const int inf = 1000000007;
const int maxn = 1100010; // 1.1e6

inline int read(){
  int x=0,f=0; char ch=getchar();
  while(!isdigit(ch)) f|=(ch==45),ch=getchar();
  while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
  return f?-x:x;
}

void once() {
  int n = read(), x = read();
  static int a[maxn];
  int A = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  sort(a+1, a+1+n);
  for (int i = 1; i <= n; ++i) {
    if (A + a[i] == x) {
      swap(a[i], a[n]);
    }
    A += a[i];
  }
  if (A == x) {
    puts("NO");
  } else {
    puts("YES");
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    puts("");
  }
}

int main() {
  int tes = 1;
  tes = read();
  while (tes--) {
    once();
  }
  return 0;
}
