#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, m;
vector<int> adj[N];
int num[N];
int cnt = 0;
int par[N];
vector<pair<int, int>> vec;

void dfs(int u, int pre) {
    num[u] = ++cnt;
    for (int v : adj[u]) {
        if (v != pre) {
            if (!num[v]) {
                par[v] = u;
                dfs(v, u);
            } else if (num[v] < num[u]) {
                int w = u;
                int mn = u, mx = u;
                while (w != v) {
                    int w1 = par[w];
                    w = w1;
                    mn = min(mn, w);
                    mx = max(mx, w);
                }
                vec.push_back({mn, mx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("sol.inp", "r")) {
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!num[i]) {
            dfs(i, i);
        }
    }

    sort(vec.begin(), vec.end(), [&](pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    });

    vector<int> lef(n + 1, 0);
    int mx = 0;
    for (int i = 1, j = 0; i <= n; ++i) {
        while (j < vec.size() && vec[j].second <= i) {
            mx = max(mx, vec[j].first);
            j++;
        }
        lef[i] = mx + 1;
    }

    vector<long long> sum(n + 1, 0), s(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + i - lef[i] + 1;
        s[i] = s[i - 1] + i;
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        int lo = l, hi = r, id = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (lef[mid] < l) {
                lo = mid + 1;
                id = mid;
            } else {
                hi = mid - 1;
            }
        }

        cout << s[id] - s[l - 1] - 1LL * (id - l + 1) * (l - 1) + sum[r] - sum[id] << '\n';
    }
    return 0;
}