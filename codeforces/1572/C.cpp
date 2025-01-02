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

const int N = 2e5+5;




int32_t main()
{
    fastio();
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1), ra = {0};
        vector<vector<int>> store(n + 1);

        for(int i = 1; i <= n; i ++)    cin >> a[i];

        for(int i = 1, j = 1; i <= n; i = j)
        {
            ra.pb(a[i]);
            while(j <= n and a[j] == a[i]) ++ j;
        }

        a = ra;
        int m = a.size() - 1;

        for(int i = 1; i <= m; i ++)
            store[a[i]].pb(i);

        vector<vector<int>> dp(m + 1, vector<int> (m + 1));
        for(int s = 1; s <= m; s ++)
        {
            for(int l = 1, r = s; r <= m; ++ l, ++ r)
            {
                if(l != r)  dp[l][r] = dp[l + 1][r];

                for(auto i : store[a[l]])
                    if(l < i and i <= r)
                        dp[l][r] = max(dp[l][r], 1 + dp[l + 1][i - 1] + dp[i][r]);
            }
        }

        cout << m - 1 - dp[1][m] << endl;
    }
}