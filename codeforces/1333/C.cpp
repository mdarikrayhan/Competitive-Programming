#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll
const ll inf = 1e9 + 7;

void build(int v, int l, int r, vector<int> &a, vector<int> &st) {
    if (l + 1 == r) {
        st[v] = a[l];
        return;
    }
    build(v * 2 + 1, l, (l + r) / 2, a, st);
    build(v * 2 + 2, (l + r) / 2, r, a, st);
    st[v] = max(st[v * 2 + 1], st[v * 2 + 2]);
}

int max(int v, int l, int r, int ql, int qr, vector<int> &st) {
    if (l >= qr || r <= ql)
        return 0;
    if (l >= ql && r <= qr)
        return st[v];
    return max(
            max(v * 2 + 1, l, (l + r) / 2, ql, qr, st),
            max(v * 2 + 2, (l + r) / 2, r, ql, qr, st)
    );
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a)
        cin >> i;
    vector<int> pref(n + 1), ref(n + 1), st((n + 1) * 4);
    unordered_map<int, int> last;
    last[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
        if (last.contains(pref[i]))
            ref[i] = last[pref[i]] + 1;
        else
            ref[i] = 0;
        last[pref[i]] = i;
    }
    build(0, 0, n + 1, ref, st);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = n - i + 2;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (max(0, 0, n + 1, i, i + mid, st) < i)
                l = mid;
            else
                r = mid;
        }
        ans += l;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();
}