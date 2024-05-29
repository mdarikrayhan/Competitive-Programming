#include <bits/stdc++.h>

using i64 = long long;

template<class Ty>
struct MincostFlow {
    const Ty INF = std::numeric_limits<Ty>::max();
    const int n;
    struct Edge {
        int v, nxt; Ty f, w;
        Edge() : Edge(0, 0, 0, 0) {};
        Edge(int v, int nxt, Ty f, Ty w) : v(v), nxt(nxt), f(f), w(w) {};
    };
    struct mypair {
        Ty dist; int u;
        mypair() : mypair(0, 0) {}
        mypair(Ty d, int u) : dist(d), u(u) {}
        bool operator<(const mypair& rhs) const {
            return dist > rhs.dist;
        }
    };
    int S, T; Ty MF = 0, MC = 0;
    std::vector<Ty> dist, D;
    std::vector<int> h, pre;
    std::vector<Edge> E;

    MincostFlow(int _) : n(_) { init(_); };

    void init(int _) {
        dist.assign(_ + 1, 0);
        pre.assign(_ + 1, 0);
        h.assign(_ + 1, -1);
        D.assign(_ + 1, 0);
    }
    void add(int u, int v, Ty flow, Ty weight) {
        E.emplace_back(v, h[u], flow, weight), h[u] = int(E.size()) - 1;
    }
    void addEdge(int u, int v, Ty f, Ty w) {
        add(u, v, f, w), add(v, u, 0, -w);
    }

    bool Dijkstra() {
        dist.assign(n + 1, INF);
        std::priority_queue<mypair> q;
        dist[S] = 0;
        q.emplace(0, S);
        while (q.size()) {
            auto [dis, u] = q.top(); q.pop();
            if (dist[u] < dis) continue;
            for (int i = h[u]; ~i; i = E[i].nxt) {
                auto& [v, nxt, f, w] = E[i];
                if (f > 0 && dist[v] > dis + D[u] - D[v] + w) {
                    dist[v] = dis + D[u] - D[v] + w;
                    q.emplace(dist[v], v);
                    pre[v] = i;
                }
            }
        }
        return dist[T] != INF;
    }
    void work() {
        while (Dijkstra()) {
            Ty flow = INF;
            for (int i = 0; i <= n; ++i) D[i] += dist[i];
            for (int i = T; i != S; i = E[pre[i] ^ 1].v) {
                flow = std::min(flow, E[pre[i]].f);
            }
            for (int i = T; i != S; i = E[pre[i] ^ 1].v) {
                E[pre[i]].f -= flow, E[pre[i] ^ 1].f += flow;
            }
            MC += D[T] * flow;
            MF += flow;
        }
    }
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    MincostFlow<int> G(4 * n + 2);
    G.S = 0, G.T = 4 * n + 2;
    G.addEdge(G.S, 4 * n + 1, 4, 0);

    // 1 in n+1 out
    // 2n+1 del 3n+1 mod
    for (int i = 1; i <= n; ++i) {
        G.addEdge(4 * n + 1, i, n, 0);

        G.addEdge(2 * n + i, i, n, 0);
        G.addEdge(3 * n + i, i, n, 0);

        G.addEdge(i, n + i, 1, -1);
        G.addEdge(n + i, G.T, n, 0);
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] + 1 == a[j]) {
                G.addEdge(n + i, 2 * n + j, n, 0);
                break;
            }
        }
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] - 1 == a[j]) {
                G.addEdge(n + i, 2 * n + j, n, 0);
                break;
            }
        }
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] % 7 == a[j] % 7) {
                G.addEdge(n + i, 3 * n + j, n, 0);
                G.addEdge(3 * n + i, 3 * n + j, n, 0);
                break;
            }
        }
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] == a[j]) {
                G.addEdge(2 * n + i, 2 * n + j, n, 0);
                break;
            }
        }
    }

    G.work();

    std::cout << -G.MC << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}