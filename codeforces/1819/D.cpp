#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,m,lst[o],col[o],asd,sz[o],v[o],s[o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d%d",&n,&m);++asd;v[0]=1;
		for(int i=1,K,lst0=0,l=1,mx;i<=n+1;s[i]=s[i-1]+v[i],++i){
			if(i>n){
				for(int j=n,res=0;j>=l;--j){
					res=min(res+sz[j],m);
					if(!sz[j]) res=m;
					if(v[j-1]) ans=max(ans,res);
				}
				continue;
			}
			scanf("%d",&K);sz[i]=K;mx=v[i]=0;
			if(!K){lst0=i;v[i]=1;continue;}
			for(int a;K--;){
				scanf("%d",&a);
				if(col[a]^asd) col[a]=asd,lst[a]=0;
				mx=max(mx,lst[a]);lst[a]=i;
			}
			if(lst0||mx) if(l==1||s[max(lst0,mx)-1]>s[l-2]) v[i]=1;
			l=max(l,mx+1);
		}
	}
	return 0;
}
