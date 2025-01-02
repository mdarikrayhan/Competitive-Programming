// LUOGU_RID: 160446004
#include <bits/stdc++.h>
using namespace std;
typedef double db;

const int N = 105;
const int K = 10005;
const int M = 10000005;
int n, k, cnt, a[N], bar[K], ret[M];
db f[N][K];

void chmax(db &x, db y){x = max(x, y);}
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for(int r, l = 1; l < k; l = r + 1){
		r = (k - 1) / ((k - 1) / l);
		bar[++ cnt] = (k - 1) / l;
		ret[bar[cnt]] = cnt;
	}
	bar[++ cnt] = 0; ret[0] = cnt; f[0][1] = 1.0;
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= cnt; j ++) if(f[i - 1][j]){
		for(int r, l = 1; l <= bar[j]; l = r + 1){
			r = bar[j] / (bar[j] / l); chmax(f[i][ret[bar[j] / l]], f[i - 1][j] * 1.0 * (a[i] / l) / (db)a[i]); 
		}
		chmax(f[i][cnt], f[i - 1][j] * 1.0 * (a[i] / (bar[j] + 1)) / (db)a[i]);
	}
	db ans = f[n][cnt] * 1.0 * k;
	printf("%.15lf\n", ans); return 0;
}