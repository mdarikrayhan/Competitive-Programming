// LUOGU_RID: 155941681
// Author: XZC(L_Wave)
// Language: Cpp/G++14
// Problem: F. Caterpillar
// Contest: Codeforces - Codeforces Beta Round 48
// URL: https://codeforces.com/contest/51/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Create Time: not 2024-04-15 11:39:25, but 1926-08-17 11:45:14
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), i##ABRACADABRA = (b); i <= i##ABRACADABRA; i++)
#define drep(i, a, b) for (int i = (a), i##ABRACADABRA = (b); i >= i##ABRACADABRA; i--)
using namespace std;
using ll = long long;

struct edge{
  int v,nxt;
}E[200010];
int dp[2010],hd[2010],val[2010],to[2010],dfn[2010],low[2010],col[2010],tot=1,num,cnt,now,res,d,n,m;
bool cut[200010];
vector<int>G[2010];
void add(int u,int v){
  E[++tot]={v,hd[u]},hd[u]=tot;
}
void tarjan(int u,int from){
  low[u]=dfn[u]=++num;
  for (int i=hd[u];i;i=E[i].nxt){
    if (!(from^i^1))continue;
    int v=E[i].v;
    if (!dfn[v]){
      tarjan(v,i);
      low[u]=min(low[u],low[v]);
      if (low[v]>dfn[u])cut[i]=cut[i^1]=1;
    }else
      low[u]=min(low[u],dfn[v]);
  }
}
void fill(int u){
  col[u]=cnt;
  for (int i=hd[u];i;i=E[i].nxt){
    if (cut[i])continue;
    int v=E[i].v;
    if (!col[v])fill(v);
  }
}
void dfs(int u,int p){
  if (!to[u])to[u]=d;
  dp[u]=0;
  // 0: 这个不选（和上面并起来）
  // 1: 这个要选
  // cout<<u<<' '<<now<<' '<<p<<'\n';
  for (auto v:G[u]){
    if (v==p)continue;
    dfs(v,u);
    dp[u]+=dp[v];
  }
  dp[u]=max(dp[u],1);
  // cout<<u<<' '<<dp[u][0]<<' '<<dp[u][1]<<'\n';
}
void dfs2(int u,int p){
  ++now;
  for (auto v:G[u]){
    if (v==p)continue;
    now+=dp[v];
  }
  res=max(res,now);
  // cout<<u<<' '<<now<<' '<<p<<'\n';
  for (auto v:G[u]){
    if (v==p)continue;
    now-=dp[v];
    dfs2(v,u);
    now+=dp[v];
  }
  --now;
  for (auto v:G[u]){
    if (v==p)continue;
    now-=dp[v];
  }
}

int main() {
  scanf("%d%d",&n,&m);
  rep(i,1,m){
    int u,v;
    scanf("%d%d",&u,&v);
    add(u,v),add(v,u);
  }
  rep(i,1,n)if (!dfn[i])tarjan(i,0);
  rep(i,1,n)if (!col[i])++cnt,fill(i);
  // rep(i,1,n)cout<<i<<' '<<col[i]<<'\n';
  rep(u,1,n)for (int i=hd[u];i;i=E[i].nxt){
    int v=E[i].v;
    if (col[u]^col[v])G[col[u]].push_back(col[v]);
  }
  rep(i,1,cnt){
    if (!to[i])++d;
    dfs(i,0);
    now=res=0,dfs2(i,0);
    val[to[i]]=max(val[to[i]],res);
  }
  int out=0;
  rep(i,1,d)out+=val[i];
  printf("%d\n",n-out+d-1);
  return 0;
}