#line 1 "C_Graph_Transpositions.cpp"
/*
#include <bits/stdc++.h>

#include "math/modulo/modint.hpp"

template <> int cplib::ModInt<int, 0>::Mod = 998244353;
template <int V, int P>
constexpr cplib::ModInt<int, P> CInv = cplib::ModInt<int, P>(V).inv();

using Z = cplib::ModInt<int, 0>;

#include "data_structures/containers/heaps.hpp"
#include "misc/inf.hpp"
#include "misc/log2.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // if A movements and B transpositins
    // A + 2^(1 - 1) + 2^(2 - 1) + ... 2^(B - 1) = A + 2^B - 1
    //
    // none of the optimal solutions should cross an edge twice so A <= m
    // let lm = ceil(log_2(m))
    //
    // A', B' is another sequence
    //
    // consdier 2 cases:
    // B < lm < B':
    // i.e less than log flips
    //
    // then A + 2^B - 1 < A' + 2^B' - 1 since the difference between A and A' is
    // at max m, but 2^B' - 2^B is greater than m.
    //
    // Take this example to believe:
    //
    // B = 4 < lm = 5 < B' = 6
    // 2^6 - 2^4 = 2^4 * 3 > 2^4 * 2 = 2^5
    //
    // now we make the lm copies of the graph, each time transposed (the first
    // time it aint, the second time it is ... if even then transposed) then
    // connect it with the correct weight (between each node it self in the same
    // graph and also between teh different graph, I mean every node, and at
    // every point in time so that dijikstra can choose (*)) and then run
    // dijikstra to get the shortest weight of these path. The mvoement alogn
    // same graph is token and movement between new edge (i.e edge between
    // graphs (*)) is a graph transposition
    //
    // *now the reason we can do the same method as below is because, here it is
    // only guarranted the last B and lm i.e B < lm < B' is when B will
    // overpower A, before that it may not be the case therefore we need to make
    // lm copies and then actually move our node across depending on how much
    // weighted each of the nodes are, while in the next case we are said lm < B
    // < B' therefore B overpowers A in every scenario thus we can just do that
    //
    // or lm < B < B':
    // more thanlog flips
    //
    // then A + 2^B - 1 < A' + 2^B' - 1
    // regardless of A'
    //
    // so therefore we must check via (B, A) as if we are travelling within the
    // same graph we use weight (0, 1) and if we are coming from outside (1, 0)
    // and then we get shortest (B, A) via lexographically sort and then return
    // A + 2^B - 1
    //
    // this case is easy to understand
    //
    //
    // we need 2 cases, as in the second case B always overpowers A, but infirst
    // case there are scenarios where A can overpower B
    //
    // such a nice problem!!!

    int N, M;
    std::cin >> N >> M;
    // broke my graph template :(
    std::vector<std::pair<int, int>> UV(M);
    for (auto &[u, v] : UV) {
        std::cin >> u >> v;
        u--;
        v--;
    }

    std::vector<Z> pw2(std::max(N, M) + 1, 1);
    for (int i = 1; i < pw2.size(); i++) {
        pw2[i] = pw2[i - 1] * 2;
    }

    // first case
    {
        const int L = cplib::log2(M) + 1;

        std::vector<std::vector<std::pair<int, Z>>> adj(L * N + 1);

        // add the * (edge between graphs I mean every node and how much it
        // costs to do that move)
        for (int l = 0; l + 1 < L; l++) {
            for (int i = 0; i < N; i++) {
                adj[i + l * N].push_back({i + (l + 1) * N, pw2[l]});
            }
        }

        for (auto [u, v] : UV) {
            // even are non transposed
            for (int i = 0; i < L; i += 2) {
                // weight is 1, since only moving inside of same graph (token)
                adj[u + i * N].push_back({v + i * N, 1});
            }

            // odd are transposed
            for (int i = 1; i < L; i += 2) {
                // same reasonsas abvoe
                adj[v + i * N].push_back({u + i * N, 1});
            }
        }

        std::vector<int> D(adj.size(), inf<int>);
        auto djk = [&](int s) {
            cplib::MinHeap<std::pair<int, int>> pq;
            pq.push({0, s});
            D[s] = 0;
            while (!pq.empty()) {
                auto [d, x] = pq.top();
                pq.pop();

                if (d != D[x]) {
                    continue;
                }

                for (auto [y, w] : adj[x]) {
                    if (D[x] + w >= D[y]) {
                        continue;
                    }

                    D[y] = Z(D[x] + w).val();
                    pq.push({D[y], y});
                }
            }
        };
        djk(0);
        auto ans = inf<int>;
        for (int i = N - 1; i < adj.size(); i += N) {
            if (D[i] == inf<int>) {
                continue;
            }

            ans = std::min(ans, D[i]);
        }

        if (ans != inf<int>) {
            std::cout << ans << "\n";

            return 0;
        }
    }

    // second case
    {
        std::vector<std::vector<std::pair<int, std::pair<int, int>>>> adj(
            2 * N + 1);

        for (int i = 0; i < N; i++) {
            // 1, 0 i.e B, A is one transposition since we moved from i to i + N
            // i.e a transposed
            adj[i].push_back({i + N, {1, 0}});
            // reverse dir
            adj[i + N].push_back({i, {1, 0}});
        }

        for (auto [u, v] : UV) {
            adj[u].push_back({v, {0, 1}});
            // opposite i.e transposed, but it inside the transposed graph
            // itself thus A = 1 nad B = 0 since token
            adj[v + N].push_back({u + N, {0, 1}});
        }

        auto djk = [&](int s, int fin) {
            std::vector D(adj.size(), std::pair{inf<int>, inf<int>});

            cplib::MinHeap<std::pair<std::pair<int, int>, int>> pq;
            D[s] = {0, 0};
            pq.push({D[s], s});

            while (!pq.empty()) {
                auto [d, x] = pq.top();
                if (D[x] != d) {
                    continue;
                }
                pq.pop();

                for (auto [y, w] : adj[x]) {
                    std::pair<int, int> cur{D[x].first + w.first,
                                            D[x].second + w.second};
                    if (cur >= D[y]) {
                        continue;
                    }

                    D[y] = cur;
                    pq.push({D[y], y});
                }
            }

            return D[fin];
        };

        auto ans = djk(0, N - 1);
        ans = std::min(ans, djk(0, 2 * N - 1));

        std::cout << Z(ans.second + pw2[ans.first] - 1) << "\n";
    }

    return 0;
}
*/
// got the idea fully but too lazy to code

#include <bits/stdc++.h>
using namespace std;

template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int N = 200000;
const int L = __lg(N) + 1;
const int M = 998244353;

vector<int> adj[N][2];
int trans[N][2];
int dist[N][L];
int n;

int bfs() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            dist[i][j] = -1;
        }
    }

    deque<array<int, 2>> que;
    que.push_back({0, 0});
    dist[0][0] = 0;

    while (!que.empty()) {
        auto [u, t] = que.front();
        que.pop_front();

        for (auto c : adj[u][t]) {
            if (dist[c][t] == -1) {
                dist[c][t] = dist[u][t];
                que.push_front({c, t});
            }
        }

        if (dist[u][1 - t] == -1) {
            dist[u][1 - t] = dist[u][t] + 1;
            que.push_back({u, 1 - t});
        }
    }

    return min(dist[n - 1][0], dist[n - 1][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u][0].push_back(v);
        adj[v][1].push_back(u);
    }

    if (bfs() <= __lg(n)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= __lg(n); ++j) {
                dist[i][j] = -1;
            }
        }

        deque<array<int, 2>> que;
        que.push_back({0, 0});
        dist[0][0] = 0;

        while (!que.empty()) {
            auto [u, t] = que.front();
            que.pop_front();

            for (auto c : adj[u][t % 2]) {
                if (dist[c][t] == -1) {
                    dist[c][t] = dist[u][t] + 1;
                    que.push_back({c, t});
                }
            }

            if (t + 1 <= __lg(n) && dist[u][t + 1] == -1) {
                dist[u][t + 1] = dist[u][t];
                que.push_front({u, t + 1});
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j <= __lg(n); ++j) {
            if (dist[n - 1][j] != -1) {
                ans = min(ans, dist[n - 1][j] + (1 << j) - 1);
            }
        }
        cout << ans << "\n";
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                trans[i][j] = INT_MAX;
                dist[i][j] = INT_MAX;
            }
        }

        min_queue<array<int, 4>> que;
        que.push({0, 0, 0, 0});
        trans[0][0] = 0;
        dist[0][0] = 0;

        while (!que.empty()) {
            auto [d1, d2, u, t] = que.top();
            que.pop();
            if (make_pair(d1, d2) > make_pair(trans[u][t], dist[u][t])) {
                continue;
            }

            for (auto c : adj[u][t % 2]) {
                if (make_pair(d1, d2 + 1) <
                    make_pair(trans[c][t], dist[c][t])) {
                    trans[c][t] = d1;
                    dist[c][t] = d2 + 1;
                    que.push({d1, d2 + 1, c, t});
                }
            }

            if (make_pair(d1 + 1, d2) <
                make_pair(trans[u][1 - t], dist[u][1 - t])) {
                trans[u][1 - t] = d1 + 1;
                dist[u][1 - t] = d2;
                que.push({d1 + 1, d2, u, 1 - t});
            }
        }

        int color = make_pair(trans[n - 1][0], dist[n - 1][0]) >
                    make_pair(trans[n - 1][1], dist[n - 1][1]);

        int ans = 1;
        for (int i = 0; i < trans[n - 1][color]; ++i) {
            ans = ans * 2 % M;
        }
        ans = (ans + dist[n - 1][color] - 1) % M;

        cout << ans << "\n";
    }
}
