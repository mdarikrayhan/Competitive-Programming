// https://codeforces.com/contest/1846/problem/E2
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 1e6 + 5, inf = 1e18;
int n;
set<int> lis;

int check(int i, int k) {
    int cnt = 0;
    while (i != 1) {
        if (i % k) return -1;
        i /= k;
        cnt++;
    }
    return cnt;
}

__int128 power(int i, int j) {
    __int128 res = 1;
    while (j) {
        if (j&1) res *= i;
        i *= i;
        j >>= 1;
    }
    return res;
}

void solve() {
    cin >> n;
    bool ok = lis.find(n) != lis.end();
    if (ok) cout << "YES\n";
    else {
        int sq = sqrt(4 * n - 3);
        if (sq * sq == 4 * n - 3) {
            if (sq != -1 && sq&1 && (sq - 1) / 2 > 1) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int k = 2; k <= 1e6; ++k) {
        int p = 1 + k, c = k * k;
        for (int j = 3; j <= 63; ++j) {
            p += c;
            if (p > 1e18) break;
            lis.insert(p);
            if (c > 1e18 / k) break;
            c *= k;
        }
    }

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
