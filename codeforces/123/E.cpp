// LUOGU_RID: 158314840
/*
考虑n^3做法
给定(s,t)
注意到这个count实际上是访问过的点数*2-路径长度
只有这条路径上的点不会return
所以，其实是求访问的点数
考虑直接枚举st，从t开始往上找
我们需要解决的核心转移是：
给定数 a_1~a_m，随机排列，设排列后是b_1~b_m，a_m所对应位置是k，求\sum b[i] [1<=i<=k]的期望值
注意到a[x]有贡献，就说明它出现在a[m]之前，这样的概率是1/2
所以两两计算贡献，也就是a[x]/2
所以这相当于这条路上所有点的所有兄弟节点的siz之和/2
其实可以看作是siz[s]-siz[t],注意到开始节点不计数
那答案就是显然是：
\sum_{s,t} (n-siz[t])*ass[s]*ast[t]
这个siz[t]是在s为根情况下
也不能这么说
*/
#include<bits/stdc++.h>
using namespace std;
#define N 1050500
#define int long long 
int x[N],y[N],sx,sy;
int n,m,siz[N],dep[N],deps[N];
int sizx[N];
int res;
vector<int>e[N];
// void dfs(int u,int fa){
//     siz[u]=1;dep[u]=dep[fa]+1;deps[u]=dep[u]*y[u];sizy[u]=y[u];
//     for(auto v:e[u]){
//         if(v==fa)continue;
//         dfs(v,u);siz[u]+=siz[v];deps[u]+=deps[v];g[u]+=g[v];sizy[u]+=sizy[v];
//     }
//     g[u]+=y[u]*(n-siz[u]);
// }
// void dfs2(int u,int fa,int sano,int sdep){
//     // cout<<" "<<u<<" "<<fa<<" "<<sano<<" "<<sdep<<"\n";
//     ans[u]=x[u]*(sano+g[u]-y[u]*(n-siz[u])-sdep-deps[u]+dep[u]*sizy[u]);
//     // for(auto v:e[u])if(v!=fa)sano+=g[v],sdep+=deps[v]-deps[u]*siz[v];
//     for(auto v:e[u]){
//         if(v==fa)continue;
//         dfs2(v,u,sano+g[u]-g[v]-y[u]*(n-siz[u])+y[u]*siz[u],sano+deps[u]-sizy[u]*dep[u]-(deps[v]-deps[v]*sizy[v])+(1-sizy[v]));
//     }
// }
void dfs(int u,int fa){
    siz[u]=1;sizx[u]+=x[u];if(u!=1)dep[u]+=dep[fa]+1;deps[u]=dep[u];
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        siz[u]+=siz[v];sizx[u]+=sizx[v];deps[u]+=deps[v];  
        res+=siz[v]*y[u]*sizx[v];
    }
    res+=(sx-sizx[u])*y[u]*(n-siz[u]);
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;e[u].push_back(v);e[v].push_back(u);
    }
    for(int i=1;i<=n;i++)cin>>x[i],sx+=x[i],cin>>y[i],sy+=y[i];
    dfs(1,0);
    cout<<fixed<<setprecision(15)<<1.0*res/sx/sy<<"\n";
}