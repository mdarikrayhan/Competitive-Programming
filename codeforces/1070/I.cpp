// LUOGU_RID: 97674610
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1505,inf=1e9;
int T,n,m,k,cnt=1,tot,s,t,h[N],d[N],gap[N],ans[N];
struct edge{int n,t,v;}e[N<<2];
void add(int x,int y,int z){e[++cnt]={h[x],y,z},h[x]=cnt;}
void Add(int x,int y,int z){add(x,y,z),add(y,x,0);}
int dfs(int x,int flow) {
	if(x==t)return flow;
	int res=0;
	for(int i=h[x];i;i=e[i].n) {
		int y=e[i].t;
		if(e[i].v>0&&d[x]==d[y]+1) {
			int k=dfs(y,min(e[i].v,flow-res));
			e[i].v-=k,e[i^1].v+=k,res+=k;
			if(flow==res)return res;
		}
	}
	if(!--gap[d[x]])d[s]=tot;
	return ++gap[++d[x]],res;
}
int maxflow() {
	memset(d,0,sizeof(d)),memset(gap,0,sizeof(gap));
	int res=0;gap[0]=tot;while(d[s]<tot)res+=dfs(s,inf);
	return res; 
}
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&m,&k),tot=t=n+m+2,s=t-1;
		memset(h,0,sizeof(h)),cnt=1;
		int sum=0;
		for(int i=1;i<=max(n,m);i++)d[i]=ans[i]=0;
		for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),d[x]++,d[y]++,Add(i,x+m,1),Add(i,y+m,1),Add(s,i,1);
		for(int i=1;i<=n;i++) {
			int x=max(0,d[i]-k)*2;
			Add(i+m,t,x),sum+=x;
		}
		if(maxflow()!=sum) {
			for(int i=1;i<=m;i++)printf("0 ");
			puts("");continue;
		}
		int cl=2;
		for(int i=1;i<=n;i++)for(int j=h[i+m];j;j=e[j].n)if(e[j].v&&e[j].t!=t)ans[e[j].t]=cl/2,cl++;
		cl/=2;
		for(int i=1;i<=m;i++)printf("%d ",ans[i]?ans[i]:++cl);
		puts(""); 
	}
	return 0;
}