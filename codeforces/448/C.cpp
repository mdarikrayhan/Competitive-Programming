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
// #define int long long
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

vi a;

int go(int l, int r) {
    if (l > r) return 0;
    if (r == l) return 1;
    int mn = 1e9 + 100, cnt = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] < mn) {
            mn = a[i];
            cnt = 0;
        }
        if (a[i] == mn) cnt++;
    }
    if (mn > r - l + 1) return r - l + 1;
    for (int i = l; i <= r; i++) {
        a[i] -= mn;
    }
    int last = l;
    int ans = mn;
    for (int i = l; i <= r; i++) {
        if (a[i] == 0) {
            ans += go(last, i - 1);
            last = i + 1;
        }
    }
    ans += go(last, r);
    return min(ans, r - l + 1);
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    cin >> a;
    cout << go(0, n - 1);
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