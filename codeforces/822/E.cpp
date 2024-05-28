#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;

void Tamora() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

}

const ll mod = 1e9 + 7, inf = 1e9 + 5, N = 4e5 + 5, M = 1e4 + 7, LG = 25, P1 = 37, P2 = 31;

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
};

void maximize(int &x, int y) {
    x = max(x, y);
}

void solve() {
    int n, m, x;
    string s, t;
    cin >> n >> s;
    cin >> m >> t;
    cin >> x;
    s = s + '#' + t;
    SuffixArray suffixArray(s);
    suffixArray.preLcp();
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= x; j++) {
            if (j + 1 <= x) { // pick if can
                int lcp = suffixArray.queryLcp(i, n + dp[i][j] + 1);
                maximize(dp[i + lcp][j + 1], dp[i][j] + lcp);
            }
            // leave
            maximize(dp[i + 1][j], dp[i][j]);
        }
    int ans = 0;
    for (int j = 0; j <= x; j++)
        maximize(ans, dp[n][j]);
    cout << (ans == m ? "YES" : "NO") << endl;
}

int main() {
    Tamora();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
    return 0;
}


