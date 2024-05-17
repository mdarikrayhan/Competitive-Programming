// Practice makes perfect !!
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define sz(x) (ll)(x.size())
#define int long long
typedef long long ll;
typedef string str;
vector<int> v;
int dp[(int)2e5+5], vis[(int)2e5+5], id=1;
int solve(int i=0){
    if (i>=sz(v)) return (i!=sz(v))*1e15;
    auto &ret=dp[i];
    if(vis[i]==id) return ret;
    ret=solve(i+1)+1, vis[i]=id;
    ret=min(ret, solve(i+v[i]+1));
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t;      cin>>t;
    while(t--){
        int n;      cin>>n;
        v=vector<int> (n);
        for (auto &it:v) cin>>it;
        cout<<solve()<<'\n';
        ++id;
    }

    return 0;
}