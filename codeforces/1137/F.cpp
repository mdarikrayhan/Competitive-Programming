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

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9+7;
const int64_t inf = 0x3f3f3f3f, INF = 1e18, BIG_MOD = 489133282872437279;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// #define int int64_t

const int N = 2e5+100, L = 30;

int bit[2 * N];
struct Fenwick          //one indexed
{
    int n;

    Fenwick(int n) 
    {
        this->n = n + 10;
    }

    int sum(int idx) 
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) 
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) 
    {
        for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
    }
};
Fenwick rq(N << 1);


struct node
{
    pair<int, int> mn_l = mp(inf, inf), mn_r = mp(inf, inf);
    node() : mn_l(mp(inf, inf)), mn_r(mp(inf, inf)) {};
};

bool cLazy[8 * N + 5];
int lazy[8 * N + 5];
vector<node> st(8 * N + 5);

struct SegTree
{
    int N;
    SegTree(int n)
    {
        N = n;
    }
    void merge(node &cur, node &l, node &r)
    {
        cur.mn_l = min(l.mn_l, r.mn_l);
        cur.mn_r = min(l.mn_r, r.mn_r);
    }

    // be careful about that one lifting case in range add, range max qr for ex
    void propagate(int ver, int L, int R)
    {
        if (L != R) // passing on lazy shit to children
        {
            cLazy[ver * 2] = cLazy[ver * 2 + 1] = 1;
            lazy[ver * 2] = lazy[ver * 2 + 1] = lazy[ver];
        }

        st[ver].mn_l = mp(lazy[ver], L), st[ver].mn_r = mp(lazy[ver], -R);
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

    void Update(int ver, int L, int R, int i, int j, int val)
    {
        if (cLazy[ver])
            propagate(ver, L, R);
        if (j < L || i > R)
            return;
        if (i <= L && R <= j)
        {
            cLazy[ver] = 1, lazy[ver] = val;
            propagate(ver, L, R);
            return;
        }
        int M = (L + R) / 2;
        Update(ver * 2, L, M, i, j, val), Update(ver * 2 + 1, M + 1, R, i, j, val);

        merge(st[ver], st[ver * 2], st[ver * 2 + 1]);
    }

    void pUpdate(int ver, int L, int R, int pos, int val)
    {
        if (cLazy[ver])
            propagate(ver, L, R);
        if (L == R)
        {
            st[ver].mn_l = mp(val, pos), st[ver].mn_r = mp(val, -pos);
            return;
        }
        int M = (L + R) / 2;
        if (pos <= M)
            pUpdate(ver * 2, L, M, pos, val);
        else
            pUpdate(ver * 2 + 1, M + 1, R, pos, val);

        if(cLazy[ver*2])  propagate(ver*2, L, M);
        if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

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
    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }
    void update(int l, int r, int val)
    {
        Update(1, 1, N, l, r, val);
    }
};
SegTree cq(N << 1);


int n, q, root;
vector<int> adj[N];

//paths
int mx[N], p[N], rev[N << 1], dep[N];

//lca
int timer = 0;
int tin[N], tout[N], jump[N][L];


void dfs(int u, int p)
{
    tin[u] = ++ timer;

    jump[u][0] = p;
    for(int i = 1; i < L; i ++) jump[u][i] = jump[jump[u][i - 1]][i - 1];

    mx[u] = u;

    for(auto v : adj[u])
        if(v != p)
            dep[v] = dep[u] + 1, dfs(v, u), mx[u] = max(mx[u], mx[v]);
    
    rq.add(mx[u], 1);
        
    tout[u] = ++ timer;
}

bool is_ancestor(int par, int node)
{
    return (tin[par] <= tin[node] and tout[node] <= tout[par]); 
}
int lca(int u, int v)
{
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for(int i = L - 1; i >= 0; i --)
        if(!is_ancestor(jump[u][i], v))
            u = jump[u][i];
    
    return jump[u][0];
}
int dis(int u, int v)
{
    return (dep[u] + dep[v] - 2 * dep[lca(u, v)]); 
}


int sub[N], par[N], val[N], head[N], sid[N];
bool heavy[N];

struct HLD
{
    int n;

    // for heavy paths
    int timer = 0;


    void init(int N)
    {
        n = N;
    }
    
    void build(int root)
    {
        vector<pair<int, int>> heavy_child(n + 5, mp(0, -1));

        function<void(int)> structure = [&](int u)
        {
            sub[u] = 1;

            for(auto v : adj[u])
                if(v != par[u])
                    par[v] = u, structure(v), sub[u] += sub[v], heavy_child[u] = max(heavy_child[u], mp(sub[v], v));
            
            if(heavy_child[u].second != -1)    heavy[heavy_child[u].second] = 1;
        };
        structure(root);

        for(int h = 1; h <= n; h ++)
        {
            if(heavy[h])
            {
                if(heavy[par[h]])   continue;

                int u = h, v = h;

                while(v != -1)
                {
                    head[v] = h, sid[v] = ++ timer;

                    cq.update(sid[v], mx[v]);

                    v = heavy_child[v].second;
                }
            }
            else
            {
                val[h] = mx[h];
            }
        }
    }

    void set_on_segment(int l, int r, int x)
    {
        auto qr = cq.query(l, r);

        while(qr.mn_l.first < x)
        {
            int y = qr.mn_l.first, a = qr.mn_l.second, b = -qr.mn_r.second;
            
            rq.add(y, -(b - a + 1));
            cq.update(a, b, x);
            rq.add(x, b - a + 1);

            qr = cq.query(l, r);
        }
    }

    void update(int u, int v, int x)
    {
        int l = lca(u, v);
        
        vector<int> b = {u, v};

        for(auto w : b)
        {
            while(w != par[l])
            {
                if(heavy[w])
                {
                    if(is_ancestor(head[w], l))
                    {                    
                        set_on_segment(sid[l], sid[w], x);
                        w = par[l];
                    }
                    else
                    {
                        set_on_segment(sid[head[w]], sid[w], x);
                        w = par[head[w]];
                    }
                }
                else
                {
                    rq.add(val[w], -1);
                    val[w] = x;
                    rq.add(val[w], +1);
                    w = par[w];
                }
            }
        }
    }

    int query(int u)
    {
        if(!heavy[u])   return val[u];

        return cq.query(sid[u]).mn_l.first;
    }
}hld;


void up(int v, int x)
{
    hld.update(root, v, p[root]);

    root = v, p[v] = x, rev[x] = v;

    hld.update(root, root, p[root]);
}
int when(int v)
{
    int color = hld.query(v);

    if(color == p[root])
        return rq.sum(1, color) - dis(v, root);

    return (color > 1 ? rq.sum(1, color - 1) : 0) + 1 + dis(v, rev[color]);
}



int32_t main()
{
    fastio();
    
    cin >> n >> q;
    for(int i = 1, u, v; i < n; i ++)   cin >> u >> v, adj[u].pb(v), adj[v].pb(u);

    tin[0] = 0;
    dep[n] = 1, dfs(n, 0);
    tout[0] = ++ timer;

    for(int i = 1; i <= n; i ++)    p[i] = rev[i] = i;
    root = n;

    hld.init(n);
    hld.build(n);

    for(int i = 1, u, v; i <= q; i ++)
    {
        string s;
        cin >> s;

        if(s == "up")
        {
            cin >> v;
            up(v, n + i);
        }
        else if(s == "when")
        {
            cin >> v;
            cout << when(v) << endl;
        }
        else if(s == "compare")
        {
            cin >> v >> u;
            cout << (when(v) < when(u) ? v : u) << endl;
        }
    }
}