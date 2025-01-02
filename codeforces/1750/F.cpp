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

const int N = 5e3+5;

int n, m;
int pw[N], way[N];

int _dp[N][2 * N];
int &dp(int i, int x)   {_dp[i][x + N] %= m; return _dp[i][x + N];}


int32_t main()
{
    fastio();
    cin >> n >> m;

    pw[0] = 1;
    for(int i = 1; i <= n; i ++)    pw[i] = (pw[i - 1] * 2) % m;

    way[0] = 1;
    for(int x = 0; x <= n; x ++)    dp(0, x) += 1;

    for(int i = 1; i <= n; i ++)
    {
        for(int last = -n; last <= n; last ++)   dp(i, last - 1) += (dp(i - 1, last) - dp(i - 1, last - 1) + m) % m;

        for(int x = 1; x < i; x ++)
            dp(i, x) += ((-(i - x) > -(x + 1) ? 1 : dp(i - x, -x - 1)) * (int64_t)way[x]) % m;

        for(int x = -n; x < i; x ++)
            dp(i, x) += dp(i, x - 1);
        
        way[i] = (pw[i] - dp(i, i - 1) + m) % m;

        for(int x = i; x <= n; x ++)    
            dp(i, x) = (dp(i, i - 1) + way[i]) % m;
    }

    cout << way[n] << endl;
}