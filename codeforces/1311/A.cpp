#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, m;cin>>n>>m;
    if (n==m)cout<<0<<endl;
    else cout<<1+(int)((n<m)^((m-n)&1))<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
