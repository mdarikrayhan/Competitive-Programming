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

const int N = 3e2+5;

int n, m;
int a[N][N];
set<int> rm, cm;

bool took_row[N], took_col[N];
int f[N][N];

int cnt[N][N];
vector<pair<int, int>> av;      //2 sides taken

int32_t main()
{
    fastio();
    cin >> n >> m;

    for(int r = 1; r <= n; r ++)
        for(int c = 1; c <= m; c ++)
            cin >> a[r][c];

    for(int r = 1; r <= n; r ++)
    {
        int mx = 0;
        for(int c = 1; c <= m; c ++)
            mx = max(mx, a[r][c]);
        rm.insert(mx);
    }
    for(int c = 1; c <= m; c ++)
    {
        int mx = 0;
        for(int r = 1; r <= n; r ++)
            mx = max(mx, a[r][c]);
        cm.insert(mx);
    }

    auto mark_around = [&](int x, int y) -> void
    {
        cnt[x][y] = 100;
        took_row[x] = took_col[y] = true;

        for(int dx = -1; dx <= 1; dx ++)
            for(int dy = -1; dy <= 1; dy ++)
                if(abs(dx + dy) == 1)
                    if(1 <= x + dx and x + dx <= n and 1 <= y + dy and y + dy <= m)
                    {
                        ++ cnt[x + dx][y + dy];
                        if(cnt[x + dx][y + dy] == 2)
                            av.pb(mp(x + dx, y + dy));                        
                    }
    };

    bool can = true;
    for(int x = n * m; x >= 1; x --)
    {
        bool rmx = rm.count(x), cmx = cm.count(x);

        if(rmx and cmx)
        {
            pair<int, int> opt = mp(-1, -1);

            for(int r = 1; r <= n; r ++)
                for(int c = 1; c <= m; c ++)
                    if(!took_row[r] and !took_col[c])
                        opt = mp(r, c);

            auto [p, q] = opt;
            if(p == -1)
            {
                can = false;
                break;
            }

            f[p][q] = x;
            mark_around(p, q);
        }
        else if(rmx)
        {
            pair<int, int> opt = mp(-1, -1);

            for(int r = 1; r <= n; r ++)
                for(int c = 1; c <= m; c ++)
                    if(!took_row[r] and cnt[r][c] == 1)
                        opt = mp(r, c);

            auto [p, q] = opt;
            if(p == -1)
            {
                can = false;
                break;
            }

            f[p][q] = x;
            mark_around(p, q);
        }
        else if(cmx)
        {
            pair<int, int> opt = mp(-1, -1);

            for(int r = 1; r <= n; r ++)
                for(int c = 1; c <= m; c ++)
                    if(!took_col[c] and cnt[r][c] == 1)
                        opt = mp(r, c);

            auto [p, q] = opt;
            if(p == -1)
            {
                can = false;
                break;
            }

            f[p][q] = x;
            mark_around(p, q);
        }
        else
        {
            if(av.empty())
            {
                can = false;
                break;
            }

            auto [p, q] = av.back();
            av.pop_back();

            mark_around(p, q);
            f[p][q] = x;
        }
    }

    if(!can)
    {
        cout << -1 << endl;
        exit(0);
    }

    for(int r = 1; r <= n; r ++)
        for(int c = 1; c <= m; c ++)
            cout << f[r][c] << " \n"[c == m];
}