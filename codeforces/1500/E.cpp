#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const int M = 4e5 + 5;
int n, Q, m;
struct Query {
    int opt, id;
    ll x;
} q[N];
vector<ll> val;
ll s[N], id[N];
int getid(ll x) {
    return lower_bound(val.begin(), val.end(), x) - val.begin() + 1;
}
struct Node {
    ll sum, cnt, l, r;
} t[M << 2];
void pushup(int p) {
    t[p].cnt = t[p << 1].cnt + t[p << 1 | 1].cnt;
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
    t[p].l = t[p << 1].l + t[p << 1 | 1].cnt * t[p << 1].sum + t[p << 1 | 1].l;
    t[p].r = t[p << 1 | 1].r + t[p << 1].cnt * t[p << 1 | 1].sum + t[p << 1].r;
}
void update(int p, int l, int r, int x, ll val) {
    if (l == r) {
        t[p].cnt += (val < 0 ? -1 : 1);
        t[p].sum += val;
        t[p].l += val;
        t[p].r += val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        update(p << 1, l, mid, x, val);
    else
        update(p << 1 | 1, mid + 1, r, x, val);
    pushup(p);
    // cout << p << " " << l << " " << r << "\n";
    // cout << t[p].cnt << " " << t[p].sum << " " << t[p].l << " " << t[p].r << "\n";
}
ll query_l(int p, int k) {
    if (t[p].cnt <= k)
        return t[p].sum;
    ll ans = query_l(p << 1, k);
    if (k > t[p << 1].cnt)
        ans += query_l(p << 1 | 1, k - t[p << 1].cnt);
    return ans;
}
ll query_r(int p, int k) {
    if (t[p].cnt <= k)
        return t[p].sum;
    ll ans = query_r(p << 1 | 1, k);
    if (k > t[p << 1 | 1].cnt)
        ans += query_r(p << 1, k - t[p << 1 | 1].cnt);
    return ans;
}
ll query_sl(int p, int k) {
    if (t[p].cnt <= k)
        return t[p].l;
    ll ans = query_sl(p << 1, k);
    if (k > t[p << 1].cnt) {
        ans += (k - t[p << 1].cnt) * t[p << 1].sum;
        ans += query_sl(p << 1 | 1, k - t[p << 1].cnt);
    }
    return ans;
}
ll query_sr(int p, int k) {
    if (t[p].cnt <= k)
        return t[p].r;
    ll ans = query_sr(p << 1 | 1, k);
    if (k > t[p << 1 | 1].cnt) {
        ans += (k - t[p << 1 | 1].cnt) * t[p << 1 | 1].sum;
        ans += query_sr(p << 1, k - t[p << 1 | 1].cnt);
    }
    return ans;
}
ll f(int x) {
    return (query_r(1, x) - query_l(1, x + 1));
}
ll query() {
    if (n <= 1)
        return 0;
    int pl = 1, pr = n - 1, pmax = n / 2;
    // cout << t[1].r << " " << t[1].l << "hi\n";
    if (f(pmax) <= 0)
        return t[1].r - t[1].l;
    int l, r, mid, pos;
    if (f(pl) < 0) {
        l = 1;
        r = pmax;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (f(mid) >= 0) {
                pos = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        pl = pos;
    }
    if (f(pr) < 0) {
        l = pmax;
        r = n - 1;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (f(mid) >= 0) {
                pos = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        pr = pos;
    }
    ll ans = query_r(1, pr + 1) - query_l(1, pl);
    if (pl > 1)
        ans += query_sr(1, pl - 1) - query_sl(1, pl - 1);
    if (pr < n - 1)
        ans += (t[1].r - query_sr(1, pr + 1)) - (t[1].l - query_sl(1, pr + 1));
    return ans;
}
void solve() {
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        val.push_back(s[i]);
    }
    for (int i = 1; i <= Q; i++) {
        int opt;
        ll x;
        cin >> opt >> x;
        val.push_back(x);
        q[i] = {opt, 0, x};
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    m = val.size();
    for (int i = 1; i <= n; i++)
        id[i] = getid(s[i]);
    for (int i = 1; i <= Q; i++)
        q[i].id = getid(q[i].x);
    for (int i = 1; i <= n; i++)
        update(1, 1, m, id[i], s[i]);
    cout << query() << "\n";
    for (int i = 1; i <= Q; i++) {
        if (q[i].opt == 1) {
            n++;
            update(1, 1, m, q[i].id, q[i].x);
        } else {
            n--;
            update(1, 1, m, q[i].id, -q[i].x);
        }
        cout << query() << "\n";
    }
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