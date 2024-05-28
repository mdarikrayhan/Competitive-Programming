#include <bits/stdc++.h>
using namespace std;

int n,m,k,mod;

bool rv=0;

int cnt[1005],res[1005];

int Pow2[1005];

int ans=1;

int main() {
	scanf("%d %d %d",&n,&m,&k);
	if(n%2!=m%2) {
		printf("0");
		return 0;
	}
	if(n<m) swap(n,m),rv=1;
	for(int i=1;i<=n;i++) res[i]=1;
	for(int i=1;i<=k;i++) {
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if(rv) swap(x,y);
		cnt[x]++,res[x]*=z;
	}
	scanf("%d",&mod);
	Pow2[0]=1;
	for(int i=1;i<=m;i++) Pow2[i]=Pow2[i-1]*2%mod;
	bool ok=0;
	for(int i=1;i<=n;i++) {
		if(cnt[i]==0 && ok==0) {
			ok=1;
			continue;
		}
		if(cnt[i]==m) {
			if(res[i]==1) ans=0;
			continue;
		}
		ans=1LL*ans*Pow2[m-cnt[i]-1]%mod;
	}
	printf("%d",ans);
	return 0;
}

	   		 		 		   					 			 	 		 	