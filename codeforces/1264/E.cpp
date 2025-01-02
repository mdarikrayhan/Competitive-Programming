// LUOGU_RID: 160409188
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e5+10,INF=1061109567;
int n,m,s,t,dis[N],inq[N],vis[N],a[110][110],d[N],id[110][110],cnt,evis[N];
int fst[N],nxt[M],to[M],val[M],cost[M],ecnt=1,cur[N];
int C(int x){return x*(x-1)/2;}
void adde(int u,int v,int w,int c){
	ecnt++;
	to[ecnt]=v;
	val[ecnt]=w;
	cost[ecnt]=c;
	nxt[ecnt]=fst[u];
	fst[u]=ecnt;
}
void Adde(int u,int v,int w,int c){adde(u,v,w,c),adde(v,u,0,-c);}
bool bfs(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=t;i++)cur[i]=fst[i];
	queue<int>q;
	dis[s]=0,inq[s]=1,q.push(s);
	while(!q.empty()){
		int u=q.front();inq[u]=0;q.pop();
		for(int i=fst[u];i;i=nxt[i]){
			int v=to[i],w=val[i],c=cost[i];
			if(w&&dis[v]>dis[u]+c){
				dis[v]=dis[u]+c;
				if(!inq[v])q.push(v),inq[v]=1;
			}
		}
	}
	return dis[t]!=INF;
}
int dfs(int u,int in){
	if(u==t)return in;
	int out=0;
	vis[u]=1;
	for(int i=cur[u];i&&in;cur[u]=i=nxt[i]){
		int v=to[i],w=val[i],c=cost[i];
		if(!vis[v]&&w&&dis[v]==dis[u]+c){
			int ret=dfs(v,min(w,in));
			val[i]-=ret,val[i^1]+=ret;
			in-=ret,out+=ret; 
		}
	}
	return out;
}
int main(){
	cin>>n>>m;s=C(n)+n+1,t=s+1;
	int ans=n*(n-1)*(n-2)/6;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)a[i][j]=2;
		}
	}
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		a[u][v]=1;
		a[v][u]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j>i){
				id[i][j]=++cnt;
				if(a[i][j]==1)d[i]++;
				else if(a[i][j]==0)d[j]++; 
			}
		}
	}
	for(int i=1;i<=n;i++)ans-=C(d[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j]==2){
				Adde(s,n+id[i][j],1,0);
				Adde(n+id[i][j],i,1,0);
				evis[id[i][j]]=ecnt;
				Adde(n+id[i][j],j,1,0);
				Adde(i,t,1,d[i]);
				Adde(j,t,1,d[j]);
				d[i]++,d[j]++;
			} 
		}
	}
	while(bfs()){
		int tmp=dfs(s,INF);
		ans-=tmp*dis[t];
	}
//	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]<2)cout<<a[i][j];
			else if(j<i)cout<<!a[j][i];
			else{
				a[i][j]=!val[evis[id[i][j]]-1];
				cout<<a[i][j];
			}
		}
		cout<<"\n";
	}
}