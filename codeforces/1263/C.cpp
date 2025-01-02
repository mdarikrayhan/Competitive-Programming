// LUOGU_RID: 159116026
#include <bits/stdc++.h>
using namespace std;
int n,a[100005],cnt,cntt,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		cnt=0;
		cntt=1;
		while(cntt<=n){
			a[++cnt]=n/cntt;
			cntt=n/(n/cntt)+1;
		}
		printf("%d\n0 ",cnt+1);
		for(int i=cnt;i>0;i--) printf("%d ",a[i]);
		putchar('\n');
	}
	return 0;
}