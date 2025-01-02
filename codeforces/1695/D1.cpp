#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,x,y,f[N],ans;
vector<int>v[N];
void dfs(int x,int fa){
int c=0;
for(int y:v[x])
if(y!=fa) dfs(y,x),f[x]+=f[y],c+=!f[y];
f[x]+=max(c-1,0);
}
signed main(){
scanf("%d",&t);
while(t--){
scanf("%d",&n),ans=1e9;
for(int i=1;i<=n;i++) v[i].clear();
for(int i=1;i<n;i++)
scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
if(n==1){puts("0");continue;}
for(int i=1;i<=n;i++)
if(v[i].size()<2) fill(f+1,f+1+n,0),dfs(i,0),ans=min(ans,f[i]+1);
printf("%d\n",ans);
}
return 0;
}