#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
const long long INF = 1000000000000;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;
#define mod (int )(1e9 + 7)
#define modd 998244353
const double PI = 3.1415926535897932384626433;
ll a[2005];
// ll b[MAXN];
ll pref[2005];
ll suff[2005];
ll dp[2005][3];
void solve(){   
    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    pref[0] = 0;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + (a[i] == 1);
    }
    suff[n + 1] = 0;
    for(int i = n; i > 0; i--){
        suff[i] = suff[i + 1] + (a[i] == 2);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans,pref[i] + suff[i]);
    }
    for(int l = 1; l <= n; l++){
        ll aa = 0;
        ll bb = 0;
        dp[l - 1][0] = 0;
        dp[l - 1][1] = 0;
        for(int r = l; r <= n; r++){
            if(a[r] == 1){  
                dp[r][0] = max(dp[r - 1][0], dp[r - 1][1]) + 1; // 1
                dp[r][1] = dp[r - 1][1]; // 2
            }else{
                dp[r][1] = dp[r - 1][1] + 1;
                dp[r][0] = dp[r - 1][0];
            }
            ans = max(ans, max(dp[r][0],dp[r][1]) + pref[l - 1] + suff[r + 1]);
        }
    }
    cout << ans << "\n";

}  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    // freopen("input.txt", "r",stdin);
    // freopen("output.txt", "w",stdout);
    solve();
    return 0;
}