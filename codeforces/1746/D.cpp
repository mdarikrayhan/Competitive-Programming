#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
basic_string<int>e[N]; 
int s[N],o;
long long ans;
int dfs(int x,int y){
	ans+=s[x]*1ll*y;
	if(e[x].empty())return s[x];
	basic_string<int>w;
	for(int o:e[x]){
		w+=dfs(o,y/e[x].size());
	}
	sort(begin(w),end(w),greater<int>());
	int p=y%e[x].size();
	for(int i=0;i<p;++i)ans+=w[i];
	return s[x]+w[p];
}
int main(){
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>o;ans=0;
		for(i=1;i<=n;++i)e[i]={};
		for(i=2;i<=n;++i)cin>>j,e[j]+=i;
		for(i=1;i<=n;++i)cin>>s[i];
		dfs(1,o);
		cout<<ans<<'\n';
	}
}