// LUOGU_RID: 159989901
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000005;
int n, k, pre, trie[N * 30][2], tot = 1, cnt[N * 30];
ll ans;
void insert(int x) {
	int now = 1;
	for (int i = 30; ~i; --i) {
		int c = x >> i & 1;
		if (!trie[now][c]) trie[now][c] = ++tot;
		now = trie[now][c];
		++cnt[now];
	}
}
int query(int x, int y) {
	int now = 1, res = 0;
	for (int i = 30; ~i; --i) {
		int c1 = x >> i & 1, c2 = y >> i & 1;
		if (c2) now = trie[now][c1 ^ 1];
		else {
			res += cnt[trie[now][c1 ^ 1]];
			now = trie[now][c1];
		} 
	}
	res += cnt[now];
	return res;
} 
int main() {
	cin >> n >> k;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		insert(pre), pre ^= x;
		ans += query(pre, k);
	}
	cout << ans;
}