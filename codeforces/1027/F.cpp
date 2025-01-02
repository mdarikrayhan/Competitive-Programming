#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << ": " << (x) << endl
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define irep(i, a, b) for (int i = a; i >= (int)(b); i--)

#define inbounds(x, l, r) ((l) <= (x) && (x) <= (r))
#define L0(res...) [&](){ return res; }
#define L1(res...) [&](auto const & x){ return res; }
#define L2(res...) [&](auto const & x, auto const& y){ return res; }

template<class T> inline void chmin(T & a, const T b){ if (a > b) a = b; }
template<class T> inline void chmax(T & a, const T b){ if (a < b) a = b; }

const int oo = 0x3f3f3f3f3f3f3f3f;

struct OnlineMatching {
    int n = 0, m = 0;
    vector<int> vis, match, dist;
    vector<vector<int>> g;
	vector<int> last;
	int t = 0;

    OnlineMatching(int n_, int m_) : n(n_), m(m_),
		vis(n, 0), match(m, -1), dist(n, n+5), g(n), last(n, -1)
		{}

    void add(int a, int b) {
        g[a].pb(b);
    }

    bool kuhn(int a) {
		vis[a] = t;
		for(const int b: g[a]) {
		    int c = match[b];
		    if (c == -1) {
				match[b] = a;
				return true;
		    }
		    if (last[c] != t || (dist[a] + 1 < dist[c])) 
				dist[c] = dist[a] + 1, last[c] = t;
		}
		for (const int b: g[a]) {
			int c = match[b];
			if (dist[a] + 1 == dist[c] && vis[c] != t && kuhn(c)) {
				match[b] = a;
				return true;
			}
		}
        return false;
    }
	bool can_match(int a) {
		t++;
		last[a] = t;
		dist[a] = 0;
		return kuhn(a);
	}
};


struct CC {
	vector<int> v;
	CC(vector<int> & a) : v(a) {
		sort(all(v));
		v.erase(unique(all(v)), v.end());
	}
	int get(int x) {
		return lower_bound(all(v), x) - v.begin();
	}
};

void solve() {
	int n; cin >> n;
	vector<int> day1(n), day2(n);
	vector<int> days(2*n);
	rep(i, 0, n) {
		cin >> day1[i];
		cin >> day2[i];
		days[i] = day1[i];
		days[n+i] = day2[i];
	}
	CC cc(days);
	OnlineMatching matching(cc.v.size(), n);
	rep(i, 0, n) {
		matching.add(cc.get(day1[i]), i);
		matching.add(cc.get(day2[i]), i);
	}
	int ans = 0;
	rep(i, 0, cc.v.size()) {
		if (matching.can_match(i)) ans++;

		if (ans == n) {
			cout << cc.v[i] << endl;
			return;
		}
	}

	cout << -1 << endl;

}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}

