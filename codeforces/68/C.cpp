#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
 
typedef pair <int, int> pii;
 
int A[10][10], L[10][10], R[10][10];
int flow[10];
int n;
 
pii Solve(int now, int cst);
 
pii Work(int now, int cur, int cst) {
	if (cur == n) {
		if (flow[now] == 0) return Solve(now + 1, cst);
		return mp(0, 0);
	}
	pii res = mp(0, 0);
	for (int i = L[now][cur]; i <= R[now][cur]; i++) {
		if (i > flow[now]) break;
		flow[now] -= i, flow[cur] += i;
		res = max(res, Work(now, cur + 1, cst + i * i + (i ? A[now][cur] : 0)));
		flow[now] += i, flow[cur] -= i;
	}
	return res;
}
 
pii Solve(int now, int cst) {
	if (now == n - 1) {return mp(1, cst);}
	return Work(now, now + 1, cst);
}
 
int main() {
	cin >> n;
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		int x, y; cin >> x >> y, x--, y--;
		cin >> L[x][y] >> R[x][y] >> A[x][y];
	}
	for (int i = 0; i <= 40; i++) {
		flow[0] = i; pii tmp = Solve(0, 0);
		if (!tmp.fi) continue;
		cout << i << " " << tmp.se << endl;
		return 0;
	}
	cout << -1 << " " << -1 << endl;
	return 0;
}