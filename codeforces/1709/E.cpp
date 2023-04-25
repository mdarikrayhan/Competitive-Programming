#include<bits/stdc++.h>
using namespace std;const int N=2e5+7;
basic_string<int>e[N];int n,a[N],v[N],i,j,k,ans;set<int>s[N];
void dfs(int x,int fa){
	v[x]=v[fa]^a[x];s[x].insert(v[x]);int f=0;
	for(int y:e[x])if(y!=fa){
		dfs(y,x);
		if(s[y].size()>s[x].size())s[y].swap(s[x]);
		for(int V:s[y])f|=s[x].count(a[x]^V);
		for(int V:s[y])s[x].insert(V);
	}
	if(f)ans++,s[x].clear(); 
}
int main(){
	for(scanf("%d",&n),i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),e[j]+=k,e[k]+=j;
	dfs(1,0);printf("%d\n",ans);
}