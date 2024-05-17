/**
 * @author      : Davi Guimarães
 * @problem     : 1539D
 * @created     : 16/05/2024
 */

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define f first
#define s second

const int N = 100000;
int n;
pair<long long, long long> a[N];

int solve(long long x){
  pair<long long, long long> b[n];
  for(int i = 0; i < n; i++){
    b[i] = a[i];
  }
  long long cnt = 0;
  for(int i = n - 1; i >= 0; i--){
    long long o = min(x, b[i].f);
    x -= o;
    b[i].f -= o;
    cnt += o;
  }
  for(int i = 0; i < n; i++){
    if(b[i].f == 0) continue;
    if(cnt < b[i].s) return 0;
    cnt += b[i].f;
    b[i].f = 0;
  }
  return 1;
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  int idx[n];
  long long total = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i].f >> a[i].s;
    total += a[i].f;
  }
  sort(a, a+n, [&](auto x, auto y){
    return x.s < y.s;
  });
  long long l = 1, r = total, ans = r * 2;
  while(l <= r){
    long long m = l + r >> 1;
    if(solve(m)){
      long long cost = m * 2 + (total - m);
      assert(cost <= ans);
      ans = cost;
      r = m - 1;
    }
    else{
      l = m + 1;
    }
  }
  cout << ans << endl;
  return 0;
}

