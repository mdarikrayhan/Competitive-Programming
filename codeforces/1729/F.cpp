#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <queue>
#include <cstdint>
#include <random>
#include <stack>
#include <random>
#include<memory.h>
#include<fstream>
#include<list>

#define mod 1000000007

using namespace std;

typedef pair<int, int> ipair;

const int MAXSZ = 200200;
const int INF = 2e9;

inline int add(int a, int b) {
	return (a + b >= 9 ? a + b - 9 : a + b);
}

inline int sub(int a, int b) {
	return (a < b ? a + 9 - b : a - b);
}

inline int mul(int a, int b) {
	return a * b % 9;
}

int sz, n, m;
string s;
int ps[MAXSZ];
vector<int> D[9];

void build() {
	sz = s.size();
	for (int md = 0; md < 9; ++md)
		D[md].clear();
	for (int i = 0; i < sz; ++i)
		ps[i + 1] = ps[i] + (s[i] - '0');
	for (int i = 0; i + n <= sz; ++i)
		D[(ps[i + n] - ps[i]) % 9].push_back(i);
}

ipair solve(int l, int r, int k) {
	int x = (ps[r] - ps[l]) % 9;
	ipair ans{ INF, INF };
	for (int a = 0; a < 9; ++a) {
		int b = sub(k, mul(a, x));
		if (D[a].empty() || D[b].empty()) continue;
		if (a != b)
			ans = min(ans, make_pair(D[a].front(), D[b].front()));
		else if (D[a].size() >= 2)
			ans = min(ans, make_pair(D[a].front(), D[a][1]));
	}
	if (ans == make_pair(INF, INF))
		return { -2, -2 };
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> s >> n >> m;
		build();
		for (int i = 0; i < m; ++i) {
			int l, r, k; cin >> l >> r >> k, --l;
			ipair ans = solve(l, r, k);
			cout << ans.first + 1 << ' ' << ans.second + 1 << endl << endl;
		}
	}
}