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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


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
const int MOD = 998244353;
const int N = 5e5 + 5;

inline int mul(int a, int b) {
    return (a * 1LL * b) % MOD;
}


inline int sum(int a, int b) {
    return (a + b) % MOD;
}


inline void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '@') {
            int j = i - 1;
            int cnt = 0;
            while (j >= 0 && s[j] != '@' && s[j] != '.') {
                if (isalpha(s[j])) cnt++;
                j--;
            }
            j = i + 1;
            bool ok = true;
            int site = 0;
            while (j < s.size() && s[j] != '.') {
                if (!isalpha(s[j]) && !isdigit(s[j])) {
                    ok = false;
                    break;
                }
                j++;
                site++;
            }
            j++;
            int d = 0;
            if (!ok || !site) {
                d = 0;
            } else {
                while (j < s.size() && isalpha(s[j])) {
                    j++;
                    d++;
                }
            }
            ans += cnt * d;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    GLHF;
    int tests = 1;
    while (tests--) {
        solve();
    }
    return 0;
}