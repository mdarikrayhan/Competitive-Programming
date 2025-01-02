#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define fst first
#define snd second
#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e
#define LSOne(S) ((S) & -(S))
#define MSOne(S) (1ull << (63 - __builtin_clzll(S)))
#define fastio ios_base::sync_with_stdio(0); \
               cin.tie(0); \
               cout.tie(0)

const vii dir4 { { 1, 0 }, { -1,0 }, { 0,1 }, { 0,-1 }
};

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

vector<int> rmq(const vector<int>& vec) {
    int n = vec.size();
    if (n == 0) { return vector<int>(); }

    vector<int> max_prefix(n);
    max_prefix[0] = vec[0];

    for (int i = 1; i < n; i++) max_prefix[i] = max(max_prefix[i - 1], vec[i]);
    return max_prefix;
}

vi paring;
auto solve() {
    string c, rev = "";
    cin >> c;
    for (int i = c.size() - 1; i >= 0; i--) {
        rev += c[i];
        paring.push_back(i);
    }

    int k, ans = 0;
    cin >> k;
    while (k--) {
        string e;
        cin >> e;

        if (e.size() == 1) continue;

        string ce = e + '#' + c;
        vi ys = z_function(ce);

        reverse(all(e));
        ce = e + '#' + rev;
        vi xs = z_function(ce);

        vi ts(xs);
        for (int i = 0; i < e.size() + 1; i++) ts[i] = -1;
        vi ps = rmq(ts);
        for (int i = e.size() + 1; i < ys.size(); i++) {
            int p = i - (e.size() + 1) + ys[i] - 1;
            int y = e.size() - ys[i];

            if (p + y < 0 or p + y >= paring.size()) continue;

            int tmp = ps[paring[p + y] + e.size() + 1];
            if (tmp >= y) {
                ans++;
                break;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    fastio;

    ll t = 1;
    //cin >> t;

    while (t--) solve();

    return 0;
}