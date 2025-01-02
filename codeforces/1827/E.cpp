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

const int MAXN = 2e5+5;

// O(a(n)) operations 
struct DSU
{
    vector<int> par, siz;
    void init(int n)
    {
        par.resize(n + 1);
        siz.assign(n + 1, 0);
        for(int i = 1; i <= n; i ++)    par[i] = i, siz[i] = 1;
    }
    
    int get(int x)
    {
        if (par[x] == x) return x;
        return par[x] = get(par[x]);
    }

    void unite(int x, int y)
    {
        x = get(x), y = get(y);
        if(siz[x] > siz[y]) swap(x, y);
        par[x] = y;
        siz[y] += siz[x];
    }
}dsu;

vector<int> get_lca(int n, int m, int root, vector<int> *adj, vector<pair<int, int>> path)
{
    vector<pair<int, int>> queries[n + 1];
    for(int i = 1; i <= m; i ++)
    {
        int a = path[i].first, b = path[i].second;
        queries[a].pb(mp(b, i));
        queries[b].pb(mp(a, i));
    }

    vector<int> ans(m + 1, -1);

    vector<int> ancestor(n + 1);
    vector<bool> visited(n + 1, false);
    
    DSU dsu;
    dsu.init(n);

    function<void(int)> dfs = [&](int v)
    {
        visited[v] = true;
        ancestor[v] = v;
        for (int u : adj[v]) 
        {
            if (!visited[u]) 
            {
                dfs(u);
                dsu.unite(v, u);
                ancestor[dsu.get(v)] = v;
            }
        }
        for (auto other_node : queries[v]) 
            if (visited[other_node.first])
                ans[other_node.second] = ancestor[dsu.get(other_node.first)];
    };
    dfs(root);
    
    return ans;
}

int32_t main()
{
    fastio();
    int t;
    cin >> t;
    while(t --)
    {
        int n, m;
        cin >> n >> m;

        vector<int> adj[n + 1];
        vector<pair<int, int>> path(m + 1);

        for(int i = 1, u, v; i < n; i ++)   cin >> u >> v, adj[u].pb(v), adj[v].pb(u);

        if(n == 2)
        {
            bool done = false;

            for(int i = 1, a, b; i <= m; i ++)
            {
                cin >> a >> b;
                if(a > b)   swap(a, b);
                if(a == 1 and b == 2)   done = true;
            }
            if(!done)
            {
                cout << "NO" << endl;
                cout << 1 << sp << 2 << endl;
                continue;
            }
            cout << "YES" << endl;
            continue;
        }

        int root = -1;
        vector<bool> leaf(n + 1, false);
        for(int u = 1; u <= n; u ++)
        {
            if(adj[u].size() > 1)   root = u;
            else    leaf[u] = true;
        }

        for(int i = 1, a, b; i <= m; i ++)
            cin >> a >> b, path[i] = mp(a, b);

        vector<int> lca = get_lca(n, m, root, adj, path);


        int timer = 0;
        vector<int> dep(n + 1), tin(n + 1), tout(n + 1);
        function<void(int, int)> dfs = [&](int u, int p)
        {
            tin[u] = ++timer;
            for(auto v : adj[u])
                if(v != p)
                    dep[v] = dep[u] + 1, dfs(v, u);
            tout[u] = ++timer;
        };
        dep[root] = 0;
        dfs(root, 0);

        vector<pair<int, int>> high(n + 1, mp(inf, inf));
        vector<int> store[n + 1];

        for(int i = 1; i <= m; i ++)
        {
            int a = path[i].first, b = path[i].second;
            if(leaf[a])
            {
                store[a].pb(b);
                high[a] = min(high[a], mp(dep[lca[i]], lca[i]));
            }
            if(leaf[b])
            {
                store[b].pb(a);
                high[b] = min(high[b], mp(dep[lca[i]], lca[i]));
            }
        }

        vector<pair<int, int>> dep_store[n + 1];

        bool can = true;
        pair<int, int> illegal;

        for(int i = 1; i <= n; i ++)
            if(leaf[i])
            {
                if(high[i].first == inf)
                {
                    can = false;
                    illegal.first = i;
                    break;
                }
                dep_store[high[i].first].pb(mp(high[i].second, i));
            }

        if(!can)
        {
            int other = 0;
            for(int i = 1; i <= n; i ++)
                if(leaf[i] and i != illegal.first)
                    illegal.second = i;
            
            cout << "NO" << endl;
            cout << illegal.first << sp << illegal.second << endl;
            continue;
        }

        vector<pair<int, int>> seq;

        for(int d = n; d >= 0; d --)  if(!dep_store[d].empty())
        {
            int s = (int)dep_store[d].size();

            for(auto u : dep_store[d])
                if(u.first != dep_store[d].back().first)
                {
                    illegal = mp(u.second, dep_store[d].back().second);
                    can = false;
                }

            if(!can)    break;

            seq.pb(dep_store[d].back());
        }

        if(!can)
        {
            cout << "NO" << endl;
            cout << illegal.first << sp << illegal.second << endl;
            continue;
        }

        auto is_anc = [&](int anc, int v) -> bool   {return tin[anc] <= tin[v] and tout[v] <= tout[anc];};

        int s = (int)seq.size();

        for(int i = 0; i < s - 1; i ++)
            if(!is_anc(seq[i + 1].first, seq[i].first))
            {
                illegal = mp(seq[i].second, seq[i + 1].second);
                can = false;
            }

        if(!can)
        {
            cout << "NO" << endl;
            cout << illegal.first << sp << illegal.second << endl;
            continue;
        }

        pair<int, int> special = mp(root, 0);
        if(!seq.empty())
            special = seq.front();

        for(int i = 1; i <= n; i ++)
            if(leaf[i] and !is_anc(special.first, i))
            {
                bool herecan = false;
                for(auto end : store[i])
                    if(is_anc(special.first, end))
                        herecan = true;
                
                if(!herecan)
                {
                    can = false;
                    illegal = mp(special.second, i);
                }
            }
        
        if(!can)
        {
            cout << "NO" << endl;
            cout << illegal.first << sp << illegal.second << endl;
            continue;
        }

        cout << "YES" << endl;
    }
}