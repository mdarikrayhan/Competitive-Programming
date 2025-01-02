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

const ll mod = 998244353;
const int maxA = 1005;

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

int n;
string s, t[maxA];
int sz[maxA];
int canZero[maxA];

int c[10];

vector<int> ord[maxA+1];

int dp[maxA][maxA];


void slv(){
    cin >> s >> n;
    int szs = s.size();

    reverse(all(s));
    while(s.size() < maxA)s.push_back('0');
    for(auto& u : s){
        if(u == '?') u = 10;
        else u -= '0';
    }
    

    for(int i = 0; i < n; i++){
        cin >> t[i];
        reverse(all(t[i]));
        sz[i] = t[i].size();
        while(t[i].size() < maxA)t[i].push_back('0');
        for(auto& u : t[i])u -= '0';
    }
    for(int i = 0; i < 10; i++)cin >> c[i];

    for(int i = 0; i < n; i++)ord[0].push_back(i);
    for(int i = 0; i < maxA; i++){
        vector<int> dig[11];
        for(auto u : ord[i]){
            dig[t[u][i]].push_back(u);
        }
        
        for(int j = 0; j < 10; j++){
            for(auto u : dig[j])ord[i+1].push_back(u);
        }
    }

    for(int ii = 0; ii <= 3; ii++){
        // for(auto u : ord[ii])cout << u+1 << ' ';
        // cout << '\n';
    }
    memset(dp, 0, sizeof dp);
    for(int j = 0; j <= n; j++)dp[maxA-1][j] = j*c[1];
    for(int i = maxA-2; i >= 0; i--){
        for(int d = 0; d < 10; d++){
            if(d != s[i] && s[i] != 10)continue;
            if(d == 0 && i == szs-1)continue;
            if(i == 1){
                // cout << d << ":";
            }
            int cnt = 0;
            int v = 0;
            for(int j = 0; j < n; j++){
                cnt += (t[j][i]+d) >= 10;
                if(i < szs || i < sz[j]){
                    v += c[(t[j][i]+d)%10];
                }
            }
            dp[i][0] = max(dp[i][0], dp[i+1][cnt]+v);
            // if(i == 1)cout << dp[i+1][cnt]+v << ' ';
            for(int ind = n-1; ind >= 0; ind--){
                int j = ord[i][ind];
                
                cnt -= (t[j][i]+d) >= 10;
                if(i < sz[j] || i < szs){
                    v -= c[(t[j][i]+d)%10];
                }
                
                cnt += (t[j][i]+d+1) >= 10;
                v += c[(t[j][i]+d+1)%10];

                dp[i][n-ind] = max(dp[i][n-ind], dp[i+1][cnt]+v);
                // if(i == 1 && j == 1)cout << dp[i+1][cnt]+v << ":" << cnt << " | " << v << endl;;
                // if(i == 1)cout << dp[i+1][cnt]+v << ' ';
            }
            // if(i == 1)cout << endl;
        }
    }
    
    // for(int i = 0; i < n; i++){
    //     for(auto& u : t[i])u += '0';
    //     cout << t[i].substr(0, 6) << endl;
    // }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= 5; j++){
    //         cout << dp[j][i] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[0][0] << endl;
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