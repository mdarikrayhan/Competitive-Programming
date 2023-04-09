#include<bits/stdc++.h>
using namespace std;

const int N=3e5+5,w=79,mod=998244353;

int n,m,pw[N],ipw[N],fa[N],dep[N],siz[N],son[N],top[N],f1[N],f2[N],dfn[N],tot,idfn[N];
char s[N];
vector<int>g[N];

int qpow(int x,int y){
int res=1;
for(;y;y>>=1,x=1ll*x*x%mod){
if(y&1)res=1ll*res*x%mod;
}
return res;
}

void dfs1(int u){
f1[u]=(f1[fa[u]]+1ll*pw[dep[u]-1]*(s[u]-'a')%mod)%mod;
f2[u]=(1ll*w*f2[fa[u]]%mod+s[u]-'a')%mod;
siz[u]=1;
for(auto v:g[u]){
if(v==fa[u])continue;
fa[v]=u,dep[v]=dep[u]+1,dfs1(v);
siz[u]+=siz[v];
if(siz[v]>siz[son[u]])son[u]=v;
}
}

void dfs2(int u,int topf){
top[u]=topf,dfn[u]=++tot,idfn[tot]=u;
if(son[u])dfs2(son[u],topf);
for(auto v:g[u]){
if(v==fa[u]||v==son[u])continue;
dfs2(v,v);
}
}

int lca(int u,int v){
while(top[u]!=top[v]){
if(dep[top[u]]<dep[top[v]])swap(u,v);
u=fa[top[u]];
}
return dep[u]<dep[v]?u:v;
}

int kfa(int u,int k){
while(k&&dep[u]-dep[fa[top[u]]]<=k){
k-=dep[u]-dep[fa[top[u]]],u=fa[top[u]];
}
return idfn[dfn[u]-k];
}

int hsh(int u,int v,int l,int len){
if(len<=dep[u]-dep[l]+1){
return 1ll*((f1[u]+mod-f1[kfa(u,len)])%mod)*ipw[dep[u]-len]%mod;
}
int res1=1ll*((f1[u]+mod-f1[fa[l]])%mod)*ipw[dep[l]-1]%mod;
int res2=(f2[kfa(v,dep[v]-dep[l]-len+dep[u]-dep[l]+1)]+mod-1ll*pw[len-dep[u]+dep[l]-1]*f2[l]%mod)%mod;
return(1ll*res1*pw[len-dep[u]+dep[l]-1]%mod+res2)%mod;
}

int main(){
scanf("%d%s",&n,s+1);
pw[0]=ipw[0]=1;
for(int i=1;i<=n;i++){
pw[i]=1ll*w*pw[i-1]%mod;
ipw[i]=qpow(pw[i],mod-2);
}
for(int i=1;i<n;i++){
int u,v;
scanf("%d%d",&u,&v);
g[u].push_back(v);
g[v].push_back(u);
}
dep[1]=1,dfs1(1),dfs2(1,1);
scanf("%d",&m);
while(m--){
int a,b,c,d;
scanf("%d%d%d%d",&a,&b,&c,&d);
int l1=lca(a,b),l2=lca(c,d);
int l=0,r=min(dep[a]+dep[b]-2*dep[l1],dep[c]+dep[d]-2*dep[l2])+1;
while(l<r){
int mid=(l+r+1)>>1;
if(hsh(a,b,l1,mid)==hsh(c,d,l2,mid))l=mid;
else r=mid-1;
}
printf("%d\n",l);
}
return 0;
}