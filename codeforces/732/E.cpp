#pragma warning (disable:4998)
#pragma warning (disable:4996)

#include <bits/stdc++.h>
#include <cassert>

const int inf = 2e9;
const long long ill = 4e18;
const long long mod = 1e9 + 7;
const long double eps = 1e-6;

//#define int long long
#define pii pair<int, int>
#define tui tuple<int, int, ll>
typedef long long ll;
typedef long double ld;

using namespace std;




void solve() {
	int n, m;
	cin >> n>>m;
	vector<pii> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first;
		p[i].second = i;
	}
	vector<pii> s(m);
	for (int i = 0; i < m; i++) {
		cin >> s[i].first;
		s[i].second = i;
	}
	vector<int> used(n, -1);
	vector<int> useds(m,-1);
	vector<int> adap(m);
	int c = 0;
	int u = 0;
	sort(p.begin(), p.end());
	sort(s.begin(), s.end());
	int ptr = 0;
	for (int lo = 0; lo <= 30; lo++) {
		//cout << "\titeration " << lo << '\n';
		if (lo)
			for (int i = 0; i < m; i++)
				s[i].first = ceil(s[i].first / 2.);
		int ptr = 0;
		for (int i = 0; i < n; i++) {
			while (ptr < m && (s[ptr].first < p[i].first || useds[s[ptr].second]!=-1))
				ptr++;
			if(ptr<m)
				if (s[ptr].first == p[i].first && useds[s[ptr].second]==-1 && used[p[i].second]==-1) {
					c++;
					u += lo;
					//cout << "connecting socket " << s[ptr].second << ' ' << " power " << s[ptr].first << " and computer " << p[i].second << " power " << p[i].first << '\n';
					adap[s[ptr].second] = lo;
					useds[s[ptr].second] = p[i].second;
					used[p[i].second] = s[ptr].second;
				}
		}
	}
	cout << c << ' ' << u << '\n';
	for (int i = 0; i < m; i++)
		cout << adap[i] << ' ';
	cout << '\n';
	for (int i = 0; i < n; i++)
		cout << used[i] + 1 << ' ';
	cout << '\n';
}


signed main() {
	//freopen("snakes.in", "r", stdin);
	//freopen("snakes.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	while (t--)
		solve();


}