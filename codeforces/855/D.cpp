// LUOGU_RID: 158570685
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=2e5+10;
const int mod=1e9+7;
int f[N][22];
int w[N][22];
vector<int> a[N];
int d[N];
int pre[N];
int find(int x){
	if(x==pre[x]) return x;
	return pre[x]=find(pre[x]);
}
void add(int x,int y){
	x=find(x);
	y=find(y);
	pre[y]=x;
}
void dfs(int x){
	for(auto y:a[x]){
		d[y]=d[x]+1;
		f[y][0]=x;
		add(x,y);
		for(int j=1;j<20;j+=1){
			f[y][j]=f[f[y][j-1]][j-1];
			w[y][j]=w[y][j-1]|w[f[y][j-1]][j-1];
		}
		dfs(y);
	}
}
int lca(int x,int y){
	int o,p;
	o=p=0;
//	cout<<x<<" "<<y<<endl;
	for(int j=19;j>=0;j--){
		if(d[x]>d[y]){
			if(d[f[x][j]]>=d[y]) o|=w[x][j],x=f[x][j];
		}else if(d[y]>d[x]){
			if(d[f[y][j]]>=d[x]) p|=w[y][j],y=f[y][j];
		}
	}
//	cout<<x<<" "<<y<<" "<<p<<endl;
	if(x==y){
		if(p==0||p==3) return -1;
		return p;
	}
	for(int j=19;j>=0;j--){
		if(f[x][j]!=f[y][j]){
			o|=w[x][j];
			p|=w[y][j];
			x=f[x][j],y=f[y][j];
		}
	}
	o|=w[x][0],p|=w[y][0];
	x=f[x][0];
	y=f[y][0];

	if(o==1&&p==2) return 2;
	return -1;
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) pre[i]=i;
	for(int i=1;i<=n;i++){
		cin>>f[i][0]>>w[i][0];
		if(f[i][0]==-1) f[i][0]=w[i][0]=0;
		else w[i][0]=1<<w[i][0];
		if(f[i][0]) a[f[i][0]].push_back(i);
		
	}
	for(int i=1;i<=n;i++){
		if(f[i][0]==0){
			d[i]=1;
			dfs(i);
		}
	}
	int q;
	cin>>q;
	while(q--){
		int t,x,y;
		cin>>t>>x>>y;
		if(find(x)!=find(y)){
			cout<<"NO"<<endl;
			continue;
		}
		if(lca(x,y)==t){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
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