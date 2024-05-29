// LUOGU_RID: 160230480
// Problem: Policeman and a Tree
// URL: https://www.luogu.com.cn/problem/CF868E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Author: Nityacke
// Time: 2024-05-25 10:32:48

#include<iostream>
#include<vector>
#include<queue>
#define pb push_back
using namespace std;
const int N=55,INF=2e9;
int n,m,s,to[N<<1],w[N<<1],cnt[N],deg[N];
vector<int>G[N];
int f[N][N<<1][N];
inline void solve(int,int);
inline int dp(int a,int b,int c){
	if(!f[a][b][c]) solve(a,b);
	return f[a][b][c];
}
struct Node{
	int i,e,c;
	inline int val()const{return c<i?dp(i,e,c+1):0;}
	inline bool operator<(const Node b)const{return val()<b.val();}
};
inline void solve(int i,int j){
	f[i][j][0]=INF;
	if(deg[to[j]]==1)
		for(int k=1;k<=i;++k) f[i][j][k]=k<i?dp(i-k,j^1,i-k)+w[j]:w[j];
	else{
		priority_queue<Node>Q;
		for(auto e:G[to[j]]) if(e!=(j^1)) Q.push({i,e,0});
		for(int k=1;k<=i;++k){
			Node x=Q.top();Q.pop();
			f[i][j][k]=min(f[i][j][k-1],x.val()+w[j]);
			x.c++,Q.push(x);
		}
	}
}
inline int dfs(int x,int fa){
	int res=cnt[x];
	for(auto e:G[x])
		if(to[e]!=fa) res+=dfs(to[e],x);
	return res;
}
signed main(){
	cin>>n;
	for(int i=1,u,v,e;i<n;++i)
		cin>>u>>v>>e,++deg[to[i<<1]=v],++deg[to[i<<1|1]=u],
		w[i<<1]=w[i<<1|1]=e,G[u].pb(i<<1),G[v].pb(i<<1|1);
	cin>>s>>m;
	for(int x,i=1;i<=m;++i) cin>>x,++cnt[x];
	int ans=INF;
	for(auto e:G[s]) ans=min(ans,dp(m,e,dfs(to[e],s)));
	cout<<ans<<"\n";
}