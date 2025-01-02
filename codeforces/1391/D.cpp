#include<bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
#include "sys/debug.h"
#define TestCase(t) cerr<<"Test #"<<t<<nl, solve();
#else
#define debug(x);
#define TestCase(t) solve();
#endif

#define ll long long
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>>
#define lp1(i,n) for(ll i =0; i<n; i++)
#define lp2(i,s,e) for(ll i = s; i<e; i++)
#define inp_vec(v, n) vector<ll> v(n); for(auto &i : v) cin>>i;
#define yy cout<<"YES"<<nl;
#define nn cout<<"NO"<<nl;
#define all(x) x.begin(), x.end()
#define nl '\n'

int mat[1000005][3];
int dp[1000005][1<<3];

void solve() {
    ll n, m; cin>>n>>m;
    if(n == 1 || n >= 4) {
        string x;
        lp1(i, n) cin>>x;                       // just reading the inputs
        cout<< (n == 1 ? 0 : -1) <<nl; 
        return;
    }

    string s;
    lp1(i, n) {
        cin>>s;
        lp1(j, m) {
            mat[j][i] = s[j] - '0';
        }
    }

    for(int i = 1; i<=m; i++) {
        for(int j = 0; j < (1<<n); j++) {
            dp[i][j] = 1e9;
        }
    }

    auto bit = [&] (int x, int y) {
        return ((x>>y) & 1);
    };

    for(int i = 0; i<m; i++) {      // current column
        ll mask = 0;
        for(int c = 0; c < n; c++) mask += mat[i][c] << c;      // mask of current column entries

        for(int j = 0; j < (1<<n); j++) {       // previous column mask
            for(int k = 0; k < (1<<n); k++) {           // let's current column mask be changed to k
                int cost = __builtin_popcount(mask ^ k);
                int val = dp[i][j] + cost;

                // check if changed current column mask is valid
                bool pos = 1;
                for(int p = 0; p+1 < n; p++) {
                    int cnt = bit(j, p) + bit(j, p+1) + bit(k, p) + bit(k, p+1);
                    if((cnt & 1) == 0) {
                        pos = 0;
                        break;
                    }
                }

                if(pos) dp[i+1][k] = min(dp[i+1][k], val);
            }
        }
    }

    int ans = 1e9;
    for(int i = 0; i < (1<<n); i++) {
        ans = min(ans, dp[m][i]);
    }

    cout<<ans<<nl;
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
freopen("fileIO/in.txt", "r", stdin);
freopen("fileIO/out.txt", "w", stdout);
freopen("fileIO/error.txt", "w", stderr);
#else
#endif

    int t = 1;
    // cin>>t;
    for(int i=1; i<=t;i++) TestCase(i)

cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nl;
return 0;
}