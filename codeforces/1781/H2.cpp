// LUOGU_RID: 101871195
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=998244353,V=410;
int T,n,m,k,f[205][2][2],g[205][2][2],pw[40005];
int x[2],y[2],id[825][825],bel[205][205];
int c[40005][3],tot,now,cnt,num,res,ans;
int vis[825][825],can0[825][825],can1[825][825];
inline int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=(ll)res*a%p;
		b>>=1,a=(ll)a*a%p;
	}
	return res;
}
inline void ins(int i,int x,int y){
	if(!f[i][x][y])++cnt;
	else now=(ll)now*f[i][x][y]%p;
}
inline void del(int i,int x,int y){
	if(!f[i][x][y])--cnt;
	else now=(ll)now*g[i][x][y]%p;
}
inline void add(int u,int x,int y){
	if(c[u][0] || c[u][1]>2)del(0,0,0);
	else if(c[u][1] || c[u][2])
		del(c[u][2]+1,c[u][1]>=1,c[u][1]>=2);
	c[u][x]+=y;
	if(c[u][0] || c[u][1]>2)ins(0,0,0);
	else if(c[u][1] || c[u][2])
		ins(c[u][2]+1,c[u][1]>=1,c[u][1]>=2);
}
inline void solve(){
	tot=res=0;
	if(n<=0 || m<=0)return;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m-1;++j){
			id[x[0]-i+V][y[0]-j+V]=0;
			id[x[1]-i+V][y[1]-j+V]=0;
		}
	}
	for(int i=0;i<=n;++i){
		for(int j=0,u,v;j<=m-1;++j){
			if((v=id[x[1]-i+V][y[1]-j+V]))u=v;
			else u=++tot;
			id[x[0]-i+V][y[0]-j+V]=u;
			id[x[1]-i+V][y[1]-j+V]=u;
			bel[i][j]=u;
		}
	}
	for(int k=1;k<=m;++k){
		cnt=num=0,now=1;
		for(int i=0;i<=n;++i){
			for(int j=0;j<=m-k;++j){
				can0[x[0]-i+V][y[0]-j+V]=1;
				can1[x[1]-i+V][y[1]-j+V]=1;
				add(bel[i][j],0,1);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1,I,J;j<=k;++j){
				if(can0[i+V][j+V]){
					I=x[0]-i,J=y[0]-j;
					add(bel[I][J],vis[x[1]-I+V][y[1]-J+V],-1);
					add(bel[I][J],vis[x[1]-I+V][y[1]-J+V]+1,1);
				}
				if(can1[i+V][j+V]){
					I=x[1]-i,J=y[1]-j;
					add(bel[I][J],vis[x[0]-I+V][y[0]-J+V],-1);
					add(bel[I][J],vis[x[0]-I+V][y[0]-J+V]+1,1);
				}
				vis[i+V][j+V]=1;
				if(can0[i+V][j+V] || can1[i+V][j+V])++num;
			}
			for(int j=0,I,J,X,Y;j<=m-k;++j){
				I=x[0]-(n-i+1)+V,J=y[0]-j+V;
				X=x[1]-(n-i+1)+V,Y=y[1]-j+V;
				add(bel[n-i+1][j],vis[I][J]+vis[X][Y],-1);
				can0[I][J]=0;
				if(can0[I][J]+can1[I][J]==0 && vis[I][J])--num;
				can1[X][Y]=0;
				if(can0[X][Y]+can1[X][Y]==0 && vis[X][Y])--num;
			}
			res=(res+pw[k*i]-(ll)now*(!cnt)*pw[k*i-num])%p;
		}
		for(int i=1;i<=tot;++i)
			for(int j=0;j<3;++j)c[i][j]=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=k;++j)vis[i+V][j+V]=0;
		for(int i=0;i<=n;++i){
			for(int j=0;j<=m-k;++j){
				can0[x[0]-i+V][y[0]-j+V]=0;
				can1[x[1]-i+V][y[1]-j+V]=0;
			}
		}
	}
}
int main(){
	scanf("%d",&T);
	f[1][1][1]=f[1][0][1]=f[1][1][0]=pw[0]=1;
	f[1][0][0]=2;
	for(int i=2;i<=200;++i){
		for(int j=0;j<2;++j){
			f[i][j][1]=f[i-1][j][0];
			f[i][j][0]=(f[i-1][j][0]+f[i-1][j][1])%p;
		}
	}
	for(int i=1;i<=200;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				g[i][j][k]=qpow(f[i][j][k],p-2);
	for(int i=1;i<=40000;++i)pw[i]=(pw[i-1]<<1)%p;
	while(T--){
		scanf("%d%d%d",&n,&m,&k),ans=0;
		for(int i=0;i<k;++i)
			scanf("%d%d",x+i,y+i);
		while(k<2)x[k]=n+1,y[k]=k+1,++k;
		if(y[0]==y[1]){
			swap(n,m);
			swap(x[0],y[0]),swap(x[1],y[1]);
		}
		if(x[0]>x[1] || (x[0]==x[1] && y[0]>y[1]))
			swap(x[0],x[1]),swap(y[0],y[1]);
		for(int S=0;S<16;++S){
			if(S&1)--n,--x[0],--x[1];
			if(S&2)--n;
			if(S&4)--m,--y[0],--y[1];
			if(S&8)--m;
			solve();
			if(S&1)++n,++x[0],++x[1];
			if(S&2)++n;
			if(S&4)++m,++y[0],++y[1];
			if(S&8)++m;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					if(i-(S&1)-(S>>1&1)<=0 || j-(S>>2&1)-(S>>3&1)<=0)++res;
			ans=(ans+(__builtin_parity(S)?-1:1)*res)%p;
		}
		printf("%d\n",(ans+p)%p);
	}
	return 0;
}