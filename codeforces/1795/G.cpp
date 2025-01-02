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

const int N = 1e5+5;
const int L = 64;

int n, m;
int tim[N];
int64_t anc[N];

int32_t main()
{
    fastio();
    int t;
    cin >> t;
    while(t --)
    {
        cin >> n >> m;

        vector<int> a(n + 1);
        for(int i = 1; i <= n; i ++)    cin >> a[i];

        vector<int> d(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for(int i = 1, u, v; i <= m; i ++)  cin >> u >> v, ++ d[u], adj[u].pb(v), ++ d[v], adj[v].pb(u);

        int64_t ans = 0;

        vector<int> id(n + 1, 0), rid(n + 1, 0);
        vector<bool> vis(n + 1, false);
        
        for(int u = 1; u <= n; u ++)    if(!vis[u])
        {
            vector<int> root, comp;

            int timer = 0;

            auto dfs = [&](int u, auto &&dfs) -> void
            {
                vis[u] = true;
                comp.pb(u);
                id[u] = ++ timer;
                rid[id[u]] = u;

                if(d[u] == a[u])
                    root.pb(u);

                for(auto v : adj[u])
                    if(!vis[v])
                        dfs(v, dfs);
            };
            dfs(u, dfs);

            int n = comp.size();
            vector<int> in(n + 1, 0);
            vector<bool> bis(n + 1, false);
            vector<vector<int>> adj2(n + 1);

            queue<int> q;
            for(auto r : root)  q.push(r), bis[id[r]] = true;

            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                for(auto v : adj[u])
                    if(!bis[id[v]])
                    {
                        -- d[v];
                        ++ in[id[v]];
                        adj2[id[u]].pb(id[v]);

                        if(d[v] == a[v])
                        {
                            bis[id[v]] = true;
                            q.push(v);
                        }
                    }
            }

            for(auto r : root)
            {
                ++ in[id[r]];
                adj2[0].pb(id[r]);
            }

            fill(tim, tim + n + 2, 0);
            vector<pair<int, int>> edge;

            auto ddfs = [&](int u, auto &&ddfs) -> void
            {
                ++ tim[u];
                if(tim[u] < in[u])  return;
                
                for(auto v : adj2[u])
                {
                    edge.pb(mp(u, v));
                    ddfs(v, ddfs);
                }
            };
            ddfs(0, ddfs);

            int64_t add = 0;
            vector<int> cnt(n + 1, 0);

            for(int i = 1; i <= (n + L - 1)/L; i ++)
            {
                fill(tim, tim + n + 2, 0);
                fill(anc, anc + n + 2, 0);

                int l = (i - 1) * L + 1, r = min(n, i * L);
                for(int u = l; u <= r; u ++)
                    anc[u] |= ((int64_t)1 << (u - l));

                for(auto [u, v] : edge)
                {
                    anc[v] |= anc[u];

                    ++ tim[v];
                    if(tim[v] >= in[v]) cnt[v] += __builtin_popcountll(anc[v]);
                }
            }

            for(int i = 1; i <= n; i ++)
                ans += (n - 1 - 2 * (cnt[i] - 1));

            int64_t sz = comp.size();
            ans += sz * (::n - sz);
        }

        cout << ans/2 << endl;
    }
}

/*
ok, so the relations between adjacent nodes are definitely unique

the adjacent node relationships can be modelled as a unique directed graph (direct the edges)

actually, it will be a dag because everytime we "take" a node, all edges get directed outwards

yeah so we just have to find the number of distinct ancestors for each node

(take care of the weakly disconnected shit seperately)
*/