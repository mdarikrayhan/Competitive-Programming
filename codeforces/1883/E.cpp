#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#pragma GCC optimize("O3")

using namespace std;
using namespace __gnu_pbds;

//clock_t tStart = clock(); cout << "Time taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#define int long long
#define GLHF ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
const double EPS = 1e-6;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


template<typename T1, typename T2>
inline istream &operator>>(istream &in, pair<T1, T2> &p) {
    return in >> p.first >> p.second;
}

template<typename T1, typename T2>
inline ostream &operator<<(ostream &out, pair<T1, T2> &p) {
    return out << p.first << ' ' << p.second;
}

template<typename T>
inline istream &operator>>(istream &in, vector<T> &v) {
    for (auto & i: v) {
        in >> i;
    }
    return in;
}

template<typename T>
inline ostream &operator<<(ostream &out, vector<T> &v) {
    for (auto &i : v) {
        out << i << ' ';
    }
    return out;
}

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int ans = 0;
    vector<int> x(n, 0);
    for (int i = 1; i < n; ++i) {
        x[i] = x[i - 1];
        if (a[i - 1] <= a[i]) {
            int p = 2;
            while (a[i - 1] * p <= a[i] && x[i]) {
                p *= 2;
                x[i]--;
            }
        } else {
            int p = 1;
            while (a[i] * p < a[i - 1]) {
                p *= 2;
                x[i]++;
            }
        }
        ans += x[i];
    }
    cout << ans << '\n';
}

int32_t main() {
    GLHF;
    int tests = 1;
    cin >> tests;
    while (tests--) {
        solve();
    }
    return 0;
}