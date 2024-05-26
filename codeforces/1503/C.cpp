#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long int

template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>>v(n);
    int ans = 0;
    for(int i = 0; i < n; i ++){
        cin >> v[i][0] >> v[i][1];
        ans += v[i][1];
    }
    
    sort(v.begin(), v.end());
    int mx = v[0][0] + v[0][1];
    for(int i = 1; i < n; i ++){
        ans += max(0ll, v[i][0] - mx);
        mx = max(mx, v[i][0] + v[i][1]);
    }
    
    cout << ans << '\n';
}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;

}
