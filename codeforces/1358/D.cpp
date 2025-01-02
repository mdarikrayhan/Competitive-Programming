#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<list>
#include<cstring>
#include<cstdint>
#include<sstream>
#include<bitset>
#include<string_view>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

// #define pb push_back
#define all(p) begin(p),end(p)
#define rep(ind,sz) for(int (ind) = 0; (ind) < (sz); (ind)++)
#define vi vector<int>
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define pss pair<string,string>
#define ve vector
#define mp make_pair
#define PI 3.14159265358979323846
#define vs ve<string>
#define int long long
#define double long double

using namespace std;

template <class T>
istream& operator >> (istream& in, pair<T, T>& v) { in >> v.first >> v.second; return in; }
template <class T>
istream& operator >> (istream& in, vector<T>& v) { for (auto& e : v) { in >> e; } return in; }

template <class T>
ostream& operator << (ostream& out, const pair<T, T>& v) { out << v.first << " " << v.second; return out; }
template <class T>
ostream& operator << (ostream& out, const vector<T>& v) { for (auto& e : v) { out << e << " "; } out << "\n"; return out; }

void fast() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cout << fixed; cout.precision(10);
}

void precalc() {
}

void solve() {
    int n, x;
    cin >> n >> x;
    vi d(n);
    cin >> d;
    rep(i, n + 2) {
        d.push_back(d[i]);
    }
    vi p(d.size());
    vi pd(d.size());
    rep(i, d.size()) {
        if (i) {
            p[i] = p[i - 1];
            pd[i] = pd[i - 1];
        }
        p[i] += (1 + d[i]) * d[i] / 2;
        pd[i] += d[i];
    }
    int ans = 0;
    rep(i, n) {
        // if (x <= d[i]) {
        //     int f = d[i] - x + 1;
        //     ans = max(ans, (f + d[i]) * x / 2);
        //     continue;
        // }
        int l = i, r = d.size() - 1;
        int pos = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = pd[mid] - (i > 0 ? pd[i - 1] : 0);
            if (val > x) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int res = ((pos > 0 ? p[pos - 1] : 0) - (i > 0 ? p[i - 1] : 0));
        int xx = x - ((pos > 0 ? pd[pos - 1] : 0) - (i > 0 ? pd[i - 1] : 0));
        int ost = min(d[i], d[pos] - xx);
        res -= (1 + ost) * ost / 2;
        xx += ost;
        res += (1 + xx) * xx / 2;
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast(); 
    precalc();
    int t = 1;
    // cin >> t;
    rep(i, t) {
#ifdef LOCAL
        cout << "test case #" << i + 1 << ":\n";
#endif
        solve();
    }
    return 0;
}