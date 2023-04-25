/*这一瞬冲破 最高亢的歌 予我*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=200005,maxk=30;
int n,m,T,ans,flg,dfns,q;
int a[maxn],L[maxn],R[maxn],id[maxn],dep[maxn],fore[maxn][maxk];
vector<int>v[maxn];
struct linearbase{
int b[maxk];
void insert(int x){
for(int i=29;i>=0;i--)
if((x>>i)&1){
if(b[i]==0){
b[i]=x;
return ;
}
x^=b[i];
}
}
int query(){
int res=0;
for(int i=29;i>=0;i--)
if((res^b[i])>res)
res^=b[i];
return res;
}
void clear(){
memset(b,0,sizeof(b));
}
}lb[maxn],pre[maxn],suf[maxn];
void dfs(int x,int last){
dep[x]=dep[last]+1,fore[x][0]=last;
for(int i=1;i<=20;i++)
fore[x][i]=fore[fore[x][i-1]][i-1];
L[x]=++dfns,id[dfns]=x;
lb[x].clear(),lb[x].insert(a[x]);
for(int i=0;i<v[x].size();i++)
if(v[x][i]!=last){
dfs(v[x][i],x);
for(int j=0;j<30;j++){
int w=lb[v[x][i]].b[j];
if(w)
lb[x].insert(w);
}
}
R[x]=dfns;
}
int kthfa(int x,int k){
for(int i=0;i<=20;i++)
if((k>>i)&1)
x=fore[x][i];
return x;
}
int main(){
scanf("%d",&T);
while(T--){
scanf("%d",&n);
for(int i=1;i<=n;i++)
scanf("%d",&a[i]);
for(int i=1,x,y;i<n;i++)
scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
dfns=0,dfs(1,0);
pre[0].clear();
for(int i=1;i<=n;i++)
pre[i]=pre[i-1],pre[i].insert(a[id[i]]);
suf[n+1].clear();
for(int i=n;i>=1;i--)
suf[i]=suf[i+1],suf[i].insert(a[id[i]]);
scanf("%d",&q);
while(q--){
int r,v;
scanf("%d%d",&r,&v);
linearbase now;
if(r==v)
now=lb[1];
else if(L[v]<=L[r]&&L[r]<=R[v]){
int p=kthfa(r,dep[r]-dep[v]-1);
now=pre[L[p]-1];
if(R[p]<n)
for(int j=0;j<30;j++){
int v=suf[R[p]+1].b[j];
if(v)
now.insert(v);
}
}
else now=lb[v];
printf("%d\n",now.query());
}
for(int i=1;i<=n;i++)
v[i].clear();
}
return 0;
}