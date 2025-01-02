#include <bits/stdc++.h>
 
#define scan(a, __n) for(int __ = 0; __ < __n; __++)cin >> a[__];
// #define print(a, __n) for(int ___ = 0; ___ < __n; ___++)cout << a[___] << ' '; cout << '\n';
 #define int ll

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

// #define fr first
// #define sc second
 
#define all(v) v.begin(), v.end()
 
// #define c0 (v<<1)
// #define c1 (c0|1)
// #define md ((l+r)/2)
 
typedef long long ll;
typedef double ld;


using namespace std;

const ll mod = 1e9+7;
const int maxN = 2e5+70;

// const int maxFac = maxN; 
// ll fac[maxFac], _fac[maxFac];

// ll po(ll b, ll p){
//     b %= mod;
//     p %= mod-1;
//     ll r = 1;
//     while(p){
//         if(p&1)r = r*b%mod;
//         p >>= 1;
//         b = b*b%mod;
//     }
//     return r;
// }

// ll choose(ll k, ll n){
//     return fac[n]*_fac[k]%mod*_fac[n-k]%mod;
// }

// ll factorial(ll n, ll k){
//     ll ret = 1;
//     for(ll i = n; i >= n-k+1; i--){
//         ret = ret*i%mod;
//     }
//     return ret;
// }

vector<int> g[maxN];
int a[maxN];

int sz[maxN]; // all vertices below
int dp[maxN]; // answer below

int n, k;
int ans = 0;


void dfs(int nw, int pr, int x){

    sz[nw] = 1;
    dp[nw] = 1;
    int mx = 0, mx2 = 0;

    for(auto u : g[nw]){
        if(u != pr){
            dfs(u, nw, x);
            if(sz[u] == dp[u]){
                dp[nw] += dp[u];
            }
            else{
                mx2 = max(mx2, dp[u]);
                if(mx < mx2){
                    swap(mx, mx2);
                }
            }

            sz[nw] += sz[u];
        }
    }

    if(a[nw] < x){
        dp[nw] = 0;
        return;
    }

    dp[nw] += mx;
    ans = max(ans, dp[nw]+mx2);
}


void slv(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int lo = 0, hi = 1e9+10, md;
    int r = min_element(a , a + n) - a ;

    while(lo + 1 < hi){
        md = (lo+hi)/2;
        ans = 0;
        dfs(r, -1, md);
        if(ans >= k)lo = md;
        else hi = md;
    }

    cout << lo << endl;

    // ans = 0;
    // dfs(0, 0, 10);
    // for(int i = 0; i < n; i++){
        // cout << dp[i] << ' ' << maxi[i] << ' ' << maxi2[i] << ' ' << sz[i] << ' ' << good[i] << ' ' << a[i] << ' ' << (a[i] >= 10) << endl;
    // }
}

signed main(){

    fastIO;
    // cout << fixed << setprecision(15);

    // fac[0] = 1;
    // for(int i = 1; i < maxFac; i++)fac[i] = fac[i-1]*i%mod;
    // _fac[maxFac-1] = po(fac[maxFac-1], mod-2);
    // for(int i = maxFac-2; i >= 0; i--)_fac[i] = _fac[i+1]*(i+1)%mod;
    
    
    int t = 1;
    // cin >> t;
    while(t--){
        // cout << "**S" << endl;

        // cout << slv() << '\n';
        slv();
        // string s;
        // cin >> s;
        // ll x = slv();
        // cout << (x == -1?"use the stairs":to_string(x)) << '\n';
    }
}       
/*
0    2
1    1
2    6
3    1
4    1
5    2
6    5
7    2
8    2
9    3

5   8   2   9
2   2   6   3 | 30
*/