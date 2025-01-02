// LUOGU_RID: 159747589
#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define putln putchar('\n')
#define putsp putchar(' ')
#define inl inline
#define tot_time cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << enl;
#define tot_memory cerr << abs(&mst - &men) / 1024.0 / 1024 << "MB" << enl;
#define getchar() (tt == ss && (tt = (ss = In) + fread(In, 1, 1 << 20, stdin), ss == tt) ? EOF : *ss++)
typedef unsigned int uint;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef pair<lli, int> pli;
typedef pair<lli, lli> pll;
typedef vector<int> vei;
typedef vector<lli> vel;
char In[1 << 20], *ss=In, *tt=In;
namespace IO {
	inl void RS() {freopen("test.in", "r", stdin), freopen("test.out", "w", stdout); }
	inl void TD() {std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL); }
	inl lli read() {
		lli x = 0, f = 1; char ch = getchar();
		for (; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
		for (; ch >= '0' && ch <= '9'; ch = getchar()) x = ((x << 1) + (x << 3) + (ch ^ 48));
		return x * f;
	}
	inl void writ(lli x) {
		if (x < 0) {putchar('-'); x = -x;}
		if (x >= 10) writ(x / 10);
		putchar(x % 10 + '0');
	}
	inl void writln(lli x) {writ(x), putln;}
	inl void writsp(lli x) {writ(x), putsp;}
}
using namespace IO;
mt19937 mrn(time(NULL));
const int iinf = 0x3f3f3f3f;
const lli linf = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1000000007;
const int leb = 233;
const int coe = 2000;
const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
lli qpow(lli a, lli b, lli an = 1) {
    for (; b; b >>= 1, a = a * a % mod) an = (b & 1) ? an * a % mod : an;
    return an;
}

bool mst;
int n, m, K;
int w[2511][2511], bou[11][2];
lli an;
bool men;

int calc(int x1, int y1, int x2, int y2) {
	return (w[x2][y2] + w[x1][y1] - w[x2][y1] - w[x1][y2]);
}

void dfs(int x1, int y1, int x2, int y2) { //(x1, y1)是矩形左下角坐标, (x, y)是矩形右下角坐标
	if (x1 == x2 || y1 == y2) return;
	if (x1 + 1 == x2 && y1 + 1 == y2) return (void)(an += calc(x1, y1, x2, y2) == K);
	if (x2 - x1 > y2 - y1) {
		int mid = x1 + x2 >> 1;
		dfs(x1, y1, mid, y2);
		dfs(mid, y1, x2, y2);
		for (int i = y1; i < y2; i++) {
			bou[0][0] = bou[0][1] = mid;
			for (int k = 1; k <= K + 1; k++) bou[k][0] = x1, bou[k][1] = x2;
			for (int j = i + 1; j <= y2; j++) {
				for (int k = 1; k <= K + 1; k++) {
					for (; calc(bou[k][0], i, mid, j) >= k; bou[k][0]++);
					for (; calc(mid, i, bou[k][1], j) >= k; bou[k][1]--);
				}
				for (int k = 0; k <= K; k++) an = an + 1ll * (bou[k][0] - bou[k + 1][0]) * (bou[K - k + 1][1] - bou[K - k][1]);
			}
		}
	}
	else {
		int mid = y1 + y2 >> 1;
		dfs(x1, y1, x2, mid);
		dfs(x1, mid, x2, y2);
		for (int i = x1; i < x2; i++) {
			bou[0][0] = bou[0][1] = mid;
			for (int k = 1; k <= K + 1; k++) bou[k][0] = y1, bou[k][1] = y2;
			for (int j = i + 1; j <= x2; j++) {
				for (int k = 1; k <= K + 1; k++) {
					for (; calc(i, bou[k][0], j, mid) >= k; bou[k][0]++);
					for (; calc(i, mid, j, bou[k][1]) >= k; bou[k][1]--);
				}
				for (int k = 0; k <= K; k++) an = an + 1ll * (bou[k][0] - bou[k + 1][0]) * (bou[K - k + 1][1] - bou[K - k][1]);
			}
		}
	}
	return;
}

signed main() {
    // tot_memory
    // RS();
	TD();
	cin >> n >> m >> K;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char a;
			cin >> a;
			w[i][j] = a - '0';
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) w[i][j] = w[i][j] + w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
	dfs(0, 0, n, m);
	cout << an;
    // tot_time
    return 0;
}