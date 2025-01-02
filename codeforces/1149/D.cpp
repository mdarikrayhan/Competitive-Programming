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

#define lnt int64_t

const int N = 7e1+5;

int pw(int i)           {return (1 << i);}
bool on(int i, int x)   {return pw(i) & x;}

int n, m, a, b;
vector<vector<int>> adjs(N), adjb(N), store(N);
int sz[N], comp[N], bit[N];

lnt ans[N];
lnt dp[N][1 << (N/4 + 1)];

int32_t main()
{
    fastio();
    
    cin >> n >> m >> a >> b;

    for(int i = 1, u, v, c; i <= m; i ++)
    {
        cin >> u >> v >> c;
        if(c == a)
            adjs[u].pb(v), adjs[v].pb(u);
        else
            adjb[u].pb(v), adjb[v].pb(u);
    }

    int timer = 0, btimer = 0;
    for(int u = 1; u <= n; u ++)    if(comp[u] == 0)
    {
        auto dfs = [&](int u, auto &&dfs) -> void
        {
            comp[u] = timer;
            store[comp[u]].pb(u);
            ++ sz[comp[u]];

            for(auto v : adjs[u])
                if(comp[v] == 0)
                    dfs(v, dfs);
        };

        ++ timer;
        dfs(u, dfs);

        if(sz[comp[u]] > 3)
            bit[comp[u]] = btimer ++;
    }

    for(int u = 1; u <= n; u ++)
    {
        vector<int> mod;
        for(auto v : adjb[u])
            if(comp[u] != comp[v])
                mod.pb(v);
        adjb[u] = mod;
    }

    fill(ans, ans + N, INF);
    for(int u = 1; u <= n; u ++)
        fill(dp[u], dp[u] + (1 << (N/4 + 1)), INF);

    dp[1][0] = 0;
    for(int mask = 0; mask < pw(btimer); mask ++)
    {
        //inter/intra-component, mask not affected
        set<pair<lnt, int>> q;
        for(int u = 1; u <= n; u ++)
            if(sz[comp[u]] <= 3)
                q.insert(mp(dp[u][mask], u));
            
        while(!q.empty())
        {
            auto [_, u] = *q.begin();
            q.erase(q.begin());

            for(auto v : adjs[u])
                if(dp[v][mask] > dp[u][mask] + a)
                {
                    q.erase(mp(dp[v][mask], v));
                    dp[v][mask] = dp[u][mask] + a;
                    q.insert(mp(dp[v][mask], v));
                }

            for(auto v : adjb[u])
            {
                if(sz[comp[v]] <= 3)
                {
                    if(dp[v][mask] > dp[u][mask] + b)
                    {
                        q.erase(mp(dp[v][mask], v));
                        dp[v][mask] = dp[u][mask] + b;
                        q.insert(mp(dp[v][mask], v));
                    }
                }
                else
                {
                    if(!on(bit[comp[v]], mask))
                        dp[v][mask] = min(dp[v][mask], dp[u][mask] + b);
                }
            }
        }

        //intra-component, mask not affected 
        for(int c = 1; c <= timer; c ++)    if(sz[c] > 3)
        {
            set<pair<lnt, int>> q;
            for(auto u : store[c])
                q.insert(mp(dp[u][mask], u));
            
            while(!q.empty())
            {
                auto [_, u] = *q.begin();
                q.erase(q.begin());

                for(auto v : adjs[u])
                {
                    if(dp[v][mask] > dp[u][mask] + a)
                    {
                        q.erase(mp(dp[v][mask], v));
                        dp[v][mask] = dp[u][mask] + a;
                        q.insert(mp(dp[v][mask], v));
                    }
                }
            }
        }

        //inter-component        
        for(int u = 1; u <= n; u ++)    if(sz[comp[u]] > 3)
        {
            if(on(bit[comp[u]], mask)) continue;

            //exiting
            for(auto v : adjb[u])
                if(sz[comp[v]] <= 3 or !on(bit[comp[v]], mask))
                    dp[v][mask | pw(bit[comp[u]])] = min(dp[v][mask | pw(bit[comp[u]])], dp[u][mask] + b);
        }

        for(int u = 1; u <= n; u ++)
            ans[u] = min(ans[u], dp[u][mask]);
    }

    for(int u = 1; u <= n; u ++)
        cout << ans[u] << sp;
    cout << endl;
}
