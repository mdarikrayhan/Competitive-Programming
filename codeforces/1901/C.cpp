#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    ll maxi = a[0];
    ll mini = a[0];
    for (int i = 0; i < n;i++){
        maxi = max(maxi, a[i]);
        mini = min(mini, a[i]);
    }
    vector<ll> ans;
    while(mini!=maxi){
        if(mini%2==maxi%2)
            ans.push_back(0);
        else if(maxi%2==0){
            ans.push_back(1);
            maxi += 1;
            mini += 1;
        }
        else{
            ans.push_back(0);
        }
        maxi /= 2;
        mini /= 2;
    }
    cout << ans.size() << endl;
    if(ans.size()==0)
        return;
    if(ans.size()<=n){
        for(auto v:ans){
            cout << v << " ";
        }
        cout << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    solve();
    return 0;
}