#include <bits/stdc++.h>
using namespace std;
int n, k, cnt, tot[2], ans[2][4010][2];
char a[2010], b[2010];
void upd(char *c, int fl, int l, int r){
	int i;
	for(i = 0; l + i < r - i; i++) swap(c[l + i], c[r - i]);
	tot[fl]++; ans[fl][tot[fl]][0] = l; ans[fl][tot[fl]][1] = r;
}
void calc(char *c, int fl){
	int i, j, l, r;
	for(i = n, j = 0; tot[fl] + k + 1 < cnt; i--){
		if(c[i] == '0') continue;
		j++;
		if(j >= k) upd(c, fl, i, n - tot[fl]);
	}
	l = 1; r = n - cnt + k + 1;
	while(c[l] == '0') l++;
	while(c[r] == '0') r--;
	while(r - l > k){
		upd(c, fl, l, r - 1);
		while(c[l] == '0') l++;
		upd(c, fl, l + 1, r);
		while(c[r] == '0') r--;
	}
	if(k & 1){
		for(i = 1; i <= k + 1 >> 1; i++){
			upd(c, fl, 1, r - 1); upd(c, fl, 2, r);
		}
	}
}
void solve(){
	tot[0] = 0; tot[1] = 0;
	int i, j, x = 0, y;
	scanf("%d%d", &n, &k);
	scanf("%s%s", a + 1, b + 1);
	for(i = 1; i <= n; i++) x += a[i] - b[i];
	if(x != 0){ printf("-1\n"); return; }
	for(i = 1, x = 0; i <= n; i++) x += a[i] - '0';
	cnt = x;
	if(k == 0 || x < k){
		for(i = 1; i <= n; i++){
			if(a[i] != b[i]){ printf("-1\n"); return; }
		}
		printf("0\n"); return;
	}else if(x == k){
		for(i = 1; a[i] != '1'; i++) ;
		x = i;
		for(i = 1; b[i] != '1'; i++) ;
		y = i;
		for(i = 0; x + i <= n && y + i <= n; i++){
			if(a[x + i] != b[y + i]) break;
		}
		if(x + i > n || y + i > n){ printf("2\n%d %d\n%d %d\n", x, n, y, n); return; }
		for(i = n; b[i] != '1'; i--) ;
		y = i;
		for(i = 0; x + i <= n && y - i >= 1; i++){
			if(a[x + i] != b[y - i]) break;
		}
		if(x + i > n || y - i < 1) printf("3\n1 %d\n1 %d\n1 %d\n", n, n - x + 1, y);
		else printf("-1\n");
		return;
	}
	calc(a, 0); calc(b, 1);
	for(i = 1; i <= n; i++){
		if(a[i] != b[i]){ printf("-1\n"); return; }
	}
	printf("%d\n", tot[0] + tot[1]);
	for(i = 1; i <= tot[0]; i++) printf("%d %d\n", ans[0][i][0], ans[0][i][1]);
	for(i = tot[1]; i >= 1; i--) printf("%d %d\n", ans[1][i][0], ans[1][i][1]);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}
 	  	 		  			  		   	 	 		 		 	