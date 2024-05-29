#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, q;
ll c[N], r[N], maxn;
ll f[N], h[N], sum[N];
struct Node {
    int l, r;
    ll k, b;
} t[N << 5];
int rt[N], tot;
vector<int> idx[N];
void pushup(int p) {
    t[p].k = t[t[p].l].k + t[t[p].r].k;
    t[p].b = t[t[p].l].b + t[t[p].r].b;
}
void build(int& p, int L, int R) {
    p = ++tot;
    if (L == R) {
        t[p] = {0, 0, r[L], 0};
        return;
    }
    int mid = (L + R) >> 1;
    build(t[p].l, L, mid);
    build(t[p].r, mid + 1, R);
    pushup(p);
}
void update(int rt, int& p, int l, int r, int x, ll k, ll b) {
    p = ++tot;
    t[p] = t[rt];
    if (l == r) {
        t[p] = {0, 0, k, b};
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        update(t[rt].l, t[p].l, l, mid, x, k, b);
    else
        update(t[rt].r, t[p].r, mid + 1, r, x, k, b);
    pushup(p);
}
array<ll, 2> query(int p, int l, int r, int x, int y) {
    if (!p)
        return {0, 0};
    if (x <= l && r <= y)
        return {t[p].k, t[p].b};
    int mid = (l + r) >> 1;
    array<ll, 2> ans = {0, 0};
    if (x <= mid)
        ans = query(t[p].l, l, mid, x, y);
    if (y > mid) {
        auto tmp = query(t[p].r, mid + 1, r, x, y);
        ans[0] = ans[0] + tmp[0];
        ans[1] = ans[1] + tmp[1];
    }
    return ans;
}
int find(int p, int l, int r, int x, ll& sum, ll tim) {
    if (r < x)
        return -1;
    if (x <= l) {
        ll res = tim * t[p].k + t[p].b;
        if (res <= sum) {
            sum -= res;
            return -1;
        }
        if (l == r)
            return l;
    }
    int mid = (l + r) >> 1;
    int pos = find(t[p].l, l, mid, x, sum, tim);
    if (pos != -1)
        return pos;
    return find(t[p].r, mid + 1, r, x, sum, tim);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> r[i];
        if (c[i] / r[i] + 1 < 2e5 + 1)
            idx[c[i] / r[i] + 1].push_back(i);
        sum[i] = sum[i - 1] + c[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> f[i] >> h[i];
        maxn = max(maxn, f[i]);
    }
    build(rt[1], 1, n);
    for (int i = 2; i <= maxn; i++) {
        rt[i] = rt[i - 1];
        for (auto x : idx[i])
            update(rt[i], rt[i], 1, n, x, 0, c[x]);
    }
    stack<array<ll, 5>> s;
    s.push({1, n, 2, 0, 0});
    ll totsum = 0;
    for (int i = 1; i <= q; i++) {
        ll tim = f[i];
        ll res = h[i];
        while (true) {
            auto [L, R, type, cur, in] = s.top();
            s.pop();
            ll len = R - L + 1;
            if (type == 0) {
                auto tmp = query(rt[tim - in], 1, n, L, R);
                ll ans = (tim - in) * tmp[0] + tmp[1];
                if (ans > res) {
                    ll val = res;
                    int pos = find(rt[tim - in], 1, n, L, val, tim - in);
                    if (pos + 1 <= R)
                        s.push({pos + 1, R, 0, 0, in + pos - L + 1});
                    val = min(((tim - in) * r[pos]), (ll)c[pos]) - val;
                    s.push({pos, pos, 1, val, tim + pos - L});
                    if (pos - 1 >= 1)
                        s.push({1, pos - 1, 0, 0, f[i]});
                    break;
                } else {
                    res -= ans;
                    if (R == n) {
                        s.push({1, n, 0, 0, f[i]});
                        totsum += res;
                        break;
                    }
                }
            } else if (type == 1) {
                cur = min(cur + (ll)(tim - in) * r[L], (ll)c[L]);
                if (res < cur) {
                    s.push({L, L, 1, cur - res, f[i] + L - 1});
                    if (L > 1)
                        s.push({1, L - 1, 0, 0, f[i]});
                    break;
                } else if (res == cur) {
                    s.push({1, L, 0, 0, f[i]});
                    break;
                } else {
                    res -= cur;
                    if (L == n) {
                        s.push({1, n, 0, 0, f[i]});
                        totsum += res;
                        break;
                    }
                }
            } else {
                int l = L, r = R, mid, pos = L;
                if (sum[R] - sum[L - 1] <= res) {
                    totsum += res - (sum[R] - sum[L - 1]);
                    s.push({1, n, 0, 0, f[i]});
                    break;
                }
                while (l <= r) {
                    mid = (l + r) >> 1;
                    if (sum[mid] - sum[L - 1] > res) {
                        pos = mid;
                        r = mid - 1;
                    } else
                        l = mid + 1;
                }
                if (pos + 1 <= R)
                    s.push({pos + 1, R, 2, 0, 0});
                ll val = sum[pos] - sum[L - 1] - res;
                s.push({pos, pos, 1, val, f[i] + pos - 1});
                if (pos - 1 >= 1)
                    s.push({1, pos - 1, 0, 0, f[i]});
                break;
            }
            tim += R - L + 1;
        }
    }
    cout << totsum << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
