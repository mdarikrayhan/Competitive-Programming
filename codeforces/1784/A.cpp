// LUOGU_RID: 159049919
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int t,n,a[N];
signed main() {
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		int ans=0;
		int p=0;
		for(int i=1;i<=n;i++) {
			if(p+1>=a[i]) {
				p=a[i];
				continue;
			}
			ans+=a[i]-(p+1);
			a[i]=p+1,p=a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}