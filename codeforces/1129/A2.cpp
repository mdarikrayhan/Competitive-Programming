#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int long long 
#define endl '\n'

void Prework() {

}
const int inf = 1e9;
void Solve() {
    int n, m;cin >> n >> m;
    vector<int> a(m + 1), b(m + 1);
    for (int i = 1;i <= m;i++) cin >> a[i] >> b[i];
    vector<int> cnt(n + 1);
    vector<int> mn(n + 1, n);
    for (int i = 1;i <= m;i++) {
        mn[a[i]] = min(mn[a[i]], (b[i] - a[i] + n) % n);
        cnt[a[i]]++;
    }
    deque<int> q;int now = 1;
    auto nxt = [&](int x) {
        if (x == n) return 1;
        else return x + 1;
        };
    auto calc = [&](int x, int i) {
        return cnt[x] ? (cnt[x] - 1) * n + mn[x] + (x - i + n) % n : 0;
        };
    for (int i = 0;i + 1 < n;i++, now = nxt(now)) {
        while (q.size() && calc(now, 1) >= calc(q.back(), 1)) q.pop_back();
        q.push_back(now);
    }
    vector<int> res(n + 1);
    for (int i = 1;i <= n;i++, now = nxt(now)) {
        while (q.size() && calc(now, i) >= calc(q.back(), i)) q.pop_back();
        q.push_back(now);
        res[i] = calc(q.front(), i);
        if (q.front() == i) q.pop_front();
    }
    for (int i = 1;i <= n;i++) cout << res[i] << " \n"[i == n];

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    Prework();
    while (T--) Solve();
}