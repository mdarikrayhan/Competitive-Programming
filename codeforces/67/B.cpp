// LUOGU_RID: 156383129
#include <iostream>
#include <cassert>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <ctime>
#include <map>
#include <stack>
using namespace std;
#define int long long
#define pii pair<int, int>
#define eb emplace_back
#define F first
#define S second
#define test(x) cout << "Test: " << x << '\n'
#define debug puts("qwq")
#define open(x) fresopen(#x".in", "r", stdin);fresopen(#x".out", "w", stdout);
#define close fclose(stdin);fclose(stdout);
namespace FastIO {
	template <typename T = int>
	inline T read() {
		T s = 0, w = 1;
		char c = getchar();
		while (!isdigit(c)) {
			if (c == '-') w = -1;
			c = getchar();
		}
		while (isdigit(c)) s = (s << 1) + (s << 3) + (c ^ 48), c = getchar();
		return s * w;
	}
	template <typename T>
	inline void read(T &s) {
		s = 0;
		int w = 1;
		char c = getchar();
		while (!isdigit(c)) {
			if (c == '-') w = -1;
			c = getchar();
		}
		while (isdigit(c)) s = (s << 1) + (s << 3) + (c ^ 48), c = getchar();
		s = s * w;
	}
	template <typename T, typename... Arp> inline void read(T &x, Arp &...arp) {
		read(x), read(arp...);
	}
	template <typename T>
	inline void write(T x, char ch) {
		if (x < 0) x = -x, putchar('-');
		static char stk[25];
		int top = 0;
		do {
			stk[top++] = x % 10 + '0', x /= 10;
		} while (x);
		while (top) putchar(stk[--top]);
		putchar(ch);
		return;
	}
	template <typename T>
	inline void smax(T &x, T y) {
		if (x < y) x = y;
	}
	template <typename T>
	inline void smin(T &x, T y) {
		if (x > y) x = y;
	}
	void quit() {
		exit(0);
	}
} using namespace FastIO;
int b[1005];
bool vis[2005];
signed main() {
	int n, k;
	read(n, k);
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int j = 1; j <= n; j++) {
		int qwq = 0;
		for (int i = k + 1; i <= n; i++) qwq += vis[i];
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && qwq == b[i]) {
				cout << i << " ";
				vis[i] = 1;
				break;
			}
			qwq -= vis[i + k];
		}
	}
	return 0;
}