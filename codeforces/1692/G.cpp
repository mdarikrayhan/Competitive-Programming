#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,k,tmp1,tmp2,tot,d;
	for(scanf("%d", &t);t--; printf("%d\n", tot)) for(scanf("%d %d %d", &n, &k, &tmp1), d = 1, tot = 0, n--; n--; scanf("%d", &tmp2), d = (tmp1 < 2*tmp2) ? d+1 : 1, tmp1 = tmp2, tot += d > k);
	return 0;
}
