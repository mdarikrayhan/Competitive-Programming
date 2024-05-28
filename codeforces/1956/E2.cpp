#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using ld = long double;

template<typename T>
int szof(T& a) {
    return a.size();
}

bool bad(int n, vector<int> z) {
    for (int i = 1; i < szof(z); ++i) {
        if (z[i] - z[i - 1] - 1 > 3) {
            return true;
        }
    }
    return z.empty() || (n - z.back() - 1) + z[0] > 3;
}

vector<int> alive(vector<int> p) {
    if (p.empty()) {
        return {};
    }
    if (szof(p) < 3) {
        return {1};
    }
    int x = p[1] / p[0];
    if ((ll)x * ((p[1] - x * p[0]) + (p[1] - p[0])) < p[2] + p[2]) {
        return {1, 3};
    }
    return {1};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), z;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            z.push_back(i);
        }
    }
    while (bad(n, z)) {
        for (int i = 1; i < n; ++i) {
            a[i] = max(0, a[i] - a[i - 1]);
        }
        a[0] = max(0, a[0] - a.back());
        z.clear();
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                z.push_back(i);
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i < szof(z); ++i) {
        for (auto j : alive(vector(a.begin() + z[i - 1] + 1, a.begin() + z[i]))) {
            ans.push_back(z[i - 1] + j + 1);
        }
    }
    {
        vector<int> p;
        for (int i = z.back() + 1; i < n; ++i) {
            p.push_back(a[i]);
        }
        if (z[0] > 0) {
            p.push_back(a[0]);
        }
        for (int i = 1; i < z[0]; ++i) {
            a[i] = max(0, a[i] - a[i - 1]);
            p.push_back(a[i]);
        }
        for (auto i : alive(p)) {
            ans.push_back((z.back() + i) % n + 1);
        }
    }
    sort(ans.begin(), ans.end());
    cout << szof(ans) << "\n";
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << "\n";
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios_base::fixed);
    cout.precision(6);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
