#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define EPS 1e-9
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define endl '\n'
#define PI acos(-1)
#define Ones(n) __builtin_popcount(n)
#define Onesl(n) __builtin_popcountll(n)
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;
const ll N = 2e5 + 5;
const int OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
int dx8[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy8[] = {-1, +1, +0, +0, +1, -1, +1, -1};
int dx4[] = {+0, +0, -1, +1};
int dy4[] = {-1, +1, +0, +0};
int knightX[] = {+1, +1, +2, +2, -1, -1, -2, -2};
int knightY[] = {+2, -2, +1, -1, -2, +2, +1, -1};

void Rokba() {
    cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);
#ifdef Clion
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

vector<pair<int, int>> adj[N];
int n, m;
vector<int> vars[N];
set<int> active;
char ans[N];
int who[N];
int who2[N];
bool vis[N];
queue<int> q;
int cnt[N];

bool notDependant(int u) {
    if (vis[u])
        return false;
    int c = 0;
    for (auto x: adj[u])
        c += (int)active.count(x.first);
    if (c == 2 && adj[u][1].second != adj[u][0].second)
        return false;
    return true;
}

void solveExpression(int idx) {
    active.erase(idx);
    for (auto x: vars[idx])
        if (!vis[abs(x)]) {
            if (adj[abs(x)][0].first != idx) {
                who[abs(x)] = adj[abs(x)][0].first;
            } else {
                who[abs(x)] = adj[abs(x)][1].first;
            }
            q.push(abs(x));
            vis[abs(x)] = true;
        }
}

int getParity(int idx, int x) {
    for (auto v: adj[x]) {
        if (v.first == idx)
            return v.second;
    }
    return -1;
}

void solveQueue() {
    while (q.size()) {
        auto cur = q.front();
        for (auto x: adj[cur])
            cnt[x.first]--;
        q.pop();
        if (active.count(who[cur]) == 0 && active.count(who2[cur]) == 0) {
            ans[cur] = '0';
            continue;
        }
        ans[cur] = '0' + getParity(who[cur], cur);
        solveExpression(who[cur]);
        solveExpression(who2[cur]);
    }
}

typedef long long LL;

struct Edge {
    int from, to, cap, flow, index;

    Edge(int from, int to, int cap, int flow, int index) :
            from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
    int N;
    vector<vector<Edge> > G;
    vector<LL> excess;
    vector<int> dist, active, count;
    queue<int> Q;

    PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2 * N) {}

    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    void Enqueue(int v) {
        if (!active[v] && excess[v] > 0) {
            active[v] = true;
            Q.push(v);
        }
    }

    void Push(Edge &e) {
        int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
        if (dist[e.from] <= dist[e.to] || amt == 0) return;
        e.flow += amt;
        G[e.to][e.index].flow -= amt;
        excess[e.to] += amt;
        excess[e.from] -= amt;
        Enqueue(e.to);
    }

    void Gap(int k) {
        for (int v = 0; v < N; v++) {
            if (dist[v] < k) continue;
            count[dist[v]]--;
            dist[v] = max(dist[v], N + 1);
            count[dist[v]]++;
            Enqueue(v);
        }
    }

    void Relabel(int v) {
        count[dist[v]]--;
        dist[v] = 2 * N;
        for (int i = 0; i < G[v].size(); i++)
            if (G[v][i].cap - G[v][i].flow > 0)
                dist[v] = min(dist[v], dist[G[v][i].to] + 1);
        count[dist[v]]++;
        Enqueue(v);
    }

    void Discharge(int v) {
        for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
        if (excess[v] > 0) {
            if (count[dist[v]] == 1)
                Gap(dist[v]);
            else
                Relabel(v);
        }
    }

    LL GetMaxFlow(int s, int t) {
        count[0] = N - 1;
        count[N] = 1;
        dist[s] = N;
        active[s] = active[t] = true;
        for (int i = 0; i < G[s].size(); i++) {
            excess[s] += G[s][i].cap;
            Push(G[s][i]);
        }

        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            active[v] = false;
            Discharge(v);
        }

        LL totflow = 0;
        for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
        return totflow;
    }
};

void Solution() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        cnt[i] = k;
        vars[i].resize(k);
        active.insert(i);
        for (auto &x: vars[i]) {
            cin >> x;
            adj[abs(x)].push_back({i, x > 0});
        }
    }

    for (int i = 1; i <= m; i++) {
        if (adj[i].empty()) {
            ans[i] = '0';
            vis[i] = true;
        }
        if (notDependant(i)) {
            vis[i] = true;
            who[i] = adj[i][0].first;
            if (adj[i].size() == 2)
                who2[i] = adj[i][1].first;
            q.push(i);
        }
    }
    solveQueue();

    ///the rest are of 2 occurences and have different parities
    int nodes = n + m + 2;
    int source = n + m;
    int sink = source + 1;
    PushRelabel net(nodes);
    for (int i = 1; i <= n; i++)
        if (active.count(i)) {
            net.AddEdge(source, i - 1, 1);
        }
    for (int i = 1; i <= m; i++)
        if (!vis[i]) {
            ans[i] = '0';
            net.AddEdge(n + i - 1, sink, 1);
            for (auto x: adj[i]) {
                net.AddEdge(x.first - 1, n + i - 1, 1);
            }
        }
    int x = net.GetMaxFlow(source, sink);
    if (x == active.size()) {
        for (int i = 1; i <= m; i++) {
            if (!vis[i]) {
                for (auto x: net.G[n + i - 1]) {
                    if (x.flow) {
                        if (x.to + 1 == adj[i][0].first) {
                            ans[i] = '0' + adj[i][0].second;
                        } else {
                            ans[i] = '0' + adj[i][1].second;
                        }
                    }
                }
            }
        }
    } else {
        cout << "NO\n";
        return;
    }


    cout << "YES\n";
    for (int i = 1; i <= m; i++) {
        cout << ans[i];
    }
}

int main() {
    Rokba();
    int T = 1;
//    cin >> T;
    while (T--) {
        Solution();
    }
}

					 		 	  		   			 	 				 	