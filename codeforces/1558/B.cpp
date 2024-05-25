// LUOGU_RID: 159852333
/**
 *    author: sunkuangzheng
 *    created: 22.05.2024 15:14:02
**/
#include<bits/stdc++.h>
#ifdef DEBUG_LOCAL
#include <mydebug/debug.h>
#endif
using ll = long long;
const int N = 4e6+5;
using namespace std;
int T,n,mod,g[N],f[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> mod; int sm = 0;
    for(int i = 1;i <= n;i ++){
        g[i] = (g[i - 1] + g[i]) % mod,f[i] = (sm + g[i] + (i == 1)) % mod,
        sm = (sm + f[i]) % mod;
        for(int j = 1;j <= n / i;j ++){
            int l = max(i + 1,j * i),r = min(n,(i + 1) * j - 1); 
            g[l] = (g[l] + f[i]) % mod,g[r + 1] = (g[r + 1] - f[i] + mod) % mod;
        }
    }cout << f[n];
}
