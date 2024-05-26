#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
struct edge{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){
	}
	bool operator < (const edge&e)const{
		return w<e.w;
	}
}e[maxn];
int n,m,k;
int N;
map<int,int>Map;
int d[1000][1000];
int ans[1000000+10];
int cnt;
int id(int x){
	if(Map.count(x)==0){
		return Map[x]=++N;
	}
	return Map[x];
}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1);
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=k;i++){
		int u=id(e[i].u);
		int v=id(e[i].v);
		d[u][v]=d[v][u]=e[i].w;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<i;j++){
			ans[++cnt]=d[i][j];
		}
	}
	sort(ans+1,ans+cnt+1);
	printf("%lld",ans[k]);
	return 0;
}
 	 	 	  				 	        		   				