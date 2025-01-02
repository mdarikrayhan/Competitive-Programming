// LUOGU_RID: 159162084
/**
 *    author: sunkuangzheng
 *    created: 16.05.2024 11:07:34
**/
#include<bits/stdc++.h>
#ifdef DEBUG_LOCAL
#include <mydebug/debug.h>
#endif
using ll = long long;
const int N = 5e5+5;
using namespace std;
int T,n,a[N];
void los(){
    cin >> n; vector<ll> p(n); ll ans = 0;
    for(int i = 0;i < n;i ++) cin >> a[i]; 
    sort(a+1,a+n); 
    for(int i = n - 1;i >= 1;i --) a[i] -= a[i-1];
    p[0] = -1e18;
    for(int i = 1;i < n;i ++) p[i] = 1ll * i * (n - i);
    for(int i = 1;i < n;i ++) ans += -(p[i] - 1) * (a[i]);
    cout << ans << "\n";
}int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(cin >> T;T --;) los();
}