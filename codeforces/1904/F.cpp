#include<bits/stdc++.h>
#pragma GCC optimize("03")

using namespace std;

#define ll long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define all(a) a.begin(),a.end()
#define endl "\n"
#define sp " " 
#define pb push_back
#define mp make_pair
#define vecvec(type, name, n, m, value) vector<vector<type>> name(n + 1, vector<type> (m + 1, value))

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
#define debug(x...) {cerr << "[" << #x << "] = ["; _print(x);}
#define reach cerr << "reached" << endl
#else
#define debug(x...)
#define reach 
#endif

const int MOD = 1e9+7;
const int64_t inf = 0x3f3f3f3f, INF = 1e18, BIG_MOD = 489133282872437279;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// #define int int64_t
using i64 = int64_t;
const int N = 2e5+5, L = 23;

struct node
{
    pair<i64, int> mn = mp(INF, INF);
    node() : mn(mp(INF, INF)) {};
};
struct SegTree
{
    int N;
    vector<node> st;
    vector<bool> cLazy;
    vector<i64> lazy;
    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
        cLazy.assign(4 * N + 5, false);
        lazy.assign(4 * N + 5, 0);
    }
    void merge(node &cur, node &l, node &r)
    {
        cur.mn = min(l.mn, r.mn);
    }

    // be careful about that one lifting case in range add, range max qr for ex
    void propagate(int ver, int L, int R)
    {
        if (L != R) // passing on lazy shit to children
        {
            cLazy[ver * 2] = cLazy[ver * 2 + 1] = 1;
            lazy[ver * 2] += lazy[ver], lazy[ver * 2 + 1] += lazy[ver];
        }
        st[ver].mn.first += lazy[ver];
        cLazy[ver] = lazy[ver] = 0;
    }
    node Query(int ver, int L, int R, int i, int j)
    {
        if (cLazy[ver])
            propagate(ver, L, R);
        if (j < L || i > R)
            return node();
        if (i <= L && R <= j)
            return st[ver];
        int M = (L + R) / 2;
        node left = Query(ver * 2, L, M, i, j), right = Query(ver * 2 + 1, M + 1, R, i, j), cur;
        merge(cur, left, right);
        return cur;
    }
    node pQuery(int ver, int L, int R, int pos)
    {
        if (cLazy[ver])
            propagate(ver, L, R);
        if (L == R)
            return st[ver];
        int M = (L + R) / 2;
        if (pos <= M)
            return pQuery(ver * 2, L, M, pos);
        else
            return pQuery(ver * 2 + 1, M + 1, R, pos);
    }
    void Update(int ver, int L, int R, int i, int j, i64 val)
    {
        if (cLazy[ver])
            propagate(ver, L, R);
        if (j < L || i > R)
            return;
        if (i <= L && R <= j)
        {
            cLazy[ver] = 1, lazy[ver] += val;
            propagate(ver, L, R);
            return;
        }
        int M = (L + R) / 2;
        Update(ver * 2, L, M, i, j, val), Update(ver * 2 + 1, M + 1, R, i, j, val);

        // if(cLazy[ver*2])  propagate(ver*2, L, M);
        // if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver], st[ver * 2], st[ver * 2 + 1]);
    }
    void pUpdate(int ver, int L, int R, int pos, pair<i64, int> val)
    {
        if (cLazy[ver])
            propagate(ver, L, R);
        if (L == R)
        {
            st[ver].mn = val;
            return;
        }
        int M = (L + R) / 2;
        if (pos <= M)
            pUpdate(ver * 2, L, M, pos, val);
        else
            pUpdate(ver * 2 + 1, M + 1, R, pos, val);

        // if(cLazy[ver*2])  propagate(ver*2, L, M);
        // if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver], st[ver * 2], st[ver * 2 + 1]);
    }

    node query(int pos)
    {
        return pQuery(1, 1, N, pos);
    }
    node query(int l, int r)
    {
        return Query(1, 1, N, l, r);
    }
    void update(int pos, pair<i64, int> val)
    {
        pUpdate(1, 1, N, pos, val);
    }
    void update(int l, int r, i64 val)
    {
        Update(1, 1, N, l, r, val);
    }
};


int n, m;
queue<int> q;
int p[N], r[N];
bool relieved[N], removed[N];           //relieved => all incoming edges from other nodes min enforces deleted      |       removed => already assigned an index in the topological ordering
vector<vector<int>> adj(N);
vector<array<int, 4>> res(N);

vector<pair<int, int>> upd[N];
priority_queue<pair<int, int>> req[N];

int timer = 0;
int d[N], tin[N], tout[N];
int up[N][L];

void dfs(int u, int p = 0)
{
    tin[u] = ++ timer;

    up[u][0] = p;
    for(int i = 1; i < L; i ++)     up[u][i] = up[up[u][i - 1]][i - 1];
    
    if(p != 0)  adj[u].erase(find(all(adj[u]), p));
    for(auto v : adj[u])
        d[v] = d[u] + 1, dfs(v, u);
    
    tout[u] = ++ timer;
}

bool is_ancestor(int p, int v)    {return tin[p] <= tin[v] and tout[v] <= tout[p];}

int lca(int u, int v)
{
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for(int i = L - 1; i >= 0; i --)
        if(!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

struct HLD
{
    int n;

    // vector<int> adj[MAXN];           //-> just keep this outside
    vector<int> sub, par;

    // for light nodes
    vector<i64> val;       //value of the light node

    // for heavy paths
    int timer = 0;
    vector<bool> heavy;
    vector<int> head, sid;      //head of heavy path, segment tree index (NOTE: less depth => lesser sid for all paths)

    SegTree rq;

    void init(int N)
    {
        n = N;

        rq.init(n);

        sub.assign(n + 5, 0), par.assign(n + 5, 0), val.assign(n + 5, 0), heavy.assign(n + 5, 0), head.assign(n + 5, 0), sid.assign(n + 5, 0);
    }
    
    void build(int root)
    {
        function<void(int)> structure = [&](int u)
        {
            sub[u] = 1;

            pair<int, int> heavy_child = mp(0, -1);
            
            for(auto v : adj[u])
                if(v != par[u])
                    par[v] = u, structure(v), sub[u] += sub[v], heavy_child = max(heavy_child, mp(sub[v], v));
            
            if(heavy_child.second != -1)    heavy[heavy_child.second] = 1;
        };
        structure(root);

        function<void(int, int)> decompose = [&](int u, int h)
        {
            pair<int, int> heavy_child = mp(0, -1);

            head[u] = h, sid[u] = ++ timer;
            for(auto v : adj[u])    
                if(v != par[u]) 
                    heavy_child = max(heavy_child, mp(sub[v], v));

            if(heavy_child.second != -1)    decompose(heavy_child.second, h);
        };
        for(int h = 1; h <= n; h ++)    
            if(heavy[h] and !heavy[par[h]])
                decompose(h, h);
        
        for(int u = 1; u <= n; u ++)
            if(heavy[u])
                rq.update(sid[u], mp(0, u));
    }

    // have lca structure and (range query-range update structure) ready before calling update and query
    void update(int u, int v, i64 x)
    {
        int l = lca(u, v);

        vector<int> b = {u, v};

        for(auto w : b)
        {
            while(w != par[l])
            {
                if(heavy[w])
                {
                    if(is_ancestor(head[w], l))         // gotta make update and jump up
                    {                    
                        rq.update(sid[l], sid[w], +x);
                        w = par[l];
                    }
                    else
                    {
                        rq.update(sid[head[w]], sid[w], +x);
                        w = par[head[w]];
                    }
                }
                else
                {
                    val[w] += x;
                    w = par[w];
                }
            }
        }    

        // l recieved update twice, fix
        if(heavy[l])
            rq.update(sid[l], sid[l], -x);
        else
            val[l] -= x;
    }

    pair<i64, int> query(int u, int v)
    {
        int l = lca(u, v);
        vector<int> b = {u, v};

        pair<i64, int> ans = mp(INF, inf);
        for(auto w : b)
        {
            while(w != par[l])
            {
                if(heavy[w])
                {
                    if(is_ancestor(head[w], l))     // gotta make update and jump up
                    {                    
                        ans = min(ans, rq.query(sid[l], sid[w]).mn);
                        w = par[l];
                    }
                    else
                    {
                        ans = min(ans, rq.query(sid[head[w]], sid[w]).mn);
                        w = par[head[w]];
                    }
                }
                else
                {
                    ans = min(ans, mp(val[w], w));
                    w = par[w];
                }
            }
        }

        return ans;
    }
}hld;

struct DSU
{
    vector<int> par, high;
    vector<vector<int>> keep;

    void init(int n)
    {
        par.resize(n + 1, 0);
        high.resize(n + 1, 0);
        keep.resize(n + 1, vector<int>());
        for(int i = 1; i <= n; i ++)    par[i] = i, high[i] = d[i], keep[i].pb(i);
    }

    void unite(int u, int v)
    {
        u = par[u], v = par[v];

        if(keep[u].size() < keep[v].size()) swap(u, v);
        high[u] = min(high[u], high[v]);

        for(auto x : keep[v])
            par[x] = u, keep[u].pb(x);
        keep[v].clear();

        while(!req[v].empty())  req[u].push(req[v].top()), req[v].pop();
    }
}dsu;

void resolve(int u)
{
    u = dsu.par[u];
    while(!req[u].empty() and req[u].top().first >= dsu.high[u])
    {
        auto [_, c] = req[u].top();
        req[u].pop();
        -- r[c];

        if(r[c] == 0 and relieved[c])   q.push(c);
    }
}

void merge_around(int u)
{
    if(up[u][0] != 0 and removed[up[u][0]])   dsu.unite(up[u][0], u);
    for(auto v : adj[u])
        if(removed[v])
            dsu.unite(u, v);

    resolve(u);
}

void remove(int u)
{
    assert(relieved[u] and r[u] == 0);

    removed[u] = true;
    merge_around(u);

    for(auto [a, b] : upd[u])
    {
        hld.update(a, b, -1);
        hld.update(u, u, +1);

        for(auto qr = hld.query(a, b); qr.first == 0; qr = hld.query(a, b))
        {
            relieved[qr.second] = true;

            if(r[qr.second] == 0)   q.push(qr.second);

            hld.update(qr.second, qr.second, INF);
        }
    }
}

vector<pair<int, int>> get(int a, int b, int c)
{
    assert(a != b);

    int l = lca(a, b);
    vector<pair<int, int>> ret;

    if(c != l)  ret.pb(mp(up[c][0], d[l]));

    if(is_ancestor(c, a))
    {
        if(c != a)
            ret.pb(mp(a, d[c] + 1));
    }
    else    ret.pb(mp(a, d[l]));

    if(is_ancestor(c, b))
    {
        if(c != b)
            ret.pb(mp(b, d[c] + 1));
    }
    else    ret.pb(mp(b, d[l]));
    return ret;
}

int32_t main()
{
    fastio();
    cin >> n >> m;

    for(int i = 1, u, v; i < n; i ++)   cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    dfs(1, 0);
    tin[0] = 0, tout[0] = inf;

    hld.init(n);
    hld.build(1);

    dsu.init(n);

    for(int i = 1, t, a, b, c; i <= m; i ++)
    {
        cin >> t >> a >> b >> c;
        res[i] = {t, a, b, c};

        if(a == b)  continue;

        if(t == 1)
        {
            // min enforce
            hld.update(a, b, +1);
            hld.update(c, c, -1);
            upd[c].pb(mp(a, b));
        }
        else
        {
            //max enforce
            auto paths = get(a, b, c);
            for(auto [end, reach_depth] : paths)
                ++ r[c], req[end].push(mp(reach_depth, c));
        }
    }

    for(int u = 1; u <= n; u ++)
    {
        if(hld.query(u, u).first == 0)
        {
            relieved[u] = true;
            hld.update(u, u, INF);

            if(r[u] == 0)   q.push(u);
        }
    }

    for(int x = 1; x <= n; x ++)
    {
        if(q.empty())
        {
            cout << -1 << endl;
            exit(0);
        }

        int u = q.front();
        q.pop();


        p[u] = x;
        remove(u);
    }

    for(int i = 1; i <= n; i ++)    cout << p[i] << sp;
    cout << endl;
}
