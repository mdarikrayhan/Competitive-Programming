// // بسم الله
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define iinf INT_MAX
#define pi pair<int,int>
#define endl '\n'
#define linf LONG_LONG_MAX
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll,null_type,less<>,rb_tree_tag,tree_order_statistics_node_update>
/*
// find_by_order, order_of_key
*/
void fastio(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
void file(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
}

#define int ll
#define mod (int)(1e9+7)
void solve() {
    int n; cin >> n;
    vector<int>a(n),b(n); for(auto &aa : a) cin >> aa;
    for(auto &bb : b) cin >> bb;
    sort(all(a));
    sort(all(b));
    int ans = 1;
    for(int i = 0; i<n; i++) {
        int x = lower_bound(all(b), a[i])-b.begin();
        ans *= (x-i);
        ans%=mod;
    }
    cout << ans << endl;



}

void solve1() {

}

signed main() {

    file();
    fastio();
    int t = 1;
    cin >> t;
    while(t--) solve();

}