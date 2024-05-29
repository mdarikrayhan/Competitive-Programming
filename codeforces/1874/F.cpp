// LUOGU_RID: 160023658
#include<iostream>
#include<cstring>
using namespace std;
const int N=205,mod=1e9+7;
int n,a[N],f[N][N],g[N][N],fac[N];
inline void add(int &x,int v){if((x+=v)>=mod) x-=mod;}
inline void dec(int &x,int v){if((x-=v)<0) x+=mod;}
signed main(){
	cin>>n,fac[0]=1;
	for(int i=1;i<=n;++i) cin>>a[i],fac[i]=1ll*fac[i-1]*i%mod;
	if(a[1]==n) return cout<<"0\n",0;
	for(int l=n;l;--l){
		memset(g,0,sizeof g),g[l-1][0]=1;
		for(int r=l;r<=n;++r){
			for(int c=0;c<=r-l+1;++c){
				if(c) g[r][c]=g[r-1][c-1];
				for(int k=l+1;k<=r;++k)
					if(a[k]>=r) dec(g[r][c],1ll*g[k-1][c]*f[k][r]%mod);
				add(f[l][r],1ll*g[r][c]*fac[c]%mod);
			}
			if(r<=a[l]) dec(g[r][0],f[l][r]);
		}
	}
	cout<<f[1][n]<<"\n";
}