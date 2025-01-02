#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e6 + 1;
const ll M = 1e9 + 7;

ll n, m;
vector<pair<ll, ll>> a, b;

auto findConvexHull = [](vector<pair<ll, ll>> a) -> vector<pair<ll, ll>> {
    vector<pair<ll, ll>> hi, lo, res;
    sort(a.begin(), a.end(), [](pair<ll, ll>a, pair<ll, ll> b) -> bool { 
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    });
    auto cal = [&](pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) -> ll {
        return (a.first - b.first) * (a.second + b.second) + (b.first - c.first) * (b.second + c.second) + (c.first - a.first) * (c.second + a.second);
    };
    for (auto v : a) {
        while (hi.size() >= 2 && cal(hi[hi.size() - 2], hi[hi.size() - 1], v) >= 0) hi.pop_back();
        hi.push_back(v);
        while (lo.size() >= 2 && cal(lo[lo.size() - 2], lo[lo.size() - 1], v) <= 0) lo.pop_back();
        lo.push_back(v);
    }
    for (ll i = 0; i < hi.size() - 1; i ++) res.push_back(hi[i]);
    for (ll i = lo.size() - 1; i > 0; i --) res.push_back(lo[i]);
    return res;
};

auto dis = [](long double a, long double b) -> long double {
    return sqrt(a * a + b * b);
};

auto flatten = [](vector<pair<ll, ll>> a) -> vector<long double> {
    vector<long double> res;
    a.push_back(a[0]); a.push_back(a[1]);
    for (int i = 0; i < a.size() - 2; i ++) {
        res.push_back(dis(a[i].first - a[i + 1].first, a[i].second - a[i + 1].second));
        res.push_back(dis(a[i].first - a[i + 2].first, a[i].second - a[i + 2].second));
    }
    return res;
};

auto same = [](long double a, long double b) -> bool {
    return abs(a - b) < 1e-6;
};

auto pi = [](vector<long double> s) -> vector<ll> {
    vector<ll> p(s.size());
    for (ll i = 1; i < s.size(); i ++) {
        ll g = p[i - 1];
        while (g && !same(s[i], s[g])) g = p[g - 1];
        p[i] = g + same(s[i], s[g]);
    }
    return p;
};

void doTest(ll testID) {
    cin >> n >> m; a.resize(n); b.resize(m);
    for (int i = 0; i < n; i ++) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; i ++) cin >> b[i].first >> b[i].second;
    vector<pair<ll, ll>> ca = findConvexHull(a), cb = findConvexHull(b);
    vector<long double> fa = flatten(ca), fb = flatten(cb);
    
    vector<long double> s; for (auto x: fa) s.push_back(x); s.push_back('\0');
    for (auto x: fb) s.push_back(x); for (auto x: fb) s.push_back(x);
    vector<ll> p = pi(s);
    
    // cout << "Debug: " << '\n';
    // for (auto [x, y]: ca) cout << x << '-' << y << ' '; cout << '\n';
    // for (auto [x, y]: cb) cout << x << '-' << y << ' '; cout << '\n';
    // for (auto x: fa) cout << x << ' '; cout << '\n';
    // for (auto x: fb) cout << x << ' '; cout << '\n';
    // for (auto x: p) cout << x << ' '; cout << '\n';
    // cout << '\n';

    for (auto x: p)
        if (x == fa.size()) {
            cout << "YES";
            return;
        }
    cout << "NO";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; 
    // cin >> test;
    for (int _ = 1; _ <= test; _ ++) doTest(test);
}