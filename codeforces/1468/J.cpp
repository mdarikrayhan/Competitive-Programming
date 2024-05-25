#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<array<ll,3>>a;
int fa[200005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    fa[find(x)]=find(y);
}
void solve(){
    a.clear();
    ll n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a.push_back({z,x,y});
    }
    sort(a.begin(),a.end());
    ll ans=0;
    for (int i=0;i<a.size();i++){
        int x=a[i][1],y=a[i][2];
        if (find(x)==find(y)) continue;
        else{
            merge(x,y);
            if (a[i][0]>k) ans+=(a[i][0]-k);
        }
    }
    if (!ans) {
        ans=(ll)1e18;
        for (int i=0;i<a.size();i++) ans=min(ans,abs(a[i][0]-k));
    }
    cout<<ans<<"\n";
}
int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}