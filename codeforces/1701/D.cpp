#include<bits/stdc++.h>
using namespace std;const int N=5e5+7,INF=1e9;typedef pair<int,int>pa;
int T_T,i,n,x,ans[N],l,r;set<pa>s;vector<pa>f[N];
int main(){
for(scanf("%d",&T_T);T_T--;){
for(scanf("%d",&n),i=1;i<=n;++i){
scanf("%d",&x);
l=i/(x+1)+1;r=x?i/x:n;
f[l].push_back({r,i});
}
for(i=1;i<=n;++i){
for(auto p:f[i])s.insert(p);
ans[s.begin()->second]=i;
s.erase(s.begin());
}
for(i=1;i<=n;++i)printf("%d ",ans[i]),f[i].clear();
puts("");
}
}