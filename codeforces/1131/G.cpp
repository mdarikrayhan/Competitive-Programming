#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
int N,M,k[300009],Q,id[300009],mu[300009],f[10000009],f2[10000009],H[10000009],tp,t,
st[10000009];
long long C[10000009],dp[10000009];
std::vector<int> c[300009],h[300009];
signed main(void) {
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++) {
		scanf("%d",&k[i]);
		int a;
		for(int j=1;j<=k[i];j++) {
			scanf("%d",&a);
			h[i].push_back(a);
		}
		for(int j=1;j<=k[i];j++) {
			scanf("%d",&a);
			c[i].push_back(a);
		}
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++) {
		scanf("%d %d",&id[i],&mu[i]);
		for(int j=1;j<=k[id[i]];j++) {
			H[++tp]=h[id[i]][j-1];
			C[tp]=1ll*mu[i]*c[id[i]][j-1];
		}
	}
	for(int i=M;i>=1;i--) {
		if(H[i]>1&&t) {
			int l=i+H[i]-1;
			int ll=1,rr=t,md;
			while(ll<rr) {
				md=(ll+rr)>>1;
				if(st[md]<=l) {
					rr=md;
				} else {
					ll=md+1;
				}
			}
			f[i]=f[st[ll]];
		} else f[i]=i;
		while(t&&f[i]>=f[st[t]]) {
			t--;
		}
		st[++t]=i;
	}
	t=0;
	for(int i=1;i<=M;i++) {
		if(H[i]>1&&t) {
			int l=i-H[i]+1;
			int ll=1,rr=t,md;
			while(ll<rr) {
				md=(ll+rr)>>1;
				if(st[md]>=l) {
					rr=md;
				} else {
					ll=md+1;
				}
			}
			f2[i]=f2[st[ll]];
		} else f2[i]=i;
		while(t&&f2[i]<=f2[st[t]]) {
			t--;
		}
		st[++t]=i;
	}
	t=0;
	//printf("%d %d\n",f[1],f2[7]);
	memset(dp,0x3f,sizeof(dp));dp[0]=0;
	for(int i=0;i<=M;i++) {
		if(i) {
			int l=f2[i]-1;
			int ll=1,rr=t,md;
			while(ll<rr) {
				md=(ll+rr)>>1;
				if(st[md]>=l) {
					rr=md;
				} else {
					ll=md+1;
				}
			}
			dp[i]=std::min(dp[i],dp[st[ll]]+C[i]);						
		}
		while(t&&dp[i]<=dp[st[t]]) t--;
		st[++t]=i;
		if(i<M) dp[f[i+1]]=std::min(dp[f[i+1]],dp[i]+C[i+1]);
	}
	printf("%lld",dp[M]);
}