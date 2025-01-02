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

const int MAXN = 1e3+5;

char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dis[MAXN][MAXN];
pair<int, pair<int, int>> cls[MAXN][MAXN];
pair<int, pair<int, int>> dls[MAXN][MAXN];

void clr(int n, int m)
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            vis[i][j] = (grid[i][j] == '#' ? true : false);
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

        pair<int, int> v;

        int block = 0;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
            {
                cin >> grid[i][j];
                vis[i][j] = false, dis[i][j] = inf;
                cls[i][j] = dls[i][j] = mp(inf, mp(inf, inf));
                if(grid[i][j] == 'V')   v = mp(i, j), vis[i][j] = true;
                if(grid[i][j] == '#')   ++ block, vis[i][j] = true;
            }
        
        vector<pair<int, int>> exit;

        queue<pair<int, int>> q;
        q.push(v);
        vis[v.first][v.second] = true;
        dis[v.first][v.second] = 0;

        while(!q.empty())
        {
            auto c = q.front();
            q.pop();

            int x = c.first, y = c.second;

            if(x != 1 and !vis[x - 1][y])
                vis[x - 1][y] = true, dis[x - 1][y] = dis[x][y] + 1, q.push(mp(x - 1, y));
            if(x != n and !vis[x + 1][y])
                vis[x + 1][y] = true, dis[x + 1][y] = dis[x][y] + 1, q.push(mp(x + 1, y));
            if(y != 1 and !vis[x][y - 1])
                vis[x][y - 1] = true, dis[x][y - 1] = dis[x][y] + 1, q.push(mp(x, y - 1));
            if(y != m and !vis[x][y + 1])
                vis[x][y + 1] = true, dis[x][y + 1] = dis[x][y] + 1, q.push(mp(x, y + 1));

            if(x == 1 or x == n or y == 1 or y == m)    exit.pb(mp(x, y));
        }

        if(exit.empty())
        {
            cout << n * m - 1 - block << endl;
            continue;
        }

        clr(n, m);

        set<pair<int, pair<int, int>>> pq;
        for(auto e : exit)  pq.insert(mp(0, e)), cls[e.first][e.second] = mp(0, e), vis[e.first][e.second] = true;

        while(!pq.empty())
        {
            auto c = *pq.begin();
            pq.erase(c);

            int x = c.second.first, y = c.second.second, d = c.first;
            vis[x][y] = true;

            if(x != 1 and !vis[x - 1][y] and cls[x - 1][y].first > cls[x][y].first + 1)
            {
                pq.erase(mp(cls[x - 1][y].first, mp(x - 1, y)));
                cls[x - 1][y] = cls[x][y];
                ++ cls[x - 1][y].first;
                pq.insert(mp(cls[x - 1][y].first, mp(x - 1, y)));
            }
            if(x != n and !vis[x + 1][y] and cls[x + 1][y].first > cls[x][y].first + 1)
            {
                pq.erase(mp(cls[x + 1][y].first, mp(x + 1, y)));
                cls[x + 1][y] = cls[x][y];
                ++ cls[x + 1][y].first;
                pq.insert(mp(cls[x + 1][y].first, mp(x + 1, y)));
            }
            if(y != 1 and !vis[x][y - 1] and cls[x][y - 1].first > cls[x][y].first + 1)
            {
                pq.erase(mp(cls[x][y - 1].first, mp(x, y - 1)));
                cls[x][y - 1] = cls[x][y];
                ++ cls[x][y - 1].first;
                pq.insert(mp(cls[x][y - 1].first, mp(x, y - 1)));
            }
            if(y != m and !vis[x][y + 1] and cls[x][y + 1].first > cls[x][y].first + 1)
            {
                pq.erase(mp(cls[x][y + 1].first, mp(x, y + 1)));
                cls[x][y + 1] = cls[x][y];
                ++ cls[x][y + 1].first;
                pq.insert(mp(cls[x][y + 1].first, mp(x, y + 1)));
            }
        
        }

        if(exit.size() == 1)
        {
            cout << n * m - block - 1 - cls[v.first][v.second].first << endl;
            continue;
        }

        clr(n, m);
        for(int x = 1; x <= n; x ++)
            for(int y = 1; y <= m; y ++)
            if(!vis[x][y])
            {
                if(x != 1 and !vis[x - 1][y] and cls[x - 1][y].first + 1 < dls[x][y].first and cls[x - 1][y].second != cls[x][y].second)
                    dls[x][y] = cls[x - 1][y], ++ dls[x][y].first;
                if(x != n and !vis[x + 1][y] and cls[x + 1][y].first + 1 < dls[x][y].first and cls[x + 1][y].second != cls[x][y].second)
                    dls[x][y] = cls[x + 1][y], ++ dls[x][y].first;
                if(y != 1 and !vis[x][y - 1] and cls[x][y - 1].first + 1 < dls[x][y].first and cls[x][y - 1].second != cls[x][y].second)
                    dls[x][y] = cls[x][y - 1], ++ dls[x][y].first;
                if(y != m  and !vis[x][y + 1] and cls[x][y + 1].first + 1 < dls[x][y].first and cls[x][y + 1].second != cls[x][y].second)
                    dls[x][y] = cls[x][y + 1], ++ dls[x][y].first;

                pq.insert(mp(dls[x][y].first, mp(x, y)));
            }
    
        while(!pq.empty())
        {
            auto c = *pq.begin();
            pq.erase(c);

            int x = c.second.first, y = c.second.second, d = c.first;
            vis[x][y] = true;

            if(x != 1 and !vis[x - 1][y] and dls[x - 1][y].first > dls[x][y].first + 1 and cls[x - 1][y].second != dls[x][y].second)
            {
                pq.erase(mp(dls[x - 1][y].first, mp(x - 1, y)));
                dls[x - 1][y] = dls[x][y];
                ++ dls[x - 1][y].first;
                pq.insert(mp(dls[x - 1][y].first, mp(x - 1, y)));
            }
            if(x != n and !vis[x + 1][y] and dls[x + 1][y].first > dls[x][y].first + 1 and cls[x + 1][y].second != dls[x][y].second)
            {
                pq.erase(mp(dls[x + 1][y].first, mp(x + 1, y)));
                dls[x + 1][y] = dls[x][y];
                ++ dls[x + 1][y].first;
                pq.insert(mp(dls[x + 1][y].first, mp(x + 1, y)));
            }
            if(y != 1 and !vis[x][y - 1] and dls[x][y - 1].first > dls[x][y].first + 1 and cls[x][y - 1].second != dls[x][y].second)
            {
                pq.erase(mp(dls[x][y - 1].first, mp(x, y - 1)));
                dls[x][y - 1] = dls[x][y];
                ++ dls[x][y - 1].first;
                pq.insert(mp(dls[x][y - 1].first, mp(x, y - 1)));
            }
            if(y != m and !vis[x][y + 1] and dls[x][y + 1].first > dls[x][y].first + 1 and cls[x][y + 1].second != dls[x][y].second)
            {
                pq.erase(mp(dls[x][y + 1].first, mp(x, y + 1)));
                dls[x][y + 1] = dls[x][y];
                ++ dls[x][y + 1].first;
                pq.insert(mp(dls[x][y + 1].first, mp(x, y + 1)));
            }
        }
    
    
        int64_t ans = INF;
        for(int x = 1; x <= n; x ++)
            for(int y = 1; y <= m; y ++)
                ans = min(ans, (int64_t)dis[x][y] + (int64_t)cls[x][y].first + (int64_t)dls[x][y].first);

        cout << n * m - block - ans - 1 << endl;
    }
}