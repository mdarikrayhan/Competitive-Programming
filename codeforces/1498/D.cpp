#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define oo ((ll)1e18)
#define endl '\n'
#define all(v) v.begin(),v.end()

#ifdef LOCAL

#include "assets/debug.h"

#else
#define dd(x...)
#define ExeTime
#endif

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int N = 1e6 + 10, M = 20, mod = 1e9 + 7, K = 22;
const double EPS = 1e-12, PI = acos(-1);

void testCase();

void init() {}

int main() {
    init();
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
//    cin >> T;
    for (int i = 0; i < T; i++) {
        testCase();
    }
    ExeTime;
}

void testCase() {
    int n, m;
    cin >> n >> m;
    vector<int> ans(m + 1, 1e9);
    ans[0] = 0;
    for (int i = 0; i < n; i++) {
        ll t, x, y;
        cin >> t >> x >> y;
        vector<bool> vis(m + 1, 0);
        queue<pair<int, int> > q;
        for (int j = 0; j <= m; j++) {
            if (ans[j] != 1e9) {
                q.push({j, 0});
                vis[j] = 1;
            }
        }

        if (t == 1) {
            while (!q.empty()) {
                auto [fr, level] = q.front();
                q.pop();
                ll nx = (fr * 1e5 + x + 1e5 - 1) / 1e5;
                if (nx > m || vis[nx] || level >= y) continue;
                q.push({nx, level + 1});
                ans[nx] = min(i + 1, ans[nx]);
                vis[nx] = 1;
            }
        } else {
            while (!q.empty()) {
                auto [fr, level] = q.front();
                q.pop();
                ll nx = (fr * x + 1e5 - 1) / 1e5;
                if (nx > m || vis[nx] || level >= y) continue;
                q.push({nx, level + 1});
                ans[nx] = min(i + 1, ans[nx]);
                vis[nx] = 1;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        if (ans[i] == 1e9) cout << -1 << ' ';
        else cout << ans[i] << ' ';
    }
    cout << endl;
}