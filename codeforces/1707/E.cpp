#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;const int N=1e5+7;typedef pair<int,int>pa;
pa f[35][17][N],p;int n,m,i,j,k,Log[N];
pa operator+(pa a, pa b){return pa(min(a.x,b.x), max(a.y,b.y));}
pa F(pa x,int i){
	int t=Log[x.y-x.x+1];
	return f[i][t][x.x]+f[i][t][x.y-(1<<t)+1];
}
int main(){
	for(Log[0]=-1,i=1;i<N;++i)Log[i]=Log[i>>1]+1;
	for(scanf("%d%d",&n,&m),i=1;i<=n;++i)scanf("%d",&j),f[0][0][i]=pa(j,j);
	for(j=1;j<17;++j)for(i=1;i+(1<<j)-1<=n;++i)f[0][j][i]=f[0][j-1][i]+f[0][j-1][i+(1<<j-1)];
	for(k=1;k<35;++k)for(j=0;j<17;++j)for(i=1;i+(1<<j)-1<=n;++i)f[k][j][i]=F(f[k-1][j][i],k-1);
	while(m--){
		scanf("%d%d",&p.x,&p.y);
		if(p==pa(1,n)){puts("0");continue;}
		for(j=0,i=34;i>=0;--i){
			auto ret = F(p,i);
			if(ret.x>1||ret.y<n)p=ret,j|=1<<i;
		}p=F(p,0);j++;
		printf("%d\n",p==pa(1,n)?j:-1);
	}
}