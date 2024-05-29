#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,k) for(int i=j;i<=k;++i)
#define g(i,j,k) for(int i=j;i>=k;--i)
int n,m,s,l;
const int N=202020,mo=1e9+7;
int app[N][2],hv[N][2],u[N],v[N];
int f[N][2][2][2],a[N][2];
vector<int>all;
void fdall(int x){
	if(!x||v[x])return;v[x]=1;
	all.push_back(x);
	f(p,0,1)f(q,0,1)fdall(app[abs(hv[x][p])][q]);
}
inline void Add(int&x,int y){x=(x+y)%mo;}
int a0=1,a1,b0,b1,c0,c1;
inline void DP(int x,int z){
	if(!x)return;all.clear();fdall(x);s=b0=b1=0;
	for(int x:all)a[++s][0]=hv[x][0],a[s][1]=hv[x][1];
	f(i,1,s)u[abs(a[i][0])]=u[abs(a[i][1])]=1;
	if(abs(a[1][1])!=abs(a[2][0])&&abs(a[1][1])!=abs(a[2][1]))swap(a[1][0],a[1][1]);
	f(i,2,s)if(abs(a[i-1][1])!=abs(a[i][0]))swap(a[i][0],a[i][1]);
	f(i,0,s)f(p,0,1)f(q,0,1)f(r,0,1)f[i][p][q][r]=0;
	if(a[1][0])f[0][0][1][1]=1;f[0][0][0][0]=1;
	f(i,1,s)f(p,0,1)f(q,0,1)f(r,0,1)f(rr,0,1){
		if(!a[i][1]&&rr)break;
		int u=r^(a[i][0]<0),v=rr^(a[i][1]<0);
		Add(f[i][p^(u|v)][q][rr],f[i-1][p][q][r]);
	}
	f(q,0,1)f(r,0,1)if(z||q==r)Add(b0,f[s][0][q][r]),Add(b1,f[s][1][q][r]);
	c0=a0*b0+a1*b1;
	c1=a0*b1+a1*b0;
	a0=c0%mo;a1=c1%mo;
}
signed main(){
	cin>>n>>m;
	f(i,1,n){
		scanf("%lld",&s);
		f(j,0,s-1){
			scanf("%lld",&hv[i][j]);
			l=abs(hv[i][j]);
			app[l][!!app[l][0]]=i;
		}
	}
	f(i,1,m)if(!app[i][1]&&!v[s=app[i][0]])DP(s,1);
	f(i,1,n)if(!v[i]&&!hv[i][1])DP(i,0);
	f(i,1,n)if(!v[i])DP(i,0);
	f(i,1,m)if(!u[i])a1=a1*2%mo;
	cout<<a1;
	return 0;
}