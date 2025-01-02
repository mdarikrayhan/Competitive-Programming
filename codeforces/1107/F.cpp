#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#include<boost/algorithm/string.hpp>

//pragmas
#pragma GCC optimize("O3")

//types
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define vec vector<long long int>
#define pall pair<long long int, long long int>
#define vecpair vector<pair<long long int,long long int>>
#define vecvec(a, i, j) vector<vector<long long int>> a (i, vec (j, 0))
#define vecvecvec(a, i, j, k) vector<vector<vector<long long int>>> dp (i + 1, vector<vector<long long int>>(j + 1, vector<long long int>(k + 1, 0)))

using namespace std;
using namespace __gnu_pbds;

//random stuff
#define all(a) a.begin(),a.end()
#define read(a) for (auto &x : a) cin >> x
#define endl "\n"
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl
#define sz(x) x.size()
#define F first
#define S second
#define sp " " 
const ll INF = 9223372036854775807, MOD = 1e9 + 7;
int inf = 0x3f3f3f3f;
typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define safe_map unordered_map<long long, int, custom_hash>
#define hashmap gp_hash_table<int, int, custom_hash>


//debug
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define reach cerr<<"reached"<<endl
#else
#define debug(x...)
#define reach 
#endif


/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
ll ceil_div(ll x, ll y){return (x + y - 1) / y;}
unsigned long long power(unsigned long long x,ll y, ll p){unsigned long long res = 1;x = x % p; while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;}
unsigned long long modInverse(unsigned long long n,int p){return power(n, p - 2, p);}
ll nCr(ll n,ll r, ll p){if (n < r)return 0;if (r == 0)return 1;unsigned long long fac[n + 1];fac[0] = 1;for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p;return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;}
ll accumulate(const vec &nums){ll sum = 0; for(auto x : nums) sum += x; return sum;}
ll tmax(ll a, ll b, ll c = 0, ll d = -INF, ll e = -INF, ll f = -INF){return max(a, max(b, max(c, max(d, max(e, f)))));}
int log2_floor(unsigned long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
string bin(ll n){return bitset<32>(n).to_string();}
/*--------------------------------------------------------------------------------------------------------------------------*/

const ll MAXN = 1e3;
// tutorial : https://www.topcoder.com/thrive/articles/Assignment%20Problem%20and%20Hungarian%20Algorithm
// (optimal selection, min sum, one from each row and column)
template<typename flow_t, typename cost_t>
struct min_cost_flow {
    static const flow_t FLOW_INF = numeric_limits<flow_t>::max() / 2;
    static const cost_t COST_INF = numeric_limits<cost_t>::max() / 2;
 
    struct edge {
        int node, rev;
        flow_t capacity;
        cost_t cost;
 
        edge(int _node = -1, int _rev = -1, flow_t _capacity = 0, cost_t _cost = 0)
            : node(_node), rev(_rev), capacity(_capacity), cost(_cost) {}
    };
 
    int V = -1;
    vector<vector<edge>> adj;
    vector<cost_t> dist;
    vector<int> prev;
    vector<edge*> prev_edge;
 
    min_cost_flow(int vertices = -1) {
        if (vertices >= 0)
            init(vertices);
    }
 
    void init(int vertices) {
        V = vertices;
        adj.assign(V, {});
        dist.resize(V);
        prev.resize(V);
        prev_edge.resize(V);
    }
 
    void add_directional_edge(int u, int v, flow_t capacity, cost_t cost) {
        edge uv_edge(v, adj[v].size() + (u == v ? 1 : 0), capacity, cost);
        edge vu_edge(u, adj[u].size(), 0, -cost);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
    }
 
    edge &reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }
 
    bool bellman_ford(int source, int sink) {
        for (int i = 0; i < V; i++) {
            dist[i] = COST_INF;
            prev[i] = -1;
            prev_edge[i] = nullptr;
        }
 
        vector<int> last_seen(V, -1);
        vector<int> nodes(1, source);
        dist[source] = 0;
 
        for (int iteration = 0; iteration < V; iteration++) {
            vector<int> next_nodes;
 
            for (int node : nodes)
                for (edge &e : adj[node])
                    if (e.capacity > 0 && dist[node] + e.cost < dist[e.node]) {
                        dist[e.node] = dist[node] + e.cost;
                        prev[e.node] = node;
                        prev_edge[e.node] = &e;
 
                        if (last_seen[e.node] != iteration) {
                            last_seen[e.node] = iteration;
                            next_nodes.push_back(e.node);
                        }
                    }
 
            swap(nodes, next_nodes);
        }
 
        return prev[sink] != -1;
    }
 
    struct dijkstra_state {
        cost_t dist;
        int node;
 
        bool operator<(const dijkstra_state &other) const {
            return dist > other.dist;
        }
    };
 
    void dijkstra_check(int node, cost_t potential_dist, int previous, edge *previous_edge, auto &pq) {
        if (potential_dist < dist[node]) {
            dist[node] = potential_dist;
            prev[node] = previous;
            prev_edge[node] = previous_edge;
            pq.push({dist[node], node});
        }
    }
 
    bool dijkstra(int source, int sink) {
        dist.assign(V, COST_INF);
        prev.assign(V, -1);
        prev_edge.assign(V, nullptr);
 
        priority_queue<dijkstra_state> pq;
        dijkstra_check(source, 0, -1, nullptr, pq);
 
        while (!pq.empty()) {
            dijkstra_state top = pq.top();
            pq.pop();
 
            if (top.dist > dist[top.node])
                continue;
 
            for (edge &e : adj[top.node])
                if (e.capacity > 0)
                    dijkstra_check(e.node, top.dist + e.cost, top.node, &e, pq);
        }
 
        return prev[sink] != -1;
    }
 
    void reduce_cost() {
        for (int i = 0; i < V; i++)
            for (edge &e : adj[i])
                e.cost += dist[i] - dist[e.node];
    }
 
    pair<flow_t, cost_t> solve_min_cost_flow(int source, int sink, flow_t flow_goal = FLOW_INF) {
        assert(V >= 0);
 
        if (!bellman_ford(source, sink))
            return make_pair(0, 0);
 
        flow_t total_flow = 0;
        cost_t total_cost = 0;
        cost_t reduce_sum = 0;
 
        do {
            reduce_cost();
            reduce_sum += dist[sink];
            flow_t path_cap = flow_goal - total_flow;
 
            for (int node = sink; prev[node] != -1; node = prev[node])
                path_cap = min(path_cap, prev_edge[node]->capacity);
 
            for (int node = sink; prev[node] != -1; node = prev[node]) {
                edge *e = prev_edge[node];
                assert(e->cost == 0);
                e->capacity -= path_cap;
                reverse_edge(*e).capacity += path_cap;
            }
 
            total_flow += path_cap;
            total_cost += reduce_sum * path_cap;
        } while (total_flow < flow_goal && dijkstra(source, sink));
 
        return make_pair(total_flow, total_cost);
    }
};
struct assignment_problem {
    int n;
    vector<vector<long long>> costs;
 
    assignment_problem(int _n = -1) : n(_n) {
        if (n > 0)
            costs.assign(n, vector<long long>(n, 0));
    }
 
    template<typename T>
    assignment_problem(const vector<vector<T>> &_costs) {
        build(_costs);
    }
 
    template<typename T>
    void build(const vector<vector<T>> &_costs) {
        n = _costs.size();
        costs.assign(n, vector<long long>(n, 0));
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                costs[i][j] = _costs[i][j];
    }
 
    long long solve() {
        int v = 2 * n + 2, source = v - 2, sink = v - 1;
        min_cost_flow<int, long long> graph(v);
 
        for (int i = 0; i < n; i++) {
            graph.add_directional_edge(source, i, 1, 0);
            graph.add_directional_edge(n + i, sink, 1, 0);
        }
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph.add_directional_edge(i, n + j, 1, costs[i][j]);
 
        return graph.solve_min_cost_flow(source, sink).second;
    }
};

int n;
vector<array<ll, 3>> table(MAXN);


//code starts
int main()
{
    fastio();
    cin >> n;
    assignment_problem a(n);
    for(ll i = 0; i < n; i ++) cin >> table[i][0] >> table[i][1] >> table[i][2];
    for(ll i = 0; i < n; i ++)
        for(ll j = 0; j < n; j ++)
            a.costs[i][j] = -max(table[i][0] - min(table[i][2], j) * table[i][1], 0LL);
    cout << -a.solve() << endl;
}






// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.