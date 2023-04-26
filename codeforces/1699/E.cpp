#include<bits/stdc++.h>
using namespace std;const int N=5e6+10;
int T_T,n,m,ans,l,r,i,j,f[N],g[N],buc[N];
int main(){
	for(scanf("%d",&T_T);T_T--;){
		for(scanf("%d%d",&n,&m),i=1;i<=m;++i)buc[i]=f[i]=0,g[i]=i;
		for(l=1e9,r=0,i=1;i<=n;++i)scanf("%d",&j),l=min(l,j),r=max(r,j),f[j]=buc[j]=1;
		for(ans=r-l,i=sqrt(m);i;--i){
			for(j=i;j<=m;j+=i){
				if(f[j])buc[g[j]]--;
				if(g[j/i]>=i)g[j]=min(g[j],g[j/i]);
				if(f[j])buc[g[j]]++;
			}
			while(!buc[r])r--;
			ans=min(ans,r-min(l,i));
		}printf("%d\n",ans);
	}
}