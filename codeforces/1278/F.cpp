// LUOGU_RID: 160422964
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) (int)(a).size()
#define pb push_back
#define mk make_pair
#define fir first
#define sec second

using namespace std;
const int N = 5e3 + 5;
const ll M = 998244353;
ll ksm(ll aa, ll bb){
    ll as = 1;
    while(bb) {
        if(bb & 1) as =as * aa %M;
        aa = aa * aa %M; bb >>= 1;
    }
    return as;
}
int n, m, k;
ll f[N], ny[N];
ll ans;
ll C(ll nn, int yy){
    if(nn < yy) return 0;
    ll as = 1;
    L(i, 1, yy){
        as = as * (nn - i + 1) %M;
        as = as * ny[i] %M;
    }
    return as;
}
ll jx[N], nz[N];
ll cc(int nn, int mm){
    if(nn < mm) return 0;
    return (jx[nn] * nz[mm]%M) * nz[nn - mm] %M;
}
int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0); 
    cin >> n >> m >> k;
    jx[0] = 1, nz[0] = 1;
    L(i, 1, k){
        jx[i] = jx[i - 1] * i%M;
        nz[i] = ksm(jx[i], M - 2);
        ny[i] = ksm(i, M - 2);
        f[i] = ksm(i, k);
    }
    L(i, 1, k){
        L(j, 1, i - 1){
            f[i] -= f[j] * cc(i, j);
            f[i] %= M;
        }
    }
    ll ans = 0;
    R(i, k, 1){
        f[i] = (f[i] %M + M) %M;
        f[i] = f[i] * C(n, i) %M;;
        f[i] *= ksm(ksm(m, M - 2), i); f[i] %= M;
        ans += f[i];
        ans %= M;
    }
    cout << ans;
    return 0;
}