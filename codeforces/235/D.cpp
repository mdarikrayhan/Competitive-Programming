// LUOGU_RID: 160595436
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=3e3+10;
int n,col[N],vis[N],pre[N],dep[N],f[13][N],id[N];
vector<int>a[N],V;
inline void dfs(int x,int fa){
    vis[x]=1,pre[x]=fa,dep[x]=dep[fa]+1;
    for (auto v:a[x]){
        if (v==fa) continue;
        if (vis[v] && dep[v]<dep[x]){
            int t=x;
            while (1){
                V.push_back(t),col[t]=1;
                if (t==v) break;
                t=pre[t];
            }
        }else if (!vis[v]) dfs(v,x);
    }
}
inline void Dfs(int x,int fa){
    dep[x]=dep[fa]+1,id[x]=id[0],f[0][x]=fa;
    for (auto v:a[x]){
        if (col[v]) continue;
        if (v==fa) continue;
        Dfs(v,x);
    }
}
inline int LCA(int x,int y){
    if (dep[x]<dep[y]) swap(x,y);
    per(i,12,0) if (dep[f[i][x]]>=dep[y]) x=f[i][x];
    if (x==y) return x;
    per(i,12,0) if (f[i][x]^f[i][y]) x=f[i][x],y=f[i][y];
    return f[0][x];
}
void solve(){
    cin>>n;rep(i,1,n){
        int x,y;cin>>x>>y,++x,++y;
        a[x].push_back(y),a[y].push_back(x);
    }
    dfs(1,0);
    for (auto x:V) ++id[0],Dfs(x,0);
    rep(j,1,12) rep(i,1,n) f[j][i]=f[j-1][f[j-1][i]];
    double ans=0;
    rep(i,1,n) rep(j,1,n)
        if (id[i]==id[j]) ans+=1.0/(dep[i]+dep[j]-2*dep[LCA(i,j)]+1);
        else{
            int A=dep[i]+dep[j],B=abs(id[i]-id[j]),C=id[0]-B;
            --B,--C,ans+=1.0/(A+B),ans+=1.0/(A+C),ans-=1.0/(A+B+C);
        }
    cout<<fixed<<setprecision(15)<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}