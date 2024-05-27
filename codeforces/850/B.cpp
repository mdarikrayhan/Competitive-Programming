/*
    Created by:- milind0110
*/
// #pragma GCC optimize("O3")
// #pragma GCC target ("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #pragma comment(linker, "/STACK:268435456");
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define int long long
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 1e18;
const int N = 2e6 + 1;
void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> cnt(N);
    vector<int> sum(N);
    vector<int> pref(N);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
        pref[x]++;
        sum[x] += x;
    }
    for(int i = 1; i < N; i++){
        pref[i] += pref[i - 1];
        sum[i] += sum[i - 1];
    }
    int ans = inf;
    for(int i = 2; i < N; i++){
        int cost = 0;
        for(int j = i; j < N; j += i){
            int up = max(j - i + 1,j - x / y);
            int cnt = pref[j] - pref[up - 1];
            assert(cnt * j - (sum[j] - sum[up - 1]) >= 0);
            cost += (cnt * j - (sum[j] - sum[up - 1])) * y;
            assert((pref[up - 1] - pref[j - i]) >= 0);
            cost += (pref[up - 1] - pref[j - i]) * x; 
        }
        ans = min(ans,cost);
    }
    cout << ans << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int32_t t = 1;
    // cin >> t;
    for(int32_t i = 1; i <= t; i++){
        solve();
    }
    return 0; 
}  
