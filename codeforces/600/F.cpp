// LUOGU_RID: 160590498
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2005,M=1e5+5;
int n,m,b,fr[M],to[M],d[N],ans;
int vis[N][N],col[N];
int main(){
	scanf("%d%d%d",&n,&m,&b);
	for(int i=1;i<=b;i++) scanf("%d%d",&fr[i],&to[i]);
	for(int i=1;i<=b;i++) to[i]+=n;
	for(int i=1;i<=b;i++) d[fr[i]]++,d[to[i]]++;
	for(int i=1;i<=n+m;i++) ans=max(ans,d[i]);
	printf("%d\n",ans);
	for(int i=1,x,y,v1,v2,now;i<=b;i++){
		x=fr[i],y=to[i];
		v1=v2=1;
		while(vis[x][v1]) v1++;
		while(vis[y][v2]) v2++;
		vis[x][v1]=y;
		vis[y][v2]=x;
		if(v1==v2) continue;
		now=v1;
		while(x){
			swap(vis[x][v1],vis[x][v2]);
			x=vis[x][now];
			if(now==v1) now=v2;
			else now=v1;
		}
	}
	for(int i=1;i<=b;i++)
		for(int j=1;;j++)
			if(vis[fr[i]][j]==to[i]){
				printf("%d ",j);
				break;
			}
	return 0;
}



