// LUOGU_RID: 160413528
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=998244353;
const ll inf=2e9;
const int N=2e5+5;
const int M=2e5+5;
const int V=2e6;
int ca,n,fa[500005];
ld dp[500005][62];
vector<int>p;
void solve(int Ca){
	cin>>ca;n=1;
	for(int i=1;i<=60;i++) dp[1][i]=1;
	while(ca--){
		int op,u;
		cin>>op>>u;
		if(op==1){
			p.clear();fa[++n]=u,u=n;
			for(int i=1;i<=60;i++) dp[u][i]=1;
			for(int i=0,now=u;i<=60&&now;i++,now=fa[now]) p.push_back(now);
			for(int i=p.size()-1;i>=2;i--) dp[p[i]][i]/=(0.5+0.5*dp[p[i-1]][i-1]);
			for(int i=1;i<(int)p.size();i++) dp[p[i]][i]*=(0.5+0.5*dp[p[i-1]][i-1]);
		}
		else{
			ld ans=60;
			for(int i=1;i<60;i++) ans-=dp[u][i];
			cout<<fixed<<setprecision(10)<<ans-1<<"\n";
		}
	}
}
int main(){
	#ifdef ONLINE_JUDGE
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	#endif
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	
	int Ca=1;
//	cin>>Ca;
	for(int i=1;i<=Ca;i++){
		solve(i);
	}
	return 0;
}