// LUOGU_RID: 160309623
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

struct ANS{
  LL a;
  char b;
  LL c;
};
vector<ANS> ans;

LL Getl(LL x){
  int ret = 0;
  while(x > 0) x /= 2, ret++;
  return ret;
}
void Out(LL x, int k){
  while(k--){
    ans.push_back({x, '+', x});
    x *= 2;
  }
}

LL x;

int main(){
  cin >> x;
  while(x > 1){
    LL a = x;
    LL b = (x << (Getl(x) - 1)); Out(x, Getl(x) - 1);
    LL _b = b + b; ans.push_back({b, '+', b});
    LL c = a ^ b; ans.push_back({a, '^', b});
    LL d = b + c; ans.push_back({b, '+', c});
    LL e = d ^ _b; ans.push_back({d, '^', _b});
    LL f = e ^ a; ans.push_back({e, '^', a});
    while(f < b){
      if((b & f) > 0){
        ans.push_back({b, '^', f});
        b ^= f;
      }
      ans.push_back({f, '+', f});
      f *= 2;
    }
    ans.push_back({x, '^', b});
    x ^= b;
  }
  cout << ans.size() << "\n";
  for(ANS i : ans) cout << i.a << " " << i.b << " " << i.c << "\n";
  return 0;
}
// 1001