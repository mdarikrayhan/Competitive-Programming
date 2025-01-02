#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int sz = 2e5 + 5;
const int mod = 998244353;

int a[sz], b[sz];

void solve(){
    int n, s, res = 1; cin >> n >> s;
    bool flag = true; set<int>st;
    for(int i = 1; i <= n; i++) cin >> a[i], st.insert(i);
    vector<int>v1, v2;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        if(b[i] != -1) st.erase(b[i]);
        if(b[i] == -1) v1.push_back(a[i]);
        if(b[i] != -1 and a[i] - b[i] > s) flag = false;
    }
    if(!flag){ cout << 0 << '\n'; return;}
    for(int i = 1; i <= n; i++) if(st.count(i)) v2.push_back(i);
    sort(v1.rbegin(), v1.rend());
    for(int i = 0; i < v1.size(); i++){
        int k = lower_bound(v2.begin(), v2.end(), v1[i] - s) - v2.begin();
        int sum = v2.size() - k;
        res = 1LL * res * (sum - i) % mod;
    }
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}