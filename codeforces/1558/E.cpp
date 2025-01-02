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
#define i64 int64_t

const int N = 2e5+5;




int32_t main()
{
    fastio();
    int t;
    cin >> t;
    while(t --)
    {
        int n, m;
        cin >> n >> m;

        vector<i64> a(n + 1), b(n + 1);
        for(int i = 2; i <= n; i ++)    cin >> a[i];
        for(int i = 2; i <= n; i ++)    cin >> b[i];

        vector<vector<int>> adj(n + 1);
        for(int i = 1, u, v; i <= m; i ++)  cin >> u >> v, adj[u].pb(v), adj[v].pb(u);

        auto ok = [&](int x) -> bool
        {
            vector<int> up(n + 1, 0);
            vector<bool> vis(n + 1, false), out(n + 1, false);
            vector<i64> val(n + 1, 0);
            vector<vector<bool>> par(n + 1, vector<bool> (n + 1, false));

            val[1] = x;
            vis[1] = out[1] = true;
            par[1][1] = true;

            set<int> unvis;
            for(int i = 2; i <= n; i ++)    unvis.insert(i);

            while(!unvis.empty())
            {
                vector<bool> release(n + 1, false);
                bool found = false;

                queue<int> q;

                for(int i = 1; i <= n; i ++)
                    if(vis[i])
                        q.push(i);

                while(!q.empty() and !found)
                {
                    int u = q.front();
                    q.pop();

                    for(auto v : adj[u])
                    {
                        if(val[u] <= a[v] or v == up[u] or found)  continue;

                        if(vis[v]) 
                        {
                            if(out[u] and out[v] or up[v] == u)   continue;

                            for(int i = 1; i <= n; i ++)    release[i] = par[u][i] or par[v][i];
                            found = true;
                            break;
                        }
                        else
                        {
                            vis[v] = true;
                            up[v] = u;
                            q.push(v);

                            par[v] = par[u];
                            par[v][v] = true;

                            val[v] = val[u] + b[v];
                        }
                    }
                }

                if(!found)  break;

                for(int i = 1; i <= n; i ++)
                    if(release[i] and !out[i])
                    {
                        out[i] = true;
                        unvis.erase(i);

                        for(int j = 1; j <= n; j ++)
                            if(vis[j] and !par[j][i])
                                par[j][i] = true, val[j] += b[i];
                    }
            };

            return unvis.empty();
        };

        int s = 0, e = 1e9, ans = 1 + (int)1e9;

        while(s <= e)
        {
            int mid = (s + e) >> 1;
            if(ok(mid)) e = mid - 1, ans = mid;
            else    s = mid + 1;
        }
        
        cout << ans << endl;
    }
}