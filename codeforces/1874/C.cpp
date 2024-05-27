// LUOGU_RID: 160054714
// LUOGU_RID: 159710606
#include<bits/stdc++.h>
#define int long long
//#define ll long long
#define endl '\n'
#define LL __int128
using namespace std;
const int MOD=1e9+7;
const int N=5e3+10;
const int inf=1e9;
const double eps=1e-12;
int ksm(int base,int mi){
	int s=1;
	while(mi){
		if(mi&1) s=s*base%MOD;
		mi>>=1;
		base=base*base%MOD;
	}
	return s;
}
double prob[N][N],f[N];
void Init(){
	prob[1][1]=1;prob[2][1]=0.5;
	for(int i=3;i<N;i++){
		prob[i][1]=1.0/i;
		for(int j=2;j<=i;j++){
			prob[i][j]=(j-2)*1.0/i*prob[i-2][j-2]+(i-j)*1.0/i*prob[i-2][j-1];
		}
	}
}
bool cmp(int x,int y){
	return f[x]>f[y];
}
vector<int> edge[N];
void solve(){
	int n,m;cin>>n>>m;
	for(int i=0;i<=n;i++) edge[i].clear();
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		edge[u].push_back(v);
	}
	f[n]=1;
	for(int i=n-1;i>=1;i--){
		int len=edge[i].size();
		f[i]=0;
		sort(edge[i].begin(),edge[i].end(),cmp);
		for(int j=0;j<len;j++){
			f[i]+=f[edge[i][j]]*prob[len][j+1];
		}
	}
	cout<<fixed<<setprecision(12)<<f[1]<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	Init();
	cin>>T;
	while(T--) solve();
	return 0;
}
/*
5 10
2 4 3 9 6
*/