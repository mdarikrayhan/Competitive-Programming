#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
const long long INF = 1000000000000;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;
#define mod (int )(1e9 + 7)
#define modd 998244353
const double PI = 3.1415926535897932384626433;
ll a[3005];
// ll b[MAXN];
// ll pref[MAXN];
ll pre[3005][3005];
void solve(){
    ll n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pre[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        
        for(int j = 1; j <= n; j++){
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][a[i]]++;
    }
    ll ans = 0;
    
    for(int j = 1; j <= n; j++){
        
        for(int k = j + 1; k <= n; k++){
            
            ll sj = pre[n][a[j]] - pre[k][a[j]];
            
            ll sk = pre[j - 1][a[k]];
            
            ans += sj * sk;
        }
    }
    cout << ans << "\n";
}  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    // freopen("input.txt", "r",stdin);
    // freopen("output.txt", "w",stdout);
    ll t;
    cin >> t;
    while(t--){
    solve();
    }
    return 0;
}