// LUOGU_RID: 155458047
#include<bits/stdc++.h>
int T;
long long n,f[87],g[7],h[7];
int main(){
	f[0]=f[1]=1;
	for(int i=2;i<87;++i) f[i]=f[i-2]+f[i-1];
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n),memset(g,0,56),g[0]=1;
		for(int i=86;i;--i){
			if(n>=f[i]){
				n-=f[i],g[2]=g[1],g[1]=g[0],g[0]=0;
				g[4]=g[3],g[3]=0,g[6]=g[5],g[5]=0;
			}
			memset(h,0,56);
			h[0]+=g[0],h[4]+=g[1],h[0]+=g[1],h[4]+=g[2];
			h[1]+=g[3],h[1]+=g[4],h[2]+=g[5],h[2]+=g[6];
			memcpy(g,h,56);
		}
		printf("%lld\n",g[0]);
	}
	return 0;
}