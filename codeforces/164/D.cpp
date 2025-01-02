// LUOGU_RID: 116255143
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x[1005],y[1005],d[1005],c[1000005];
vector<int> g[1005];
bool dfs(int u,int k){
	if(u==n+1) return 1;
	if(d[u]) return dfs(u+1,k);
	int t=0;
	for(auto v:g[u]) t+=!d[v],d[v]++;
	if(k>=t&&dfs(u+1,k-t)) return 1;
	for(auto v:g[u]) d[v]--;
	if(t>1){
		d[u]=1;
		if(dfs(u+1,k-1)) return 1;
	}
	d[u]=0;
	return 0;
}
bool check(int mid){
	for(int i=1;i<=n;++i) d[i]=0,g[i].clear();
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j){
			if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])>=mid){
				g[i].emplace_back(j);
				g[j].emplace_back(i);
			}
		}
	}
	return dfs(1,k);
}
int main(){
    cin>>n>>k;
	for(int i=1;i<=n;++i){
        cin>>x[i]>>y[i];
		for(int j=1;j<i;++j) c[++m]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	}
	sort(c+1,c+m+1);
	int l=1,r=m;
	while(l<r){
		int mid=l+r>>1;
		if(check(c[mid])) r=mid;
		else l=mid+1;
	}
    check(c[l]);
	for(int i=1;i<=n;++i) if(d[i]) cout<<i<<" ",k--;
	for(int i=1;i<=n;++i) if(!d[i]&&k) cout<<i<<" ",k--;
	return 0;
}