// LUOGU_RID: 159683532
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

//#define int long long

const int N=1000+5;
int n;
int fa[505][505];
int a[1005],vis[1005];   // 每个人的薪水
int f[1005];
int find(int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>fa[i][j];
        }
        a[i]=fa[i][i];
    }
    for(int i=1;i<=n;i++)f[i]=i;
    int tot=n;

    vector<tuple<int,int,int>>vt;       // a[fa],u,v
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vt.emplace_back(fa[i][j],i,j);
        }
    }
    sort(vt.begin(), vt.end());
    vector<pair<int,int>>ans;
    for(auto [val,u,v]:vt){
        u=find(u),v=find(v);
        if(u==v)continue;
        if(a[u]==val){
            ans.emplace_back(v,u);
            f[v]=u;
        }
        else if(a[v]==val){
            ans.emplace_back(u,v);
            f[u]=v;
        }
        else{
            a[++tot]=val;
            ans.emplace_back(u,tot);
            ans.emplace_back(v,tot);
            f[tot]=tot;
            f[u]=tot,f[v]=tot;
        }
    }
    cout<<tot<<endl;
    for(int i=1;i<=tot;i++)cout<<a[i]<<' ';
    cout<<endl;
    cout<<tot<<endl;
    for(auto [x,ff]:ans)cout<<x<<' '<<ff<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
//    cin>>T;
    while(T--){
        solve();
    }
}