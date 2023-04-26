#include<bits/stdc++.h>
using namespace std;const int N=2e5+7,mod=998244353;
int n,k,T_T,a[N],b[N],c[N],vis[N],res,ans,i;
int main(){
	for(scanf("%d",&T_T);T_T--;){
		for(scanf("%d%d",&n,&k),res=0,ans=1,i=1;i<=n;++i)scanf("%d",a+i),c[a[i]]=i,vis[i]=0;
		for(i=1;i<=n;++i)scanf("%d",b+i),vis[max(b[i],0)]=i;
		for(i=1;i<=k;++i)if(b[c[i]]==-1)res++;
		for(i=1;i<=n;++i){
			if(i+k<=n&&b[c[i+k]]==-1)res++;
			if(vis[i]&&a[vis[i]]-i>k)ans=0;
			if(!vis[i])ans=1LL*ans*res%mod,res--;
		}printf("%d\n",ans);
	}
}