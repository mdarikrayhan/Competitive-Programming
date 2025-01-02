#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    set<int> st;
    for(int i = 0, x; i < n; i ++)
        cin >> x, st.insert(x);
    vector<int> a;
    for(auto x : st)
        a.push_back(x);
    int x = a[0];
    for(int i = 1; i < a.size(); i ++){
        if(x * 2 > a[i]){
            cout << "YES";
            return;
        }
        x = a[i];
    }
    cout << "NO";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --)
        solve();
}