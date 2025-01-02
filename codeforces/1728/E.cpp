#include <bits/stdc++.h>

#define int long long
#define ld long double
#define F first
#define S second
using namespace std;
int n;
vector<pair<int, int>> a;

bool cmp(pair<int, int> v1, pair<int, int> v2) {
    return v1.F - v1.S > v2.F - v2.S;
}

pair<int, int> euclid(int c1, int c2) {
    if (c1 == c2 + 1) {
        return {1, -1};
    }
    if (c2 == c1 + 1) {
        return {-1, 1};
    }
    pair<int, int> r = euclid(c2, c1 % c2);
    return {r.S, r.F - r.S * (c1 / c2)};
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    int now = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].F >> a[i].S;
        now += a[i].S;
    }
    sort(a.begin(), a.end(), cmp);
    vector<int> sum(n + 1);
    sum[0] = now;
    for (int i = 0; i < n; ++i) {
        now += a[i].F - a[i].S;
        sum[i + 1] = now;
    }
    int id = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i].F - a[i].S >= 0 && a[i + 1].F - a[i + 1].S <= 0) {
            id = i + 1;
            break;
        }
    }
    if (id == -1 && a[n - 1].F - a[n - 1].S > 0) {
        id = n;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        int gc = gcd(x, y);
        if (n % gc) {
            cout << -1 << '\n';
            continue;
        }
        int c1 = x / gc, c2 = y / gc;
        int tot = n / gc;
        auto[X, Y]=euclid(c1, c2);
        X *= tot;
        Y *= tot;
        if (X < 0) {
            int o = (-X + c2 - 1) / c2;
            X += o * c2;
            Y -= o * c1;
        }
        if (X > 0) {
            int o = X / c2;
            X -= o * c2;
            Y += o * c1;
        }
        if (Y < 0) {
            cout << -1 << '\n';
            continue;
        }
        int ans = 0;
        if (X * x <= id) {
            int o = (id - X * x) / (c2 * x);
            ans = max(ans, sum[X * x + o * c2 * x]);
            o++;
            if (X * x + o * c2 * x <= n) {
                ans = max(ans, sum[X * x + o * c2 * x]);
            }
        } else {
            ans = sum[X * x];
        }
        cout << ans << '\n';
    }
    return 0;
}
