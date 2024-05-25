// LUOGU_RID: 160019995
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=2e5+10;
const int mod=1e9+7;
vector<int> a[N];
int dp[N][2];
vector<int> b[N];
int edge[N];
int vis[N];
int t=0;
void dfs(int x){
	vis[x]=1;
	t+=1;
	if(t>1e6){
		cout<<"Draw"<<endl;
		exit(0);
	}
	for(auto y:b[x]){
		dfs(y);	
	}
}
int fa[N][2];
void solve(){
	int n,m;
	cin>>n>>m;
	queue<pair<int,int>> q;
	for(int i=1;i<=n;i+=1){
		int x;
		cin>>x;
		if(x==0){
			q.push({i,0});
			dp[x][0]=1;
		}
		while(x--){
			int t;
			cin>>t;
			b[i].push_back(t);
			a[t].push_back(i);
		}
	}
	while(q.size()){
		auto [x,w]=q.front();
		q.pop();
		w^=1;
		for(auto y:a[x]){
			if(dp[y][w]) continue;
			dp[y][w]=1;
			fa[y][w]=x;
			q.push({y,w});
		}
	}
	int s;
	cin>>s;
	if(dp[s][1]){
		cout<<"Win"<<endl;
		int w=1;
		vector<int> ans;
		while(s){
			cout<<s<<" ";
			s=fa[s][w];
			w^=1;
		}
	
		return;
	}
	dfs(s);

		cout<<"Lose"<<endl;
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