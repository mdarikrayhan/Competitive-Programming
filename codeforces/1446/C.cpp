// LUOGU_RID: 160054658
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=31;
int f[N*M];
struct Trie{
	int t[N*M][2],tot=1; bool ise[N*M];
	void ins(int x){
		int u=1;
		for(int i=M-1;i>=0;--i){
			int &v=t[u][(x>>i)&1];
			if(!v)v=++tot;
			u=v,ise[v]=1;
		}
	}
	void dfs(int u){
		if(!u)return;
		if(!t[u][0]&&!t[u][1])return void(f[u]=1);
		dfs(t[u][0]),dfs(t[u][1]);
		f[u]=max(f[t[u][0]],f[t[u][1]])+(ise[t[u][0]]&&ise[t[u][1]]);
	}
}T;
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;++i){int x;cin>>x;T.ins(x);}
	T.dfs(1);
	cout<<n-f[1]<<'\n';
	return 0;
}