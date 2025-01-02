/*###############################################################################################################
##                                    Author : Kim Tae Yoon (Serendipity__)                                    ##
###############################################################################################################*/

#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define prntyes cout<<"Yes\n";
#define prntno cout<<"No\n";
using namespace std;
#ifndef ONLINE_JUDGE
#include "___debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // random int64 generator
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef __int128 ll128;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pii;
typedef complex<double> inum;
// Macros from KACTL pdf
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef vector<double> vd;
const double PI = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LLINF = 1000000000000000000LL;
const ll MAX = 200005; // depending on the problem

void solve() {
    ll N,K,MOD; cin>>N>>K>>MOD;

    vector<vector<ll>> dp0(K+1, vector<ll>(2));
    vector<vector<ll>> dp1(K+1, vector<ll>(2));

    dp1[0][0] = 1;
    for (int x=0;x<=K;x++){
        dp0[x][0] = 1;
    }
    
    for (int j=2;j<=N+1;j++){
        vector<vector<ll>> new_dp(K+1, vector<ll>(2));

        ll s0,s1;
        ll t0,t1;
        ll v0,v1;
        t0=t1=0;
        s0=s1=0;
        v0=v1=0;
        for (int x=0;x<=K;x++){
            s0 += dp0[x][0];
            s1 += dp0[x][1];
            t0 += dp1[x][0];
            t1 += dp1[x][1];
            v0 += dp1[x][0]*x%MOD;
            v1 += dp1[x][1]*x%MOD;
            if (s0>=MOD){s0-=MOD;}
            if (s1>=MOD){s1-=MOD;}
            if (t0>=MOD){t0-=MOD;}
            if (t1>=MOD){t1-=MOD;}
            if (v0>=MOD){v0-=MOD;}
            if (v1>=MOD){v1-=MOD;}
        }
        for (int x=0;x<=K;x++){
            new_dp[x][0] += s0;
            new_dp[x][0] += t1*(K-x)%MOD;
            new_dp[x][0] += MOD-v1;
            new_dp[x][0] %= MOD;

            new_dp[x][1] += s1;
            new_dp[x][1] += t0*(K-x)%MOD;
            new_dp[x][1] += MOD-v0;
            new_dp[x][1] %= MOD;

            t0 -= dp1[K-x][0];
            if (t0<0){t0+=MOD;}
            t1 -= dp1[K-x][1];
            if (t1<0){t1+=MOD;}
            v0 -= dp1[K-x][0]*(K-x)%MOD;
            if (v0<0){v0+=MOD;}
            v1 -= dp1[K-x][1]*(K-x)%MOD;
            if (v1<0){v1+=MOD;}

        }
        swap(dp0,dp1);
        swap(new_dp,dp0);

    }

    ll ans = dp0[0][0] - dp0[0][1];
    if (ans<0){ans+=MOD;}
    cout<<ans<<"\n";
}

int main() {
    fastio;
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
