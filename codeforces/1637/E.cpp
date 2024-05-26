#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define F first
#define S second
 
 
using namespace std;
 
void solve(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    map<ll, ll> cnt;
    ll mx = 0;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    map<ll, set<ll>> bad;
    for(int i = 0; i < m;i++){
        int x, y; cin >> x >> y;
        bad[x].insert(y);
        bad[y].insert(x);
    }
    ll ans = 0;
    vector<vector<ll>> v(n);
    for(auto x: cnt){
        v[x.S].pb(x.F);
    }
    for(auto &x: v){
        reverse(all(x));
    }
    for(int i = 1; i < n;i++){
        for(ll x: v[i]){
            for(int j = 1; j <= i;j++){
                for(ll y: v[j]) if(x != y && !(bad[x].count(y))){
                    ans = max(ans, (x + y) * (i + j));
                    break;
                }
            }
        }
    }

    cout << ans << '\n';

}
 
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
 
int T = 1; cin >> T;
while(T--){
    solve();
}
}