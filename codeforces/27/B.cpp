#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MOD=998244353;
const int maxn=55;
int n;
int cnt[maxn];
bool vis[maxn];
vector<vector<int> > g;
void dfs(int v,int end){
	vis[v]=true;
	if(v==end) return;
	for(int x:g[v]){
		if(!vis[x]){
			dfs(x,end);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	g.resize(n);
	int m=(n-1)*n/2;
	for(int i=0;i<m-1;i++){
		int ai,bi;
		cin>>ai>>bi;
		ai--; bi--;
		cnt[ai]++;
		cnt[bi]++;
		g[ai].push_back(bi);
	}
	vector<int> p;
	for(int i=0;i<m;i++){
		if(cnt[i]==n-2){
			p.push_back(i);
		}
	}
	dfs(p[0],p[1]);
	if(vis[p[1]]){
		cout<<p[0]+1<<" "<<p[1]+1<<endl;
	}else{
		cout<<p[1]+1<<" "<<p[0]+1<<endl;
	}
	return 0;
}