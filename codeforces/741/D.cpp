// LUOGU_RID: 160340051
#include <bits/stdc++.h>
#define MISAKA main
#define ll long long
using namespace std;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
const int N=5e5+10,inf=1e9,mod=998244353;
struct node{int v,w;};
vector<node> g[N];
int n,siz[N],dep[N],mx[N],son[N],cnt[N],c[N],d[N],f[1<<24];
void dfs1(int u){
    siz[u]=1;
    for(auto [v,w]:g[u]){
        d[v]=d[u]^(1<<w);
        dep[v]=dep[u]+1;
        dfs1(v);siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
}
void dfs2(int u){
    f[d[u]]=max(f[d[u]],dep[u]);
    for(auto [v,w]:g[u]) dfs2(v);
}
void calc(int u,int rt){
    mx[rt]=max(mx[rt],dep[u]+f[d[u]]-2*dep[rt]);
    for(int i=0;i<22;i++)
        mx[rt]=max(mx[rt],dep[u]+f[d[u]^(1<<i)]-2*dep[rt]);
    for(auto [v,w]:g[u]) calc(v,rt);
}
void clear(int u){f[d[u]]=-inf;for(auto [v,w]:g[u])clear(v);}
void dfs3(int u,int tp){
    for(auto [v,w]:g[u])if(v!=son[u]) dfs3(v,0);
    if(son[u]) dfs3(son[u],1);
    mx[u]=max(mx[u],f[d[u]]-dep[u]);
    for(int i=0;i<22;i++)
        mx[u]=max(mx[u],f[d[u]^(1<<i)]-dep[u]);
    f[d[u]]=max(f[d[u]],dep[u]);
    for(auto [v,w]:g[u])if(v!=son[u]) calc(v,u),dfs2(v);
    for(auto [v,w]:g[u]) mx[u]=max(mx[u],mx[v]);
    if(!tp) clear(u);
}
signed MISAKA(){
    n=read();
    for(int i=2;i<=n;i++){
        int fa=read(),w=getchar()-'a';
        g[fa].push_back(node{i,w});
    }
    for(int i=0;i<(1<<24);i++) f[i]=-inf;
    dep[1]=N;dfs1(1);dfs3(1,1);
    for(int i=1;i<=n;i++) printf("%d ",mx[i]);
    return 0;
}
