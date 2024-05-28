// LUOGU_RID: 159644526
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=605;
const int MOD=998244353;

int h[N],to[N<<1],nex[N<<1],tot;
int dist[N][N],com[N][N];

void add(int u,int v){
	to[tot]=v;
	nex[tot]=h[u];
	h[u]=tot++;
}

void bfs(int x){
	queue<int> mq;
	bool vis[N],inq[N];
	memset(inq,0,sizeof inq);
	memset(vis,0,sizeof vis);
	memset(dist[x],0x3f,sizeof dist[x]);
	dist[x][x]=0;
	mq.push(x);
	com[x][x]=1;
	while(mq.size()){
		int u=mq.front();
		mq.pop();
		inq[u]=false;
		vis[u]=true;
		for(int i=h[u];~i;i=nex[i]){
			int v=to[i];
			if(vis[v])continue;
			if(dist[x][v]>dist[x][u]+1)dist[x][v]=dist[x][u]+1,com[x][v]=com[x][u];
			else if(dist[x][v]==dist[x][u]+1)com[x][v]+=com[x][u];
			if(com[x][v]>1)com[x][v]=2;
			if(!inq[v])mq.push(v),inq[v]=true;
		}
	}
}

void llz(){
	memset(h,-1,sizeof h);
	int n,m;
	cin>>n>>m;
	memset(h,-1,sizeof h);
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;++i)bfs(i);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			//cout<<i<<" "<<j<<" "<<dist[i][j]<<" "<<com[i][j]<<"\n";
			int ans=1;
			if(com[i][j]>1){
				cout<<0<<" ";
				continue;
			}
			for(int k=1;k<=n;++k){
				if(dist[k][i]+dist[k][j]==dist[i][j])continue;
				int cnt=0;
				for(int p=h[k];~p;p=nex[p]){
					int v=to[p];
					if(dist[i][v]+1==dist[i][k]&&dist[j][v]+1==dist[j][k])cnt++;
				}
				//cout<<i<<" "<<j<<" "<<k<<" "<<cnt<<"\n";
				ans=1ll*ans*cnt%MOD;
			}
			cout<<ans<<" ";
		}
		cout<<"\n";
	}
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)llz();
	return 0;
}