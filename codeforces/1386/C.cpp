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

int ceil_div(int x, int y)  {return (x + y - 1)/y;}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// #define int int64_t

const int MAXN = 2e5+5;

struct dsu_save
{
    int u, v, vs;

    dsu_save(int u, int v, int vs) : u(u), v(v), vs(vs) {}; 
};
struct dsu_with_rollbacks
{
    vector<pair<int, int>> parent;
    vector<int> siz;

    vector<dsu_save> op;

    void init(int n)
    {
        parent.resize(n + 1);
        siz.resize(n + 1);

        for(int i = 0; i <= n; i ++)    parent[i] = mp(i, 0), siz[i] = 1;
    }

    pair<int, int> find_set(int v) 
    {
        int res = 0;
        while(parent[v].first != v)
        {
            res ^= parent[v].second;
            v = parent[v].first;
        }
        return mp(v, res);
    }

    bool add_edge(int a, int b) 
    {
        pair<int, int> xa = find_set(a);
        pair<int, int> xb = find_set(b);

        if(xa.first == xb.first)
        {
            op.pb(dsu_save(0, 0, 0));
            return (xa.second != xb.second);
        }

        if(siz[xa.first] < siz[xb.first])   swap(xa, xb);

        op.pb(dsu_save(xa.first, xb.first, siz[xb.first]));

        siz[xa.first] += siz[xb.first];
        parent[xb.first] = mp(xa.first, (xa.second == xb.second));

        return true;
    }

    void rollback()
    {
        if(op.empty())  return;
        auto c = op.back();
        op.pop_back();

        if(c.u == -1)   return;

        siz[c.u] -= siz[c.v];
        parent[c.v] = mp(c.v, 0);
    }

    void show()
    {
        vector<pair<int, int>> a;
        for(auto x : op)    a.pb(mp(x.u, x.v));
        debug(a);
    }
}dsu;

int n, m, q;

vector<int> adj[MAXN], col(MAXN, 0);

pair<int, int> e[MAXN];
vector<int> opt(MAXN, MAXN);

bool put(int l, int r)
{
    for(int i = l; i <= r; i ++)
    {
        if(!dsu.add_edge(e[i].first, e[i].second))
        {
            for(int j = i; j >= l; j --)
                dsu.rollback();
            return false;
        }
    }
    return true;
}
void rem(int l, int r)
{
    for(int i = l; i <= r; i ++)
        dsu.rollback();
}


int32_t main()
{
    fastio();

    cin >> n >> m >> q;
    for(int i = 1, u, v; i <= m; i ++)    cin >> u >> v, adj[u].pb(v), adj[v].pb(u), e[i] = mp(u, v);

    bool bip = true;
    auto dfs = [&](int u, int c, auto &&dfs) -> void
    {
        col[u] = c;
        for(auto v : adj[u])
        {
            if(col[v] == 0)
                dfs(v, c ^ 3, dfs);
            else if(col[v] == c) 
                    bip = false; 
        }
    };
    for(int i = 1; i <= n; i ++)
        if(col[i] == 0)
            dfs(i, 1, dfs);
    if(bip)
    {
        for(int i = 1; i <= q; i ++)    cout << "NO" << endl;
        exit(0);
    }

    dsu.init(n);

    auto go = [&](int l, int r, int rb_l, int rb_r, auto &&go) -> void
    {
        if(l > r)   return;
        //contains edges from 1 to l - 1 and rb_r to n + 1

        int mid = (l + r) >> 1;

        if(!put(l, mid - 1))            //emergency left
        {
            go(l, mid - 1, rb_l, rb_r, go);
            return;
        }

        int bound = rb_r - 1;
        while(bound >= rb_l)
        {
            if(!dsu.add_edge(e[bound].first, e[bound].second))
            {
                dsu.rollback();
                break;
            }
            -- bound;
        }
        ++ bound;
        opt[mid] = bound;

        rem(bound, rb_r - 1);

        if(l < r and put(mid, mid))         //go right
        {
            go(mid + 1, r, bound, rb_r, go);
            rem(mid, mid);
        }

        rem(l, mid - 1);
        if(l < r and put(bound, rb_r - 1))  //go left
        {
            go(l, mid - 1, rb_l, bound, go);
            rem(bound, rb_r - 1);
        }
    };
    go(1, m, 1, m + 1, go);

    for(int i = 1, l, r; i <= q; i ++)
    {
        cin >> l >> r;
        cout << (r < opt[l] - 1 ? "YES" : "NO") << endl;
    }
}