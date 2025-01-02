#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;cin>>n;
    if(n%2==0)for(int i=1;i<=n;i++){cout<<n+1-i<<" ";}
    else cout<<-1;
    cout<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;t=1;//cin>>t;
    while(t--) solve();
    return 0;
}
