#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, k, a, mid, b[N], l[N];
double ans, cnt;
void f(int u, int t, double p, int s){
	if(!p)	return;
	if(u == n){
		if(t >= mid)	cnt += p;
		else	cnt += p * a / (a + s);
		return;
	}
	f(u + 1, t + 1, p * l[u + 1] / 10.0, s);
	f(u + 1, t, p - p * l[u + 1] / 10.0, s + b[u + 1]);
}
void dfs(int t, int nk){
	cnt = 0;
	f(0, 0, 1, 0);
	ans = max(ans, cnt);
	if(t == n || !nk)	return;
	for(int i = 0; i <= nk; i++){
		if(l[t + 1] + i <= 10){
			l[t + 1] += i;
			dfs(t + 1, nk - i);
			l[t + 1] -= i;
		}
	}
}
int main(){
	scanf("%d%d%d", &n, &k, &a);
	mid = n / 2 + 1;
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &b[i], &l[i]);
		l[i] /= 10;
	}
	dfs(0, k);
	printf("%.10lf", ans);
	return 0;
}