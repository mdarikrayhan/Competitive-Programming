#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
// typedef __int128 ll;
typedef double ld;
typedef double db;
const int mod = 1e9 + 7;

template <typename T>
T SSSP(const vector<vector<pair<int, T>>> &G, int s, int t) {
    const T inf = 1e9;

    int n = G.size();
    vector<int> vis(n, 0);
    vector<T> dis(n, inf);
    dis[s] = 0;

    priority_queue<pair<T, int>> pq;
    pq.push(make_pair(-dis[s], s));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        for (auto [v, d] : G[u]) {
            if (dis[v] > dis[u] + d) {
                dis[v] = dis[u] + d;
                pq.push(make_pair(-dis[v], v));
            }
        }
    }
    return dis[t] == inf ? -1 : dis[t];
}

void solve(int cas) {
    int n, m;
    cin >> n >> m;
    string _s;
    cin >> _s;
    auto foo = [&](string s) -> int {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ret |= (1 << i);
            }
        }
        return ret;
    };
    int s = foo(_s);
    vector<vector<pair<int, int>>> G(1 << n);
    for (int i = 1; i <= m; i++) {
        int w;
        cin >> w;
        cin >> _s;
        int s0 = foo(_s);
        cin >> _s;
        int s1 = foo(_s);
        for (int u = 0; u < (1 << n); u++) {
            int v = (u ^ (u & s0)) | s1;
            G[u].push_back({v, w});
        }
    }
    int ans = SSSP<int>(G, s, 0);
    cout << ans << endl;
}

int main() {
    // srand(time(0));
    ios::sync_with_stdio(false);
    // freopen("1.txt", "r", stdin);
    // freopen("factory.out", "w", stdout);
    int T = 1, cas = 0;
    cin >> T;
    while (T--) {
        solve(++cas);
    }
    return 0;
}
