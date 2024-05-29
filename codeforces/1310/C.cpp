#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define fi first
#define se second
#define pp push_back
#define all(x) (x).begin(), (x).end()
#define Ones(n) __builtin_popcount(n)
#define endl '\n'
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
//#define int long long
#define debug(x) cout << (#x) << " = " << x << endl

void Gamal() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef Clion
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};

const double EPS = 1e-9;
const ll OO = 0X3F3F3F3F3F3F3F3F;
const int N = 2e5 + 5, INF = INT_MAX, MOD = 1e9 + 7, LOG = 20;

struct SuffixArray {
    string S;
    // sa is the suffix array with the empty suffix being sa[0]
    // lcp[i] holds the lcp between sa[i], sa[i - 1]
    vector<int> logs, sa, lcp, rank;
    vector<vector<int>> table;

    SuffixArray() {};

    SuffixArray(string &s, int lim = 256) {
        S = s;
        int n = s.size() + 1, k = 0, a, b;
        vector<int> c(s.begin(), s.end() + 1), tmp(n), frq(max(n, lim));
        c.back() = 0; //0 is less than any character
        sa = lcp = rank = tmp, iota(sa.begin(), sa.end(), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(tmp.begin(), tmp.end(), n - j);
            for (int i = 0; i < n; i++) {
                if (sa[i] >= j)
                    tmp[p++] = sa[i] - j;
            }

            fill(frq.begin(), frq.end(), 0);

            for (int i = 0; i < n; i++) frq[c[i]]++;
            for (int i = 1; i < lim; i++) frq[i] += frq[i - 1];
            for (int i = n; i--;) sa[--frq[c[tmp[i]]]] = tmp[i];

            swap(c, tmp), p = 1, c[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                a = sa[i - 1], b = sa[i], c[b] = (tmp[a] == tmp[b] && tmp[a + j] == tmp[b + j]) ? p - 1 : p++;
        }

        for (int i = 1; i < n; i++) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k &&k--, j = sa[rank[i] - 1];
                    s[i + k] == s[j + k];
        k++);
    }

    void preLcp() {
        int n = S.size() + 1;
        logs = vector<int>(n + 5);
        for (int i = 2; i < n + 5; ++i) {
            logs[i] = logs[i / 2] + 1;
        }
        table = vector<vector<int>>(n, vector<int>(20));
        for (int i = 0; i < n; ++i) {
            table[i][0] = lcp[i];
        }

        for (int j = 1; j <= logs[n]; ++j) {
            for (int i = 0; i <= n - (1 << j); ++i) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int queryLcp(int i, int j) {
        if (i == j)return (int) S.size() - i;
        i = rank[i], j = rank[j];
        if (i == j)return (int) S.size() - sa[i];
        if (i > j)
            swap(i, j);
        i++;
        int len = logs[j - i + 1];
        return min(table[i][len], table[j - (1 << len) + 1][len]);
    }

    ll getCnt() {
        ll cnt = 0;
        for (int i = 1; i < S.size() + 1; ++i) {
            cnt += S.size() - sa[i] - lcp[i];
        }
        return cnt;
    }

    pii getKth(int x) {
        for (int i = 1; i < S.size() + 1; ++i) {
            int cnt = S.size() - sa[i] - lcp[i];
            if (cnt > x) {
                return {sa[i], x + lcp[i] + 1};
            }
            x -= cnt;
        }
        assert(false);
    };
};

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    SuffixArray sa(s);
    sa.preLcp();

    int cnt = sa.getCnt();

    int l = 0, r = cnt - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        pii cur = sa.getKth(mid);
        int idx = cur.first;
        int len = cur.second;
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; --i) {
            int lc = sa.queryLcp(idx, i);
            bool skip = false;
            if (lc >= len) {
                lc = len;
            } else {
                if ((i + lc >= n || s[i + lc] < s[idx + lc]))skip = true;
                if(!skip)lc++;
            }
            if (!skip) {
                for (int j = 1; j <= m; ++j) {
                    dp[i][j] += dp[i + lc][j - 1];
                }
            }
            if (i) {
                for (int j = 0; j <= m; ++j) {
                    dp[i][j] += dp[i + 1][j];
                    dp[i][j] = min(dp[i][j], k);
                }
            }
        }
        if (dp[0][m] >= k) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    pii x = sa.getKth(ans);
//    cout << ans << endl;
    cout << s.substr(x.first, x.second) << endl;
}


signed main() {
    Gamal();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
	   		 		  		 	 			  				 	 	