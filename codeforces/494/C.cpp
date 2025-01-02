// LUOGU_RID: 159196295
// Problem: Helping People
// URL: https://www.luogu.com.cn/problem/CF494C
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// Author: Nityacke
// Time: 2024-05-16 20:41:24

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define pb push_back
#define db double
using namespace std;
const int N=1e5+5,M=5e3+5,lgV=20;
struct Node{int l,r;db val;}p[M];
int a[lgV][N],n,m,st[M],top,mx[M];
db f[M][M],ans;
vector<int>G[M];
inline bool cmp(Node a,Node b){
	return a.l!=b.l?a.l<b.l:a.r>b.r;
}
inline int ask(int l,int r){
	int len=__lg(r-l+1);
	return max(a[len][l],a[len][r+1-(1<<len)]);
}
inline void dfs(int x){
	if(!G[x].size()){
		for(int i=1;i<=m;++i) f[x][i]=1;
		return f[x][0]=1-p[x].val,void();
	}
	for(auto v:G[x]) dfs(v);
	for(int j=0;j<=m;++j){
		db s1=1,s2=1;
		for(auto v:G[x]){
			if(mx[x]-mx[v]-1+j<=m&&mx[x]-mx[v]-1+j>=0) s1*=f[v][j+mx[x]-mx[v]-1];
			if(mx[x]-mx[v]+j<=m) s2*=f[v][j+mx[x]-mx[v]];
		}
		if(j==0) f[x][j]=(1-p[x].val)*s2;
		else f[x][j]=p[x].val*s1+(1-p[x].val)*s2;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[0][i];
	for(int j=1;j<lgV;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			a[j][i]=max(a[j-1][i],a[j-1][i+(1<<(j-1))]);
	for(int i=1;i<=m;++i)
		cin>>p[i].l>>p[i].r>>p[i].val;
	p[++m]={1,n,0},sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;++i){
		while(top&&p[st[top]].r<p[i].l) --top;
		if(top) G[st[top]].pb(i);
		st[++top]=i,mx[i]=ask(p[i].l,p[i].r);
	}
	dfs(1);
	for(int i=0;i<=m;++i)
		ans+=(f[1][i]-(!i?0:f[1][i-1]))*(i+mx[1]);
	printf("%.9lf\n",ans);
}