// LUOGU_RID: 128770028
//#pragma GCC optimize(2)
//#pragma GCC optimize(3, "Ofast", "inline")
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1000010, M = 10000010;
 
int n, res, a[N], fa[M];
bool vis[M];
 
int gcd(int a, int b) {
	return !b ? a : gcd(b, a%b);
}
 
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
 
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (!a || !b || a == b) return;
	fa[a] = b, res--;
}
 
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		fa[a[i]] = a[i];
	}
	res = n;
	for (long long i = 1; i < M; i++) {
		for (long long j = i+1; j < M; j++) {
			long long a = j*j-i*i, b = 2*i*j, c = j*j+i*i;
			if (a >= M || b >= M) break;
			if (gcd(a, b) == 1) {
				merge(a, b);
				if (c < M && gcd(a, c) == 1 && gcd(b, c) == 1) {
					merge(a, c), merge(b, c);
				}
			}
		}
	}
	printf("%d\n", res);
	
	return 0;
}