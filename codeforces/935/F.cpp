#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define app push_back
#define all(x) x.begin(), x.end()

#ifdef LOCAL
#define debug(...) [](auto...a){ ((cout << a << ' '), ...) << endl;}(#__VA_ARGS__, ":", __VA_ARGS__)
#define debugv(v) do { cout << #v << ": "; for (auto x : v) cout << x << ' '; cout << endl; } while(0)
#else
#define debug(...)
#define debugv(v)
#endif

#define x first
#define y second
#define double long double

template<typename T, typename U>
struct SegmentTree {
    int n;
    T neutral;
    U unite;
    vector<T> data;

    template<typename I>
    SegmentTree(int n, T neutral, U unite, I init) : n(n), neutral(neutral), unite(unite), data(2 * n) {
        for (int i = 0; i < n; ++i) data[i + n] = init(i);
        for (int i = n - 1; i > 0; --i) data[i] = unite(data[2 * i], data[2 * i + 1]);
    }

    SegmentTree(int n, T neutral, U unite) : n(n), neutral(neutral), unite(unite), data(2 * n, neutral) {}

    void set(int i, T x) {
        data[i += n] = x;
        for (i /= 2; i > 0; i /= 2) data[i] = unite(data[2 * i], data[2 * i + 1]);
    }

    T get(int l, int r) {
        T leftRes = neutral, rightRes = neutral;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) leftRes = unite(leftRes, data[l++]);
            if (r & 1) rightRes = unite(data[--r], rightRes);
        }
        return unite(leftRes, rightRes);
    }
};

int32_t main() {
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; ++i) d[i] = a[i + 1] - a[i];
    debugv(d);
    SegmentTree b(n - 2, (int)1e9, [&](int x, int y){ return min(x, y); }, [&](int i) { return max(-d[i], 0LL) + max(d[i + 1], 0LL); });
    SegmentTree c(n - 2, (int)1e9, [&](int x, int y){ return max(x, y); }, [&](int i) { return (d[i] >= 0 && d[i + 1] >= 0 ? d[i + 1] : (d[i] <= 0 && d[i + 1] <= 0 ? -d[i] : 0LL)); });
    auto upd = [&](int i) {
        if (i <= 0 || i >= n - 1) return;
        --i;
        b.set(i, max(-d[i], 0LL) + max(d[i + 1], 0LL));
        c.set(i, (d[i] >= 0 && d[i + 1] >= 0 ? d[i + 1] : (d[i] <= 0 && d[i + 1] <= 0 ? -d[i] : 0LL)));
    };
    int sd = 0;
    for (int i = 0; i + 1 < n; ++i) sd += abs(d[i]);
    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
//        for (int i = 0; i < n - 2; ++i) debug(b.get(i, i + 1));
        int t;
        cin >> t;
        int l, r, x;
        cin >> l >> r >> x;
        --l;
        if (t == 1) {
            int ans = 0;
            if (l + 1 == r) {
                if (l == 0) {
                    ans = sd - abs(d[0]) + abs(d[0] - x);
                } else if (r == n) {
                    ans = sd - abs(d[n - 2]) + abs(d[n - 2] + x);
                } else {
                    ans = sd - abs(d[l - 1]) - abs(d[l]) + abs(d[l - 1] + x) + abs(d[l] - x);
                }
            } else {
                if (l == 0) {
                    ans = max(ans, sd - abs(d[0]) + abs(d[0] - x));
                    l = 1;
                }
                if (r == n) {
                    ans = max(ans, sd - abs(d[n - 2]) + abs(d[n - 2] + x));
                    r = n - 1;
                }
                debug(ans, sd, b.get(l - 1, r - 1));
                ans = max(ans, sd + 2 * x - 2 * b.get(l - 1, r - 1));
                if (x <= c.get(l - 1, r - 1)) ans = max(ans, sd);
            }
            cout << ans << '\n';
        } else {
            if (l != 0) {
                sd -= abs(d[l - 1]);
                d[l - 1] += x;
                sd += abs(d[l - 1]);
                upd(l - 2);
                upd(l - 1);
                upd(l);
                upd(l + 1);
            }
            if (r != n) {
                sd -= abs(d[r - 1]);
                d[r - 1] -= x;
                sd += abs(d[r - 1]);
                upd(r - 2);
                upd(r - 1);
                upd(r);
                upd(r + 1);
            }
        }
    }

}