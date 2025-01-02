#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void solve(){
    lli n,x,m;
    cin>>n>>x>>m;
    lli l=x,r=x;
    vector<pair<lli,lli>> v(m);
    for(lli i=0;i<m;i++){
        cin>>v[i].first;
        cin>>v[i].second;
        if((v[i].second>=l && v[i].first<=l) || (v[i].first<=r && v[i].second>=r)){
            l=min(l,v[i].first);
            r=max(r,v[i].second);
        }
    }
    cout<<r-l+1<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}