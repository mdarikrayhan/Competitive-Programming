#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define endl '\n'
#define x first
#define y second
#define int long long
typedef long long ll;
typedef pair<int,int>PII;
typedef unsigned long long ull;
const int N =2e5+10 , M = 998244353 ;
const ll INF = 0x3f3f3f3f3f3f3f,mod=998244353;
const int P=131;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,-1,0,1};
//int dxx[]= {-1,-1,0,1,1,1,0,-1};
//int dyy[]= {0,1,1,1,0,-1,-1,-1};
int n,m,k;
int ans;
string x;
map<string,int>mp,vis;
int len;
void dfs(int v,string u){
	if(v==len){
		if(vis[u]==0){
			vis[u]=1;
			ans+=mp[u];
		}
		return;
	}
	if(x[v+1]=='?'){
		dfs(v+1,u);
		for(char i='a';i<='e';i++){
			dfs(v+1,u+i);
		}
	}else dfs(v+1,u+x[v+1]);
}
void solve() {
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++) cin>>s,mp[s]++;
	for(int i=1;i<=m;i++){
		cin>>x;
		ans=0;
		vis.clear();
		len=x.size(); 
		x=" "+x;
		dfs(0,"");
		cout<<ans<<endl;
	}
}
signed main() {
	FAST;
	int t=1;
//	cin>>t;
	while (t--) solve();
	return 0;
}