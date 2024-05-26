#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    for(int i=1;i<=n;i++)   cin>>a[i];
    b=a;
    vector<vector<int>> ve(n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i])   ve[j].push_back(i);
        }
    }
    vector<pair<int,int>> ans;
    for(int i=n;i>=1;i--){
        sort(ve[i].begin(),ve[i].end(),[&](int x,int y){if(b[x]!=b[y])   return b[x]<b[y];else return x<y;});
        for(auto j:ve[i])  {ans.push_back({j,i});swap(a[i],a[j]);}
        // for(int i=1;i<=n;i++)   cout<<a[i]<<' ';
        // cout<<'\n';
    }
    cout<<ans.size()<<'\n';
    for(auto [x,y]:ans) cout<<x<<' '<<y<<'\n';
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--) solve();
    return 0;
}