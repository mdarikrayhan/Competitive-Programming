#include<bits/stdc++.h>
#define N 200005

int T;

int n,m;
char s[N];

std::vector<int> E[N];

bool flg;

std::stack<int> st;
bool vis[N];
int dfn[N],_dfn,low[N],scc[N],tot,cnt[N];
inline void dfs(int u){
st.push(u),vis[u]=1;
dfn[u]=low[u]=++_dfn;
for(auto v:E[u])
if(!dfn[v])
dfs(v),low[u]=std::min(low[u],low[v]);
else if(vis[v])
low[u]=std::min(low[u],dfn[v]);
if(low[u]==dfn[u]){
cnt[++tot]=0;
int mn=n+1,x=0;
while(st.size()){
int v=st.top();
st.pop();
vis[v]=0;
scc[v]=tot;
if(s[v>>1]=='E')
mn=std::min(mn,v>>1);
else if(x)
flg=0;
else
x=v>>1;
for(auto w:E[v])
cnt[tot]|=cnt[scc[w]];
if(v==u)
break;
}
if(x){
if(x>=mn)
flg=0;
if(cnt[tot])
flg=0;
cnt[tot]=1;
}
}
}

int main(){
scanf("%d",&T);
while(T--){
for(int i=2;i<=(n<<1|1);i++)
E[i].clear(),dfn[i]=low[i]=scc[i]=0;
_dfn=tot=0;
scanf("%d%d%s",&n,&m,s+1);
for(int i=1;i<=m;i++){
int u,v;
scanf("%d%d",&u,&v);
u=u>0?u<<1:(-u)<<1|1,v=v>0?v<<1:(-v)<<1|1;
E[u^1].push_back(v),E[v^1].push_back(u);
}
flg=1;
for(int i=2;i<=(n<<1|1);i++)
if(!dfn[i])
dfs(i);
for(int i=1;i<=n;i++)
if(scc[i<<1]==scc[i<<1|1])
flg=0;
puts(flg?"TRUE":"FALSE");
}
}