#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Gondozu ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector <pair<int, int>>;
using vvi = vector <vector<int>>;

const int OO = 1e9 + 5;
const int N = 2e5 + 5;

struct SegTree {
    vector<vi> tree;
    int n;
    const vi IDN = {};

    void build(int inputN, vector<int>& a) {
        n = inputN;
        if (__builtin_popcount(n) != 1)
            n = 1 << (__lg(n) + 1);
        tree.resize(n << 1, IDN);
        for (int i = 0; i < inputN; i++)
            tree[i + n] = {a[i]};
        for (int i = n - 1; i >= 1; i--){
            tree[i].resize(tree[i << 1].size() + tree[i << 1 | 1].size());
            merge(all(tree[i << 1]),all(tree[i << 1 | 1]), tree[i].begin());
        }
    }

    int query(int ql, int qr, int val, int k, int sl, int sr) {
        if (qr < sl || sr < ql || ql > qr) return 0;
        if (ql <= sl && qr >= sr) return upper_bound(all(tree[k]), val) - lower_bound(all(tree[k]), val);

        int mid = (sl + sr) / 2;
        int left = query(ql, qr, val, k << 1, sl, mid);
        int right = query(ql, qr, val, k << 1 | 1, mid + 1, sr);
        return left + right;
    }

    int query(int ql, int qr, int val){
        return query(ql, qr, val, 1, 0, n-1);
    }
};

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
//        if (i == j) return (int) S.size() - i;
//        i = rank[i], j = rank[j];
        if (i == j)return (int) S.size() - sa[i];
        if (i > j)
            swap(i, j);
        i++;
        int len = logs[j - i + 1];
        return min(table[i][len], table[j - (1 << len) + 1][len]);
    }
};

void TC()
{
    string s;
    int n;
    cin >> n >> s;
    s = "#" + s; n++;
    SuffixArray sa(s);


    vi pref(n);
    for (int i = 1; i < n; ++i)
        pref[i] = pref[i-1] + (s[i] == '(' ? 1 : -1);

    stack<int> st; st.push(n-1);
    vi a5er(n);
    for (int i = n-1; ~i ; --i) {
        while (!st.empty() && pref[st.top()] >= pref[i]) st.pop();
        a5er[i+1] = st.empty() ? n-1 : st.top()-1;
        st.push(i);
    }

    SegTree tree;
    tree.build(n, pref);

    vi lcp = sa.lcp;
    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans += tree.query(sa.sa[i]+sa.lcp[i], a5er[sa.sa[i]], pref[sa.sa[i]-1]);
    }
    cout << ans;
}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin); freopen("output.out", "w", stdout);
#endif
    Gondozu
    int t = 1;
//    cin >> t;
    while (t--) {
        TC();
        cout << '\n';
    }
    return 0;
}
 	 	  	  		   	   	 	 				 	 		