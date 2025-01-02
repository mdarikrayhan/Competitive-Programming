#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

#define int long long
// #define double long double
#define endl "\n"

ostream& operator << (ostream& out, pair<int, int> a) {
    out << "| " << a.first << " " << a.second << " |";
    return out;
}

template<typename T>
istream& operator >> (istream& in, vector<T>& a) {
    for (int i = 0; i < a.size(); i++) in >> a[i];
    return in;
}

template<typename T>
ostream& operator << (ostream& out, vector<T>& a) {
    for (int i = 0; i < a.size(); i++) out << a[i] << " ";
    return out;
}

mt19937 rn(228);
int rnd() {return abs((int) rn());}

constexpr int N = 5e6 + 52;
constexpr int mod = 998244353;
constexpr long long inf = 1e18 + 556;
constexpr int T = 100;
constexpr int A = 26;
const double pi = acos(-1);
const double eps = pow(2, -20);

void retarded() {
    int n; cin >> n; vector<int> a(n); cin >> a; vector<int> b = a; sort(b.begin(), b.end()); b.erase(unique(b.begin(), b.end()), b.end()); for (int i = 0; i < n; i++) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin(); int m = b.size(); vector<vector<int>> pos(m + 1); for (int i = 0; i < n; i++) pos[a[i]].push_back(i); vector<int> dp(m, 0); for (int i = 0; i < m; i++) dp[i] = pos[i].size(); for (int i = 1; i < m; i++) {if (pos[i - 1].back() < pos[i].front()) {dp[i] += dp[i - 1];} dp[i] = max(dp[i], pos[i].size() + upper_bound(pos[i - 1].begin(), pos[i - 1].end(), pos[i].front()) - pos[i - 1].begin());} int ans = n; for (int i = 0; i < m; i++) ans = min(ans, n - dp[i] - (pos[i + 1].end() - upper_bound(pos[i + 1].begin(), pos[i + 1].end(), pos[i].back()))); for (int i = 0; i < n; i++) {ans = min(ans, n - (upper_bound(pos[a[i]].begin(), pos[a[i]].end(), i) - pos[a[i]].begin() + pos[a[i] + 1].end() - upper_bound(pos[a[i] + 1].begin(), pos[a[i] + 1].end(), i)));} cout << ans << endl;
}

signed main() {
    int tests = 1;

#ifdef LOCALIC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#endif
    cin >> tests;

    while (tests --> 0) retarded();
}