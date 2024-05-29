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

const int MAXN = 6e2+5, MAXQ = 4e6+5;

// O(a(n)) operations 
pair<int, int> par[MAXN][MAXN];
int siz[MAXN][MAXN];

struct DSU
{
    void init(int n, int m)
    {
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
                par[i][j] = mp(i, j), siz[i][j] = 1;
    }
    
    pair<int, int> get(int x, int y)
    {
        if (par[x][y] == mp(x, y)) return mp(x, y);
        return par[x][y] = get(par[x][y].first, par[x][y].second);
    }

    void unite(pair<int, int> x, pair<int, int> y)
    {
        x = get(x.first, x.second), y = get(y.first, y.second);
        if(siz[x.first][x.second] > siz[y.first][y.second]) swap(x, y);
        par[x.first][x.second] = y;
        siz[y.first][y.second] += siz[x.first][x.second];
    }
}dsu;


int n, m, q;
int ans[MAXQ];
int64_t add[MAXN];

int nxt[MAXN][MAXN];
bool vis[MAXN][MAXN];
pair<int, int> bound[MAXQ];
vector<pair<int, int>> store[MAXQ];
vector<pair<int, int>> qr[MAXN][MAXN];


int32_t main()
{
    fastio();
    fill(bound, bound + MAXQ, mp(inf, -inf));

    cin >> n >> m >> q;

    dsu.init(n, m);

    bound[0] = mp(0, 0);
    for(int i = 1, x, c, y; i <= q; i ++)
    {
        cin >> x >> y >> c;

        bound[c] = mp(min(bound[c].first, i), i);

        store[c].pb(mp(x, y));
        if(qr[x][y].empty() or qr[x][y].back().second != c)
            qr[x][y].pb(mp(i, c));
    }

    for(int i = 1; i <= n; i ++)    
        for(int j = 1; j <= m; j ++)
            qr[i][j].push_back(mp(q + 1, 0)), reverse(all(qr[i][j])), store[0].push_back(mp(i, j));

    for(int c = 0; c < MAXQ; c ++)  if(!store[c].empty())
    {
        int comp = 0;
        if(c != 0)
        {
            for(int i = 0; i < store[c].size(); i ++)
            {
                int x = store[c][i].first, y = store[c][i].second;

                if(vis[x][y])
                {
                    add[bound[c].first + i] += comp;
                    add[bound[c].first + i + 1] -= comp;
                    continue;
                }

                ++ comp;
                vis[x][y] = true;

                if(vis[x - 1][y] and dsu.get(x, y) != dsu.get(x - 1, y))    -- comp, dsu.unite(mp(x, y), mp(x - 1, y));
                if(vis[x + 1][y] and dsu.get(x, y) != dsu.get(x + 1, y))    -- comp, dsu.unite(mp(x, y), mp(x + 1, y));
                if(vis[x][y - 1] and dsu.get(x, y) != dsu.get(x, y - 1))    -- comp, dsu.unite(mp(x, y), mp(x, y - 1));
                if(vis[x][y + 1] and dsu.get(x, y) != dsu.get(x, y + 1))    -- comp, dsu.unite(mp(x, y), mp(x, y + 1));

                add[bound[c].first + i] += comp;
                add[bound[c].first + i + 1] -= comp;
            }
            for(auto cell : store[c])
            {
                int x = cell.first, y = cell.second;
                vis[x][y] = false;
                par[x][y] = mp(x, y);
                siz[x][y] = 1;
            }
        }

        sort(all(store[c]));
        store[c].erase(unique(store[c].begin(), store[c].end()), store[c].end());

        for(auto cell : store[c])
        {
            int x = cell.first, y = cell.second;
            nxt[x][y] = qr[x][y].back().first;
            qr[x][y].pop_back();
        }

        sort(all(store[c]), [&](pair<int, int> a, pair<int, int> b) {return nxt[a.first][a.second] > nxt[b.first][b.second];});

        comp = 0;

        int b = store[c].size();
        for(int i = 0; i < b; i ++)
        {
            ++ comp;

            int x = store[c][i].first, y = store[c][i].second;
            vis[x][y] = true;

            if(vis[x - 1][y] and dsu.get(x, y) != dsu.get(x - 1, y))    -- comp, dsu.unite(mp(x, y), mp(x - 1, y));
            if(vis[x + 1][y] and dsu.get(x, y) != dsu.get(x + 1, y))    -- comp, dsu.unite(mp(x, y), mp(x + 1, y));
            if(vis[x][y - 1] and dsu.get(x, y) != dsu.get(x, y - 1))    -- comp, dsu.unite(mp(x, y), mp(x, y - 1));
            if(vis[x][y + 1] and dsu.get(x, y) != dsu.get(x, y + 1))    -- comp, dsu.unite(mp(x, y), mp(x, y + 1));
            
            int lb = (i == b - 1 ? bound[c].second + 1 : nxt[store[c][i + 1].first][store[c][i + 1].second]);
            int rb = nxt[x][y] - 1;           

            if(lb <= rb)
            {
                add[lb] += comp;
                add[rb + 1] -= comp;
            }
        }

        for(auto cell : store[c])
        {
            int x = cell.first, y = cell.second;
            vis[x][y] = false;
            par[x][y] = mp(x, y);
            siz[x][y] = 1;
        }
    
    }

    int64_t val = 0;

    for(int i = 1; i <= q; i ++)
    {
        val += add[i];
        cout << val << endl;
    }
}