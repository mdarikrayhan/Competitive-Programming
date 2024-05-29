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
const int64_t inf = 1e9, INF = 1e18;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define int int64_t

const int N = 3e2+5;

int n, q;
int a[N];
pair<int, int> go[N];
int on[4][N];
int dp[4][N][N], np[4][N][N];
int mn[4][N][N];

int32_t main()
{
    fastio();

    fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp)/sizeof(int), INF);
    fill(&np[0][0][0], &np[0][0][0] + sizeof(np)/sizeof(int), INF);
    fill(&mn[0][0][0], &mn[0][0][0] + sizeof(mn)/sizeof(int), inf);

    cin >> n >> q;

    a[0] = inf;
    for(int i = 1; i <= q; i ++)    cin >> a[i];

    int ans = 0;

    on[1][0] = on[2][0] = on[3][0] = true;
    for(int i = 1, t, p, x, y; i <= q; i ++)
    {
        cin >> t;

        on[1][i] = on[1][i - 1], on[2][i] = on[2][i - 1], on[3][i] = on[3][i - 1];

        if(t == 1)
        {
            cin >> x >> y;
            go[i] = mp(x, y);
            ans += abs(x - y) * a[i];
        }
        else
        {
            cin >> p;
            on[p][i] ^= 1;
        }
    }

    for(int t = 1; t <= 3; t ++)
        for(int l = 0; l <= q; l ++)
            for(int r = l; r <= q; r ++)
                mn[t][l][r] = min(mn[t][l][r - 1], on[t][r] ? a[r] : inf);

    // dp[]
    go[0] = mp(1, 1);

    int last = 0;
    dp[1][0][0] = dp[2][0][0] = dp[3][0][0] = 0;

    for(int i = 1; i <= q; i ++)    if(go[i] != mp((int)0, (int)0))
    {
        for(int a = 0; a <= last; a ++)
            for(int b = 0; b <= last; b ++)
            {
                //t = 1
                if(on[1][i])
                    np[1][a][b] = min(np[1][a][b], dp[1][a][b] + abs(go[i].first - go[last].second) * mn[1][last][i]);

                if(on[2][i])
                    np[2][last][b] = min(np[2][last][b], dp[1][a][b] + abs(go[i].first - go[a].second) * mn[2][a][i]);
                
                if(on[3][i])
                    np[3][last][a] = min(np[3][last][a], dp[1][a][b] + abs(go[i].first - go[b].second) * mn[3][b][i]);
                
                //t = 2
                if(on[1][i])
                    np[1][last][b] = min(np[1][last][b], dp[2][a][b] + abs(go[i].first - go[a].second) * mn[1][a][i]);
                
                if(on[2][i])
                    np[2][a][b] = min(np[2][a][b], dp[2][a][b] + abs(go[i].first - go[last].second) * mn[2][last][i]);

                if(on[3][i])
                    np[3][a][last] = min(np[3][a][last], dp[2][a][b] + abs(go[i].first - go[b].second) * mn[3][b][i]);

                //t = 3
                if(on[1][i])
                    np[1][b][last] = min(np[1][b][last], dp[3][a][b] + abs(go[i].first - go[a].second) * mn[1][a][i]);

                if(on[2][i])
                    np[2][a][last] = min(np[2][a][last], dp[3][a][b] + abs(go[i].first - go[b].second) * mn[2][b][i]);

                if(on[3][i])
                    np[3][a][b] = min(np[3][a][b], dp[3][a][b] + abs(go[i].first - go[last].second) * mn[3][last][i]);
            }

        copy(&np[0][0][0], &np[0][0][0] + sizeof(np)/sizeof(int), &dp[0][0][0]);
        fill(&np[0][0][0], &np[0][0][0] + sizeof(np)/sizeof(int), INF);
        last = i;
    }

    int tot = INF;
    for(int t = 1; t <= 3; t ++)
        for(int a = 0; a <= q; a ++)
            for(int b = 0; b <= q; b ++)
                tot = min(tot, dp[t][a][b]);
        
    cout << tot + ans << endl;
}