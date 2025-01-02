#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int t, n, a[N], l[N], r[N], p[N];
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int cnt = n, ans = 0, lst = 0;
		for(int i = 1; i <= n; i++)	l[i] = r[i] = p[i] = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			if(!l[a[i]])	l[a[i]] = i;
			r[a[i]] = i;
		}
		for(int i = 1; i <= n; i++){
			if(!l[i]){
				cnt--;
				continue;
			}
			if(l[i] < r[lst])	p[i] = 1;
			else	p[i] = p[lst] + 1;
			ans = max(ans, p[i]);
			lst = i;
		}
		printf("%d\n", cnt - ans);
	}
	return 0;
}