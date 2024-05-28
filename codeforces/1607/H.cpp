/**
 *    author:  longvu
 *    created: 05/28/24 00:25:39
**/
#include<bits/stdc++.h>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
const int INF = numeric_limits<int>::max();
const int naxn = (int)(201001);
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

int a[naxn], b[naxn], c[naxn], ansa[naxn], ansb[naxn];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> value;
        map<int, vector<int>> memo;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i] >> c[i];
            memo[a[i] + b[i] - c[i]].push_back(i);
            value.push_back(a[i] + b[i] - c[i]);
        }
        sort(all(value));
        value.resize(unique(all(value)) - value.begin());
        int ans = 0;
        for (auto z : value) {
            vector<int> tmp = memo[z];
            // cout << z << '\n';
            vector<tuple<int, int, int>> segment;
            for (auto t : tmp) {
                int l = a[t] - min(a[t], c[t]), r = a[t] - max(0, c[t] - b[t]);
                // cout << l << " " << r << '\n';
                if (l > r) {
                    ans++;
                    ansa[t] = min(c[t], a[t]); ansb[t] = c[t] - ansa[t];
                    continue;
                }
                segment.push_back({l, r, t});
            }
            sort(all(segment));
            for (int i = 0; i < sz(segment); ++i) {
                int j = i, mn = get<1>(segment[i]);
                while (j + 1 < sz(segment) && get<0>(segment[j + 1]) <= mn) {
                    minimize(mn, get<1>(segment[j + 1]));
                    j++;
                }
                for (int e = i; e <= j; ++e) {
                    int t = get<2>(segment[e]);
                    ansa[t] = a[t] - get<0>(segment[j]); 
                    ansb[t] = c[t] - ansa[t];
                }
                ans++;
                i = j;
            }
        }
        cout << ans << '\n';
        for (int i = 1; i <= n; ++i) {
            cout << ansa[i] << " " << ansb[i] << '\n';
        }
    }
    return 0;
}