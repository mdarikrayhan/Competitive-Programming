#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <iomanip>
#include <ctime>
#include <random>
#include <numeric>
#include <climits>

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
mt19937 engine;
const int INF = 1e9 + 1;
const ll LINF = 2 * 1e18;
int MOD = 1e9 + 7;
int BASE = 257;
ld PI = 3.14159265358979323846;

void make_good(string& s) {
	if (s.size() < 20)
		return;
	string tmp = "";
	for (int i = 0; i < 10; i++)
		tmp.push_back(s[i]);
	for (int i = s.size() - 10; i < s.size(); i++)
		tmp.push_back(s[i]);
	s = tmp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	engine.seed(time(nullptr));

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<vector<set<string>>> v(n, vector<set<string>> (10));
	vector<string> ss;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;

		for (int j = 0; j < a.size(); j++) {
			string cur = "";
			for (int t = 0; t < 9; t++) {
				if (j + t >= a.size())
					break;
				cur.push_back(a[j + t]);
				v[i][t].insert(cur);
			}
		}

		make_good(a);
		ss.push_back(a);
	}

	int m;
	cin >> m;

	while (m--) {
		int ind1, ind2;
		cin >> ind1 >> ind2;
		ind1--; ind2--;
		string ns = ss[ind1] + ss[ind2];
		vector<set<string>> cur(10);
		int ans = 0;
		for (int i = 0; i < 9; i++) {
			cur[i] = v[ind1][i];
			for (auto& j : v[ind2][i])
				cur[i].insert(j);
		}
		for (int j = max(0, int(ss[ind1].size()) - 9); j < min(int(ss[ind1].size()) + 9, int(ns.size())); j++) {
			string curt = "";
			for (int t = 0; t < 9; t++) {
				if (j + t >= min(int(ss[ind1].size()) + 9, int(ns.size())))
					break;
				curt.push_back(ns[j + t]);
				cur[t].insert(curt);
				if (cur[t].size() == (1 << (t + 1))) {
					ans = max(ans, t + 1);
				}
			}
		}
		make_good(ns);
		ss.push_back(ns);
		v.push_back(cur);
		cout << ans << '\n';
	}

}
