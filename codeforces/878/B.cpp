#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
// typedef __int128 lll;
// typedef __float128 lld;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    stack<pair<int, int>> s;
    for(int i = 0; i < n; i++){
        if(s.size() != 0 && s.top().first == a[i]) {
            s.top().second ++;
        }
        else {
            s.push({a[i], 1});
        }
        if(s.top().second == k){
            s.pop();
        }
    }
    ll tot = 0;
    vector<pair<int, int>> g(0);
    while(s.size() != 0){
        tot += s.top().second;
        g.push_back(s.top());
        s.pop();
    }
    bool mid_rem = false;
    ll border = 0;
    for(int i = 0; i < g.size(); i++){
        int l = i;
        int r = g.size() - 1 - i;
        if(r <= l) {
            if(g.size() % 2 == 1){
                mid_rem = true;
            }
            break;
        }
        if(g[l].first != g[r].first) {
            break;
        }
        if(g[l].second + g[r].second < k){
            break;
        }
        border += k;
        if(g[l].second + g[r].second > k){
            break;
        }
    }
    ll ans = 0;
    if(border == tot) {
        if(m % 2 == 0){
            ans = 0;
        }
        else {
            ans = tot;
        }
    }
    else if(mid_rem) {
        ll rem = (g[g.size() / 2].second * m) % k;
        if(rem != 0){
            ans = rem + border;
        }
        else {
            ans = 0;
        }
    }
    else {
        ll mid = tot - border;
        ans = mid * m + border;
    }
    cout << ans << "\n";
    
    return 0;
}
