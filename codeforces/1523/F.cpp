// LUOGU_RID: 160493496
//Linkwish's code
//Ciallo～(∠・ω< )⌒★
#include<bits/stdc++.h>
#define endl '\n'
#define si static inline
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;typedef long double ld;typedef __int128 li;
typedef pair<int,int> pii;typedef pair<ll,ll> pll;typedef const int ci;
typedef const ll cl;const int iinf=1e9;const ll linf=LLONG_MAX;
template<typename T>si bool gmax(T &x,const T y){if(x<y)return x=y,1;return 0;}
template<typename T>si bool gmin(T &x,const T y){if(y<x)return x=y,1;return 0;}

namespace LinkWish{

	ci N=14,M=105;

	int n,m;

	struct T{
		int x,y,t;
		inline bool operator < (const T obj)const{return t<obj.t;}
	}a[N],b[M];

	si int dis(T x,T y){return abs(x.x-y.x)+abs(x.y-y.y);}

	int f[1<<N][M],g[1<<N][M],mn[1<<N][M],dd[1<<N][N];

	si void mian(){
		cin>>n>>m;
		for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y;
		for(int i=1;i<=m;i++)cin>>b[i].x>>b[i].y>>b[i].t;
		sort(b+1,b+1+m);

		memset(f,-1,sizeof f),memset(g,0x3f,sizeof g);
		for(int i=1;i<=m;i++)f[0][i]=1;
		for(int i=0;i<n;i++)g[1<<i][0]=0;

		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=m;j++){
				mn[i][j]=iinf;
				for(int k=0;k<n;k++)if(i&(1<<k))gmin(mn[i][j],dis(b[j],a[k]));
			}
			for(int j=0;j<n;j++){
				dd[i][j]=iinf;
				for(int k=0;k<n;k++)if(i&(1<<k))gmin(dd[i][j],dis(a[j],a[k]));
			}
		}

		for(int i=0;i<(1<<n);i++){
			//g->f
			for(int j=0;j<=m;j++)
				for(int k=1;k<=m;k++)
					if(g[i][j]+mn[i][k]<=b[k].t)gmax(f[i][k],j+1);

			//f->f
			for(int j=1;j<=m;j++){
				if(~f[i][j]){
					gmax(f[i][j],f[i][j]);
					for(int k=1;k<=m;k++){
						if(k!=j&&b[j].t+min(dis(b[j],b[k]),mn[i][k])<=b[k].t){
							gmax(f[i][k],f[i][j]+1);
						}
					}
				}
			}

			//f->g
			for(int j=1;j<=m;j++){
				if(~f[i][j]){
					gmin(g[i][f[i][j]],b[j].t);
					for(int k=0;k<n;k++){
						if(!(i&(1<<k)))gmin(g[i|(1<<k)][f[i][j]],b[j].t+min(dis(a[k],b[j]),dd[i][k]));
					}
				}
			}
			
			//g->g
			for(int j=0;j<=m;j++){
				for(int k=0;k<n;k++){
					if(!(i&(1<<k))){
						gmin(g[i|(1<<k)][j],g[i][j]+dd[i][k]);
					}
				}
			}
		}

		int ans=0;
		for(int i=1;i<=m;i++){
			for(int j=0;j<(1<<n);j++){
				gmax(ans,f[j][i]);
			}
		}
		for(int i=0;i<(1<<n);i++)for(int j=0;j<=m;j++)if(g[i][j]<=iinf)gmax(ans,j);

		cout<<ans<<endl;
	}
}

signed main(){
	#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	LinkWish::mian();
	return 0;
}