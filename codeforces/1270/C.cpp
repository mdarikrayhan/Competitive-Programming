// LUOGU_RID: 159101119
#include <bits/stdc++.h>
using namespace std;
int t,n;
long long sum,x,cnt;
int main(){
	scanf("%d",&t);
	while(t--){
		sum=cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x);
			sum^=x;
			cnt+=x;
		}	
		printf("2\n%lld %lld\n",sum,cnt+sum);
	}
	return 0;
}