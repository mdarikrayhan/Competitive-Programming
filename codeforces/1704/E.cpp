#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=1002,mod=998244353;
int T,n,m,a[N],r[N],num,d[N],cnt;
vector<int>e[N];
queue<int>q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),num=cnt=0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			e[i].clear(),r[i]=0;
		}
		for(int u,v;m--;){
			scanf("%d%d",&u,&v);
			e[u].push_back(v),++r[v];
		}
		for(int i=1;i<=n;++i)
			if(!r[i]) q.push(i);
		for(int u;q.size();){
			u=q.front(),q.pop();
			d[++num]=u;
			for(int v:e[u])
				if(!--r[v]) q.push(v);
		}
		for(int i=1;i<n;++i){
			bool flag=0;
			for(int j=n;j;--j)
				if(a[d[j]]>0){
					--a[d[j]],flag=1;
					for(int v:e[d[j]]) ++a[v];
				}
			if(flag) ++cnt;
			else break;
		}
		for(int i=1;i<=n;++i)
			for(int v:e[d[i]])
				(a[v]+=a[d[i]])%=mod;
		printf("%d\n",(a[d[n]]+cnt)%mod);
	}
	return 0;
}