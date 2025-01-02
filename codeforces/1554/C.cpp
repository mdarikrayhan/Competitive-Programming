// LUOGU_RID: 159240116
#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,ans;
signed main()
{
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		m++;
		ans=0;
		for(int i=30;i>=0;i--){
			if((n>>i&1)==0&&(m>>i&1)==1){
				ans|=(1<<i);
			}
			if((n>>i&1)==1&&(m>>i&1)==0){
				break;
			}
		}	
		printf("%lld\n",ans);
	}	
	return 0;
}
//dyyyyds