#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,f[100005],a[100005];
vector<pair<int,int>>ans;
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void merge(int x,int y){
	f[find(x)]=find(y);
}
signed main(){
	cin>>n>>m;
	if(n<m){
		puts("NO");
		return 0;
	}
	if(n==1){
		if(m==1) puts("YES\n0");
		else if(m==0) puts("YES\n1\n1 1");
		else puts("NO");
		return 0;
	}
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=m;++i) cin>>x>>y,merge(x,y),++a[x],++a[y];
	for(int i=1;i<=n;++i)
		if(a[i]>2){
			puts("NO");
			return 0;
		}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(a[i]<2&&a[j]<2&&find(i)!=find(j)){
				++a[i];
				++a[j];
				ans.push_back({i,j});
				merge(i,j);
			}
	if(ans.size()+m<n)
		for(int i=1;i<=n;++i){
			while(a[i]<2){
				++a[i];
				if(ans.size()+m<n) ans.push_back({i,0});
				else ans[ans.size()-1].second=i;
			}
		}
	for(int i=1;i<=n;++i)
		if(find(i)!=find(1)){
			puts("NO");
			return 0;
		}
	cout<<"YES\n"<<ans.size()<<endl;
	for(auto i:ans) cout<<i.first<<' '<<i.second<<endl;
	return 0;
}
	   	 		 	 	 	  	     			 			