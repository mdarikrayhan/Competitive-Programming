#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mkp make_pair

int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!('0' <= ch && ch <= '9')) {
		if (ch == '-') f = -1; ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();
	}
	return x * f;
}

void wr(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x >= 10) wr(x / 10); putchar(x % 10 + '0');
}

const int N = 3000;

int b[N];
int cx, px[N];
int cy, py[N];

bool solve (int x, int y) {
	cx = cy = 0;
	while (x) px[++cx] = (x % 10), x /= 10;
	while (y) py[++cy] = (y % 10), y /= 10;
	int ans = 0;
	for (int i = 1; i <= 4; ++i) {
		if (px[i] != py[i]) ans++;
	}
	return (ans <= 1);
} 

void NO() {
	cout << "No solution" << endl; exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int lst = 1000;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x; b[i] = -1;
		for (int j = 2011; j >= lst; --j)
			if (solve(x, j)) b[i] = j;
		lst = b[i];
		if (lst == -1) NO();
	}
	for (int i = 1; i <= n; ++i)
		cout << b[i] << endl;
	return 0;
}