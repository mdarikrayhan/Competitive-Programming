// LUOGU_RID: 159731459
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2E5+5;
vector<int> adj[N];
int n;
LL a[N],dp[N][2];
void dfs(int u,int p) {
	dp[u][1]=-1E18;
	for (int i=0;i<adj[u].size();i++) {
		int v=adj[u][i];
		if (v==p) continue;
		dfs(v,u);
		LL dpzero=dp[u][0],dpone=dp[u][1];
		dp[u][0]=max(dpzero+dp[v][0],dpone+dp[v][1]);
		dp[u][1]=max(dpzero+dp[v][1],dp[v][0]+dpone);
	}
	dp[u][1]=max(dp[u][1],dp[u][0]+a[u]);
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) {
		int p;cin>>p>>a[i];
		if (i!=1) adj[p].emplace_back(i);
	}
	dfs(1,0);
	cout<<max(dp[1][1],dp[1][0])<<'\n';
	return 0;
}