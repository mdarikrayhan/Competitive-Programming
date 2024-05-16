#include <bits/stdc++.h>
using namespace std;

#define e_b emplace_back
#define ins insert
#define all(x) x.begin(), x.end()
#define l first
#define r second
#define pii pair <int, int>
#define INF 1e9
#define int long long

const int mod = 1e9 + 7;
const int p = 211;

void solve() {
    int n, k;
    cin >> n >> k;
    map <int, int> cnt;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector <pii> keys;
    for (auto [x, y] : cnt) {
        keys.e_b(x, y);
    }
    int left = INF, right = -1;
    int bestl = -1, bestr = -1;
    for (int i = 0; i < keys.size(); ++i) {
        if (keys[i].r < k || (i > 0 && keys[i].l - keys[i - 1].l != 1)) {
            if (right - left >= bestr - bestl && left < INF && right > -1) {
                bestl = left;
                bestr = right;
            }
            left = INF;
            right = -1;
        }
        if (keys[i].r >= k && keys[i].l < left) {
            left = keys[i].l;
        }
        if (keys[i].r >= k && keys[i].l > right) {
            right = keys[i].l;
        }
    }
    if (right - left >= bestr - bestl && left < INF && right > -1) {
        bestl = left;
        bestr = right;
    }
    if (bestl == -1 || bestr == -1) {
        cout << -1 << '\n';
    } else {
        cout << bestl << ' ' << bestr << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}