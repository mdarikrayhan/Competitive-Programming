#include<bits/stdc++.h>
using namespace std;

#include<tr2/dynamic_bitset>
using namespace tr2;
using bset = tr2::dynamic_bitset<__uint128_t>;

#define fastio() cout.tie(NULL)

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

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9+7;
const int64_t inf = 0x3f3f3f3f, INF = 1e18, BIG_MOD = 489133282872437279;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// #define int int64_t

const int N = 2e5+5;
const int L = 45;



int32_t main()
{
    int t = 1;
    cin >> t;
    while(t --)
    {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> edge(m + 1);
        for(int i = 1, u, v; i <= m; i ++)
        {
            cin >> u >> v;
            edge[i] = mp(u, v);
        }

        vector<bool> block(m + 1, false);

        auto toggle = [&](int i) -> void
        {
            cout << (block[i] ? "+" : "-") << sp << i << endl;
            cout.flush();
            block[i] = !block[i];
        };
        auto ask = [&](int i) -> bool
        {
            cout << "?" << sp << i << endl;
            cout.flush();

            int x;
            cin >> x;
            return x;
        };

        vector<bool> span(m + 1, false);
        vector<bool> repr(m + 1, false);
        vector<vector<pair<int, int>>> adj(n + 1);

        for(int i = 1; i <= m; i ++)
        {
            bool connected = true;
            auto [u, v] = edge[i];
            toggle(i);

            for(int j = 1; j <= L; j ++)
                connected = connected and ask((RNG() % 2) ? u : v);

            span[i] = !connected;
            if(!connected)
            {
                toggle(i);
                repr[i] = true;
                adj[u].pb(mp(v, i)), adj[v].pb(mp(u, i));
            }
        }
        
        vector<int> tin(n + 1), tout(n + 1);
        int timer = 0;

        auto dfs = [&](int u, int p, auto &&dfs) -> void
        {
            tin[u] = ++ timer;

            for(auto [v, i] : adj[u])
                if(v != p)
                    dfs(v, u, dfs);

            tout[u] = ++ timer;
        };
        dfs(1, 0, dfs);

        for(int i = 1; i <= m; i ++)
            if(!span[i])
            {
                auto [u, v] = edge[i];

                int j;
                for(auto [w, i] : adj[u])
                {
                    if(tin[u] <= tin[w] and tout[w] <= tout[u])
                    {
                        if(tin[w] <= tin[v] and tout[v] <= tout[w])
                            j = i;
                    }
                    else
                    {
                        if(tin[u] <= tin[v] and tout[v] <= tout[u])
                            continue;
                        j = i; 
                    }
                }

                toggle(j);
                toggle(i);

                bool connected = true;
                for(int k = 1; k <= L; k ++)
                    connected = connected and ask((RNG() % 2) ? u : v);

                repr[i] = connected;

                toggle(i);
                toggle(j);
            }
        
        cout << "!" << sp;
        for(int i = 1; i <= m; i ++)
            cout << (int)repr[i] << " \n"[i == n];
        cout.flush();
        
        cin >> n;
    }
}