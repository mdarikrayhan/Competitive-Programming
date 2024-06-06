//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("avx", "avx2", "fma")

#include <bits/stdc++.h>

using namespace std;

//#define int long long
typedef long double ld;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 _mt(seed);

struct hash_function {
    size_t operator() (const pair<int, int>& p) const {
        return (p.first << 1) ^ p.second;
    }
};

#define x first
#define y second

const int COORD = 2e5 + 5;

int32_t main() {
#ifdef LOCAL
#else
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("f.in", "r", stdin);
    //freopen("f.out", "w", stdout);
#endif
    vector<vector<int>> diag1(2 * COORD), diag2(2 * COORD), sdiag1(2 * COORD), sdiag2(2 * COORD);
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<pair<int, int>> a(n);
        unordered_set<pair<int, int>, hash_function> s;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            a[i] = {x, y};
            s.emplace(x, y);
        }
        unordered_set<int> used1, used2;
        for (int i = 0; i < n; ++i) {
            diag1[a[i].x + a[i].y + COORD].push_back(a[i].x);
            if (s.find({a[i].x + d / 2, a[i].y - d / 2}) != s.end()) {
                sdiag1[a[i].x + a[i].y + COORD].push_back(a[i].x);
            }
            used1.insert(a[i].x + a[i].y + COORD);
            diag2[a[i].x - a[i].y + COORD].push_back(a[i].x);
            if (s.find({a[i].x + d / 2, a[i].y + d / 2}) != s.end()) {
                sdiag2[a[i].x - a[i].y + COORD].push_back(a[i].x);
            }
            used2.insert(a[i].x - a[i].y + COORD);
        }
        for (int i : used1) {
            sort(diag1[i].begin(), diag1[i].end());
            sort(sdiag1[i].begin(), sdiag1[i].end());
        }
        for (int i : used2) {
            sort(diag2[i].begin(), diag2[i].end());
            sort(sdiag2[i].begin(), sdiag2[i].end());
        }
        bool fnd = false;
        int x1, x2, x3, y1, y2, y3;
        for (int i = 0; i < n; ++i) {
            if (s.find({a[i].x, a[i].y - d}) != s.end() && s.find({a[i].x - d / 2, a[i].y - d / 2}) != s.end()) {
                x1 = a[i].x, y1 = a[i].y;
                x2 = a[i].x, y2 = a[i].y - d;
                x3 = a[i].x - d / 2, y3 = a[i].y - d / 2;
                fnd = true;
                break;
            }
            if (s.find({a[i].x, a[i].y + d}) != s.end() && s.find({a[i].x + d / 2, a[i].y + d / 2}) != s.end()) {
                x1 = a[i].x, y1 = a[i].y;
                x2 = a[i].x, y2 = a[i].y + d;
                x3 = a[i].x + d / 2, y3 = a[i].y + d / 2;
                fnd = true;
                break;
            }
            if (-COORD <= a[i].x + a[i].y + d && a[i].x + a[i].y + d < COORD) {
                if (s.find({a[i].x + d / 2, a[i].y - d / 2}) != s.end()) {
                    int l = -1, r = diag1[a[i].x + a[i].y + d + COORD].size();
                    while (r - l > 1) {
                        int m = (l + r) >> 1;
                        if (diag1[a[i].x + a[i].y + d + COORD][m] <= a[i].x + d / 2) {
                            l = m;
                        } else {
                            r = m;
                        }
                    }
                    if (r < diag1[a[i].x + a[i].y + d + COORD].size() && diag1[a[i].x + a[i].y + d + COORD][r] <= a[i].x + d) {
                        x1 = a[i].x, y1 = a[i].y;
                        x2 = a[i].x + d / 2, y2 = a[i].y - d / 2;
                        x3 = diag1[a[i].x + a[i].y + d + COORD][r], y3 = (a[i].x + a[i].y + d) - diag1[a[i].x + a[i].y + d + COORD][r];
                        fnd = true;
                        break;
                    }
                }
                int l = -1, r = sdiag1[a[i].x + a[i].y + d + COORD].size();
                while (r - l > 1) {
                    int m = (l + r) >> 1;
                    if (sdiag1[a[i].x + a[i].y + d + COORD][m] <= a[i].x) {
                        l = m;
                    } else {
                        r = m;
                    }
                }
                if (r < sdiag1[a[i].x + a[i].y + d + COORD].size() && sdiag1[a[i].x + a[i].y + d + COORD][r] <= a[i].x + d / 2) {
                    x1 = a[i].x, y1 = a[i].y;
                    x2 = sdiag1[a[i].x + a[i].y + d + COORD][r], y2 = (a[i].x + a[i].y + d) - sdiag1[a[i].x + a[i].y + d + COORD][r];
                    x3 = sdiag1[a[i].x + a[i].y + d + COORD][r] + d / 2, y3 = (a[i].x + a[i].y + d) - sdiag1[a[i].x + a[i].y + d + COORD][r] - d / 2;
                    fnd = true;
                    break;
                }
            }
            if (-COORD <= a[i].x - a[i].y + d && a[i].x - a[i].y + d < COORD) {
                if (s.find({a[i].x + d / 2, a[i].y + d / 2}) != s.end()) {
                    int l = -1, r = diag2[a[i].x - a[i].y + d + COORD].size();
                    while (r - l > 1) {
                        int m = (l + r) >> 1;
                        if (diag2[a[i].x - a[i].y + d + COORD][m] <= a[i].x + d / 2) {
                            l = m;
                        } else {
                            r = m;
                        }
                    }
                    if (r < diag2[a[i].x - a[i].y + d + COORD].size() && diag2[a[i].x - a[i].y + d + COORD][r] <= a[i].x + d) {
                        x1 = a[i].x, y1 = a[i].y;
                        x2 = a[i].x + d / 2, y2 = a[i].y + d / 2;
                        x3 = diag2[a[i].x - a[i].y + d + COORD][r], y3 = diag2[a[i].x - a[i].y + d + COORD][r] - (a[i].x - a[i].y + d);
                        fnd = true;
                        break;
                    }
                }
                int l = -1, r = sdiag2[a[i].x - a[i].y + d + COORD].size();
                while (r - l > 1) {
                    int m = (l + r) >> 1;
                    if (sdiag2[a[i].x - a[i].y + d + COORD][m] <= a[i].x) {
                        l = m;
                    } else {
                        r = m;
                    }
                }
                if (r < sdiag2[a[i].x - a[i].y + d + COORD].size() && sdiag2[a[i].x - a[i].y + d + COORD][r] <= a[i].x + d / 2) {
                    x1 = a[i].x, y1 = a[i].y;
                    x2 = sdiag2[a[i].x - a[i].y + d + COORD][r], y2 = sdiag2[a[i].x - a[i].y + d + COORD][r] - (a[i].x - a[i].y + d);
                    x3 = sdiag2[a[i].x - a[i].y + d + COORD][r] + d / 2, y3 = sdiag2[a[i].x - a[i].y + d + COORD][r] - (a[i].x - a[i].y + d) + d / 2;
                    fnd = true;
                    break;
                }
            }
        }
        if (fnd) {
            int i = -1, j = -1, k = -1;
            for (int z = 0; z < n; ++z) {
                if (a[z].x == x1 && a[z].y == y1) {
                    i = z + 1;
                }
                if (a[z].x == x2 && a[z].y == y2) {
                    j = z + 1;
                }
                if (a[z].x == x3 && a[z].y == y3) {
                    k = z + 1;
                }
            }
            cout << i << " " << j << " " << k << "\n";
        } else {
            cout << "0 0 0\n";
        }
        for (int i : used1) {
            diag1[i].clear();
            sdiag1[i].clear();
        }
        for (int i : used2) {
            diag2[i].clear();
            sdiag2[i].clear();
        }
    }
    return 0;
}
