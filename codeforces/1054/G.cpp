#include<bits/stdc++.h>
using namespace std;

#include<tr2/dynamic_bitset>
using namespace tr2;
using bset = tr2::dynamic_bitset<>;

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




int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t --)
    {
        int n, m;
        cin >> n >> m;

        vector<bset> a(n, bset(m));
        vector<int> c(n, 0);

        for(int j = 0; j < m; j ++)
        {
            string s;
            cin >> s;

            for(int i = 0; i < n; i ++)
                a[i][j] = (s[i] == '1'), c[i] += a[i][j];
        }


        bset tree(m);
        vector<int> f(n, 0);        
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);

        for(int j = 0; j < m; j ++)
            if(a[0][j])
            {
                tree[j] = 1;
                for(int i = 0; i < n; i ++)
                    if(a[i][j])
                        ++ f[i];
            }
        
        vis[0] = true;
        
        set<pair<int, int>> q;
        for(int i = 1; i < n; i ++)
            q.insert(mp(f[i], i));
        
        vector<pair<int, int>> edge;
        while(!q.empty())
        {
            auto [_, i] = *q.rbegin();
            q.erase(mp(_, i));

            vis[i] = true;
            bset sub(m);

            for(int j = 0; j < m; j ++)
            {
                if(a[i][j])
                {
                    if(tree[j])
                        sub[j] = true;
                    else
                    {
                        for(int k = 0; k < n; k ++)
                            if(!vis[k])
                                if(a[k][j])
                                {
                                    q.erase(mp(f[k], k));
                                    ++ f[k];
                                    q.insert(mp(f[k], k));                                    
                                }
                        tree[j] = true;
                    }
                }
            }

            int par = -1;
            for(int k = 0; k < n and par == -1; k ++)
                if(vis[k] and k != i)
                    if((sub & a[k]) == sub)
                        par = k;

            par = max(par, 0);

            adj[par].push_back(i);
            adj[i].push_back(par);

            edge.push_back(mp(par + 1, i + 1));
        }

        bool done = true;

        for(int j = 0; j < m; j ++)
        {
            int root = -1, cnt = 0;
            for(int i = 0; i < n; i ++)
                if(a[i][j])
                    root = i, ++ cnt;

            if(cnt == 0)
                continue;            

            vector<bool> vis(n, false);
            auto dfs = [&](int u, auto &&dfs) -> void
            {
                vis[u] = true;
                -- cnt;

                for(auto v : adj[u])
                    if(!vis[v] and a[v][j])
                        dfs(v, dfs);
            };
            dfs(root, dfs);

            if(cnt != 0)
                done = false;
        }

        if(!done)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        for(auto [i, j] : edge)
            cout << i << sp << j << endl;
    }
}