#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[45],b[45],k[45],p[45],maxn=-1e18;
int n,u,r;
int s(){
	int sum=0;
	for(int i=1;i<=n;i++) sum+=a[i]*k[i];
	return sum;
}
void dfs(int x,int *a,int f){
	if(x==u+1){
		int sum=0;
		for(int i=1;i<=n;i++) sum+=a[i]*k[i];
		maxn=max(maxn,sum);
		return; 
	}
	if((u-x+1)%2==0) dfs(u+1,a,0);
	int c[45];
	if(f){
		for(int i=1;i<=n;i++) c[i]=a[i]^b[i];
		dfs(x+1,c,0);
	}
	for(int i=1;i<=n;i++) c[i]=a[p[i]]+r;
	dfs(x+1,c,1);
}
signed main(){
	cin>>n>>u>>r;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>k[i];
	for(int i=1;i<=n;i++) cin>>p[i];
	dfs(1,a,1);
	cout<<maxn;
	return 0;
}
