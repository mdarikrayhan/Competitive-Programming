#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int v1, v2;     cin>>v1>>v2;
    int t, v0;      cin>>t>>v0;

    int d=0;
    v2 = v2 + (t-1)*v0;
    for(int i=0; i<t; i++){
        d = d + min(v1, v2);
        v1+=v0;
        v2-=v0;
    }
    cout<<d<<endl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    
    return 0;
}