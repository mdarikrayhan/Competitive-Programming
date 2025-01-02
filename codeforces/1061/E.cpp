#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct Edge {
    int to, cap, cost, f, rev;
    Edge(int to, int cap, int cost, int rev)
        : to(to), cap(cap), cost(cost), f(0), rev(rev) {}
};

const int INF = 1e9;
vector<int> adj[1000];
int req[1000];
int flag;
vector<Edge> graph[2004];

void addEdge(vector<Edge> graph[], int s, int t, int cap, int cost) {
    graph[s].emplace_back(t, cap, cost, graph[t].size());
    graph[t].emplace_back(s, 0, -cost, graph[s].size() - 1);
}

void bellmanFord(vector<Edge> graph[], int s, int dist[]) {
    int n = 2004;
    fill(dist, dist + n, INF);
    dist[s] = 0;
    bool in_queue[2004] = {false};
    int q[2004], qt = 0;
    q[qt++] = s;
    for (int qh = 0; (qh - qt) % n != 0; qh++) {
        int u = q[qh % n];
        in_queue[u] = false;
        for (Edge &e : graph[u]) {
            if (e.cap <= e.f) continue;
            int v = e.to;
            int n_dist = dist[u] + e.cost;
            if (dist[v] > n_dist) {
                dist[v] = n_dist;
                if (!in_queue[v]) {
                    in_queue[v] = true;
                    q[qt++ % n] = v;
                }
            }
        }
    }
}

int* minCostFlow(vector<Edge> graph[], int s, int t, int max_flow) {
    int n = 2004;
    static int prio[2004], current_flow[2004], previous_edge[2004], previous_node[2004], pot[2004];
    static int result[2];
    bellmanFord(graph, s, pot);
    int flow = 0, flowCost = 0;
    while (flow < max_flow) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, s});
        fill(prio, prio + n, INF);
        prio[s] = 0;
        bool finished[2004] = {false};
        current_flow[s] = INF;
        while (!finished[t] && !q.empty()) {
            int priou = q.top().first;
            int u = q.top().second;
            q.pop();
            if (priou != prio[u]) continue;
            finished[u] = true;
            for (size_t i = 0; i < graph[u].size(); i++) {
                Edge &e = graph[u][i];
                if (e.f >= e.cap) continue;
                int v = e.to;
                int nprio = prio[u] + e.cost + pot[u] - pot[v];
                if (prio[v] > nprio) {
                    prio[v] = nprio;
                    q.push({nprio, v});
                    previous_node[v] = u;
                    previous_edge[v] = i;
                    current_flow[v] = min(current_flow[u], e.cap - e.f);
                }
            }
        }
        if (prio[t] == INF) break;
        for (int i = 0; i < n; i++) if (finished[i]) pot[i] += prio[i] - prio[t];
        int df = min(current_flow[t], max_flow - flow);
        flow += df;
        for (int v = t; v != s; v = previous_node[v]) {
            Edge &e = graph[previous_node[v]][previous_edge[v]];
            e.f += df;
            graph[v][e.rev].f -= df;
            flowCost += df * e.cost;
        }
    }
    result[0] = flow;
    result[1] = flowCost;
    return result;
}

int dfs(int i, int par, int flow[], int col[], int curCol) {
    if (req[i] != -1) curCol = i;
    col[i] = curCol;

    int cost = 0;

    for (int j : adj[i]) {
        if (j != par)
            cost += dfs(j, i, flow, col, curCol);
    }

    if (req[i] != -1) {
        if (cost > req[i]) {
            flag = 1;
        }
        flow[i] = req[i] - cost;
        cost = req[i];
    }

    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int capital1, capital2;
    cin >> capital1 >> capital2;
    capital1--; capital2--;

    int maxVal = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }

    for (int i = 0; i < n; ++i) adj[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> adj2[n];
    for (int i = 0; i < n; ++i) adj2[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    fill(req, req + n, -1);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int ind, value;
        cin >> ind >> value;
        req[ind - 1] = value;
    }
    int reqFlow1 = req[capital1];

    vector<int> col(n), flow(n, 1000);
    flag = 0;
    dfs(capital1, -1, flow.data(), col.data(), capital1);
    if (flag == 1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) adj[i] = adj2[i];

    fill(req, req + n, -1);
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int ind, value;
        cin >> ind >> value;
        req[ind - 1] = value;
    }
    int reqFlow2 = req[capital2];

    if (reqFlow1 != reqFlow2) {
        cout << "-1\n";
        return 0;
    }

    vector<int> col2(n), flow2(n, 1000);
    flag = 0;
    dfs(capital2, -1, flow2.data(), col2.data(), capital2);
    if (flag == 1) {
        cout << "-1\n";
        return 0;
    }

    int source = 0, sink = 2 * n + 1;
    for (int i = 0; i < n; ++i) {
        addEdge(graph, source, i + 1, flow[i], 0);
        addEdge(graph, n + i + 1, sink, flow2[i], 0);
        addEdge(graph, col[i] + 1, n + col2[i] + 1, 1, -a[i] + maxVal);
    }

    int* ans = minCostFlow(graph, source, sink, n);
    if (ans[0] != reqFlow1) {
        cout << "-1\n";
        return 0;
    }

    int fans = ans[1] - maxVal * reqFlow1;
    fans = -fans;

    cout << fans << '\n';

    return 0;
}
