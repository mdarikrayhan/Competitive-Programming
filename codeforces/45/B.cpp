// LUOGU_RID: 159904242
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=2e5+10;
const int mod=1e9+7;
int f[N];
int d[N];
int vis[N];
int v[N];
int b[N],vv[N];
vector<int> pp;
int pre[N];
int get(int x){
	if(x==0) return 0;
	if(vv[x]) return pre[x]=0;
	if(vis[x]==0) return x;
	vv[x]=1;
	pp.push_back(x);
	if(x==pre[x]){
		pre[x]=get(f[x]);
		d[x]=1+d[f[x]];
	}else{
		int u=pre[x];
		pre[x]=get(pre[x]);
		d[x]=d[u]+d[x];
	}
	return pre[x];
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		d[i]=0;
		pre[i]=i;
	}
	for(int i=1;i<=m;i+=1) cin>>v[i];
	for(int i=1;i<=m;i+=1) cin>>b[i];
	int res=0;
	for(int i=1;i<=m;i+=1){
		int x=v[i]+res-1;
		x=x%n+1;
		vector<int> o;
		int cnt=0;
		if(vis[x]==0) cnt+=1;
		vis[x]=1;
		int w=b[i]-1;
		while(1){
			int u=get(x);
			for(auto y:pp)
				vv[y]=0;pp.clear();
			if(u==0) break;
			if(d[x]>w) break;
			vis[u]=1;
			cnt+=1;
		}
		cout<<cnt<<endl;
		res=cnt;
	}
	//	for(int i=1;i<=n;i++) cout<<i<<" "<<vis[i]<<endl;
	
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	//	cin>>t;
	while(t--) solve();
	return 0;
}