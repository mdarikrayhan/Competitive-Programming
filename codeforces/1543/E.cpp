#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)

int T,n;

set<int> G[65536];



int p[65536],q[65536];

int color[65536];

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=0;i<(1<<n);i++) G[i].clear();
		for(int i=0;i<(1<<(n-1))*n;i++) {
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].insert(v),G[v].insert(u);
		}
		memset(p,-1,sizeof(int)*(1<<n));
		p[0]=0,q[0]=0;
		int tt=0;
		for(auto x:G[0]) p[x]=(1<<tt),q[(1<<tt)]=x,tt++;
		for(int i=1;i<(1<<n);i++) {
			if(__builtin_popcount(i)<=1) continue;
			int a=q[i^lowbit(i)];
			for(auto x:G[a]) {
				if(p[x]!=-1) continue;
				bool ok=1;
				for(int j=0;j<n;j++) {
					if(((i>>j)&1) && !G[q[i^(1<<j)]].count(x)) {
						ok=0;
						break;
					}
				}
				if(!ok) continue;
				p[x]=i,q[i]=x;
				break;
			}
		}
		for(int i=0;i<(1<<n);i++) printf("%d ",q[i]);
		printf("\n");
		if(n!=lowbit(n)) {
			printf("-1\n");
			continue;
		}
		for(int i=0;i<(1<<n);i++) {
			color[i]=0;
			for(int j=0;j<n;j++) {
				if((i>>j)&1) color[i]^=j;
			}
		}
		for(int i=0;i<(1<<n);i++) printf("%d ",color[p[i]]);
		printf("\n");
	}
	return 0;
}
