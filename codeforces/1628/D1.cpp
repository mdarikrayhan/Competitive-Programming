#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fs first
#define sc second
#define pb push_back

ll MOD=1e9+7;

ll pm(ll a,ll b){
    if(b==0)return 1;
    ll c=pm((a*a)%MOD,b/2);
    if(b%2)c*=a;
    return c%MOD;
}

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    ll dp[n+1][n+1];
    for (ll i=0;i<=n;i++){
        dp[i][0]=0;
        dp[i][i]=(i*k)%MOD;
        for (int j=1;j<i;j++){
            dp[i][j]=((dp[i-1][j-1]+dp[i-1][j])%MOD*pm(2,MOD-2))%MOD;
        }
    }
    cout<<dp[n][m]<<'\n';
}

int main() {   
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin>>t; while (t--) solve();
}