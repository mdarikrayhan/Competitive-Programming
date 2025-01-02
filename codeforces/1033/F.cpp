#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
int W,N,M,ct[600000],a[30009],f[4444],v[4444];char s[15];
signed main(void) {
	scanf("%d %d %d",&W,&N,&M);
	for(int i=1;i<=N;i++) {
		scanf("%d",&a[i]);
		int pp=1,tp=0;
		for(int j=0;j<W;j++) {
			if((a[i]>>j)&1) tp+=pp;
			pp*=3;
		} 
		ct[tp]++;v[a[i]]++;
	}
	int pp=1;
	for(int i=0;i<W;i++) pp*=3;
	for(int i=0;i<pp;i++) {
		int qq=1;
		for(int j=0;j<W;j++) {
			int nc=(i/qq)%3;
			if(nc==2) {
				ct[i]=ct[i-qq]+ct[i-qq-qq];
				break;
			}
			qq*=3;
		}
	}
	while(M--) {
		scanf("%s",s);
		int pp=1;
		f[0]=0;
		for(int i=W-1;i>=0;i--) {
			int a0=0,a1=0;
			if(s[i]=='A') {
				a0=3;a1=1;
			} else if(s[i]=='O') {
				a0=1;a1=0;
			} else if(s[i]=='X') {
				a0=1;a1=2;
			} else if(s[i]=='a') {
				a0=0;a1=2;
			} else if(s[i]=='o') {
				a0=2;a1=3;
			} else {
				a0=2;a1=1;
			}
			a0*=pp;a1*=pp;
			a0-=pp;a1-=pp;
			if(a0<0) a0=-80000000;
			if(a1<0) a1=-80000000;
			for(int j=0;j<(1<<W-i-1);j++) {
				f[j|(1<<W-i-1)]=f[j]+a1;
				f[j]+=a0;
			}
			pp*=3;
		}
		int as=0;
		for(int i=0;i<(1<<W);i++) {
			if(f[i]>=0) as+=v[i]*ct[f[i]];
		}
		printf("%d\n",as);
	}
}