// LUOGU_RID: 160134903
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<array>
#define endl '\n'
using namespace std;
using ll = long long;
using pi2 = array<ll,2>;
using pi3 = array<int,2>;
const int N=55;
ll f[N][N][N][2][2][2][2];
const ll inf=1e16;
int n,K;
pi2 rg[N];
ll w[N];
void chkmin(ll& x,ll v){
    x=min(x,v);
}
bool chk(int i,int j,int d){
    ll x = (((d ? rg[j][1] : rg[j][0]) >> i)^1)<<i;
    return x >= rg[j][0] && (x | ((1ll << i) - 1)) <= rg[j][1];
}
ll dp(int i, int l, int r, int bl, int lrev, int br, int rrev) {
    ll& u = f[i][l][r][bl][lrev][br][rrev];
    if (u!=-1) return u;
    if (i == K) return u=(l > r ? 0 : inf);
    u = inf;
    int p = rg[l - 1][bl] >> i & 1 ^ lrev;
    int q = rg[r + 1][br] >> i & 1 ^ rrev;
    chkmin(u, dp(i + 1, l, r, bl, 0, br, 0) + ((1 < l && r < n) * (p ^ q) * w[i]));
    for (int j = l; j <= r; j++) {
        for (int d = 0; d < 2; d++) {
            if (!i) 
                chkmin(u, dp(i, l, j - 1, bl, lrev, d, 0) + dp(i, j + 1, r, d, 0, br, rrev));
            if (chk(i,j,d))
                chkmin(u, dp(i, l, j - 1, bl, lrev, d, 1) + dp(i, j + 1, r, d, 1, br, rrev));
        }
    }
    return u;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(f, -1, sizeof(f));
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        cin >> rg[i][0] >> rg[i][1];
    }
    for (int i = 0; i < K; i++) {
        cin >> w[i];
    }
    cout << dp(0, 1, n, 0, 0, 0, 0) << '\n';
    return 0;
}