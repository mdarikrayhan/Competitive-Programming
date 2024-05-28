#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define X first
#define Y second

ll modpow(ll base,ll exp , ll mod){
    base%=mod;
    ll res = 1;
    while(exp){
        if(exp&1)res = res*base%mod;
        base = base*base%mod, exp>>=1;
    }
    return res;
}

const int N = 3600 + 5, MOD = 998244353;
int n,m,k;
int grid[2][N];
ll dp[2][N][N];
ll fac[N],inv[N];

ll calc(int i,int j,int rem){
    if(i==0 and j>n) return rem==0;
    if(i==1 and j>m) return rem==0;
    ll &ret = dp[i][j][rem];
    if(~ret) return ret;
    ret = calc(i,j+1,rem);
    if((grid[i][j]==0) and (grid[i][j+1]==0)){
        ret += calc(i,j+2,rem-1);
        ret %= MOD;
    }
    return ret;
}

ll nCr(int n,int r){
    if(r>n) return 0;
    return fac[n]*inv[r]%MOD*inv[n-r]%MOD;
}

void solve(){
    int a = 0 , b = 0;
    cin>>n>>m>>k;
    grid[0][n+1] = grid[1][m+1] = 1;
    for(int i=1;i<=k;++i){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        grid[0][r1] = grid[0][r2] = 1;
        grid[1][c1] = grid[1][c2] = 1;
    }
    for(int i=1;i<=n;++i) a+=grid[0][i];
    for(int i=1;i<=m;++i) b+=grid[1][i];
    a = n-a, b = m-b;
    ll ret = 0,sub1,sub2;
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<n;++i){
        for(int j=0;j<m;++j){
            sub1 = calc(0,1,i) * nCr(b-2*j,i) % MOD;
            sub1 = sub1 * fac[i] % MOD;
            sub2 = calc(1,1,j) * nCr(a-2*i,j) % MOD;
            sub2 = sub2 * fac[j] % MOD;
            // cout << i << ' ' << j << '\n';
            // cout << calc(0,1,i) << ' ' << nCr(b-2*j,i) << '\n';
            // cout << calc(1,1,j) << ' ' << nCr(a-2*i,j) << '\n';
            // cout << "-------------------\n";
            sub1 = sub1 * sub2 % MOD;
            ret = (ret + sub1) % MOD;
        }
    }
    cout << ret << '\n';
}

int main()
{
ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    fac[0] = 1;
    for(int i=1;i<N;++i) fac[i] = fac[i-1]*i%MOD;
    for(int i=0;i<N;++i) inv[i] = modpow(fac[i],MOD-2,MOD);
    int tc = 1;
    // cin>>tc;
    for(int i=1;i<=tc;++i){
        solve();
    }
}