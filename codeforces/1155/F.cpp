// LUOGU_RID: 160500478
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using pi=pair<int,int>;
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define G(i,a,b) for(int i=(a);i>=(b);i--)
#define ms(a,b) memset(a,b,sizeof(a))
#define si(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define pb push_back

const int N=14,S=1<<14;
int dis[N][S],f[N][N][S],dp[S];
array<int,3> pre[S];
pi pr[N][S],g[N][N][S];
vi adj[N];

void rec(int u,int v,int s){
	if(!s) return;
	auto [p,q]=g[u][v][s];
	cout<<p+1<<' '<<v+1<<'\n';
	rec(u,p,q);
}

void rec(int s){
	if((s&-s)==s) return;
	auto [t,i,j]=pre[s];
	rec(i,j,t|(1<<j));
	rec(s^t);
}

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	F(i,1,m){
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	F(i,0,n-1){
		ms(dis,63);
		dis[i][0]=0;
		queue<pi> q;
		q.push({i,0});
		while(si(q)){
			auto [u,s]=q.front();
			q.pop();
			for(int v:adj[u]) if(~s>>v&1){
				if(v==i&&pr[u][s].fi==i) continue;
				if(dis[u][s]+1<dis[v][s|(1<<v)]){
					dis[v][s|(1<<v)]=dis[u][s]+1;
					pr[v][s|(1<<v)]={u,s};
					q.push({v,s|(1<<v)});
				}
			}
		}
		F(j,0,n-1) F(s,0,(1<<n)-1){
			f[i][j][s]=dis[j][s];
			g[i][j][s]=pr[j][s];
		}
	}
	ms(dp,63);
	F(i,0,n-1) dp[1<<i]=0;
	F(s,1,(1<<n)-1){
		for(int t=(s-1)&s;t;t=(t-1)&s){
			F(i,0,n-1) if((s^t)>>i&1){
				F(j,0,n-1) if((s^t)>>j&1){
					if(dp[s^t]+f[i][j][t|(1<<j)]<dp[s]){
						dp[s]=dp[s^t]+f[i][j][t|(1<<j)];
						pre[s]={t,i,j};
					}
				}
			}
		}
	}
	cout<<dp[(1<<n)-1]<<'\n';
	rec((1<<n)-1);
}