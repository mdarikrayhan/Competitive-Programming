/**
 *    author:  longvu
 *    created: 05/26/24 00:03:28
**/
#include<bits/stdc++.h>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
const int INF = numeric_limits<int>::max();
const int nax = (int)(2010001);
const int naxp = (int)(20100001);
const int mod = 1e9 + 7;

template<class X, class Y>
bool maximize(X& x, const Y y) {
    if (y > x) {x = y; return true;}
    return false;
}
template<class X, class Y>
bool minimize(X& x, const Y y) {
    if (y < x) {x = y; return true;}
    return false;
}

#define Fi first
#define Se second

int a[nax], b[nax], p[nax], mp[naxp];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        p[i] = i;
    }
    sort(p + 1, p + m + 1, [&](int x, int y) {
        return b[x] > b[y];
    });
    auto ok = [&](int z) {
        for (int i = 0; i <= max(n, m); ++i) {
            mp[a[i]] = mp[b[i]] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            mp[a[i]]++;
        }
        for (int i = 1; i <= z; ++i) {
            mp[b[p[i]]]++;
        }
        vector<pair<int, int>> memo;
        for (int i = 0; i < naxp; ++i) {
            if (mp[i]) {
                memo.push_back({i, mp[i]});
            }
        }
        reverse(all(memo));
        for (int i = 0; ; ++i) {
            int d = k;
            while (d > 0) {
                if (memo.empty()) {
                    return true;
                }
                if (i > memo.back().Fi) {
                    return false;
                }
                if (d >= memo.back().Se) {
                    d -= memo.back().Se;
                    memo.pop_back();
                } else {
                    memo.back().Se -= d;
                    d = 0;
                    if (!memo.back().Se) {
                        memo.pop_back();
                    }
                }

            }
        }
        assert(false);
    };
    int l = 0, r = m;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    l--;
    cout << l << '\n';
    for (int i = 1; i <= l; ++i) {
        cout << p[i] << " ";
    }
    cout << '\n';
    return 0;
}