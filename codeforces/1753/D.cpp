// LUOGU_RID: 92342014
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,p,q,v[N];
long long d[N],ans=1e18;
vector<pair<int,int>> e[N];
priority_queue<pair<long long,int>> c;
int main(){
scanf("%d%d%d%d",&n,&m,&p,&q);
auto get=[&](int x,int y){return (x-1)*m+y;};
for(int i=1;i<=n;i++){
char s[N];scanf("%s",s+1);
for(int j=1;j<=m;j++){
d[get(i,j)]=s[j]=='.'?(c.emplace(0,get(i,j)),0):1e18;
auto add=[&](int x,int y,int z){if(x>0&&x<=n&&y>0&&y<=m)e[get(x,y)].emplace_back(get(i,j),z);};
if(s[j]=='L')add(i-1,j+1,p),add(i+1,j+1,p),add(i,j+2,q);
if(s[j]=='R')add(i-1,j-1,p),add(i+1,j-1,p),add(i,j-2,q);
if(s[j]=='U')add(i+1,j-1,p),add(i+1,j+1,p),add(i+2,j,q);
if(s[j]=='D')add(i-1,j-1,p),add(i-1,j+1,p),add(i-2,j,q);
}
}
while(c.size()){
int x=c.top().second;c.pop();
if(v[x])continue;v[x]=1;
for(auto [y,z]:e[x])if(d[x]+z<d[y])d[y]=d[x]+z,c.emplace(-d[y],y);
}
for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
if(i<n)ans=min(ans,d[get(i,j)]+d[get(i+1,j)]);
if(j<m)ans=min(ans,d[get(i,j)]+d[get(i,j+1)]);
}
printf("%lld\n",ans<1e18?ans:-1);
return 0;
}