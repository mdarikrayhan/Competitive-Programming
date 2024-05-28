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

int ceil_div(int x, int y)
{
    return (x + y - 1)/y;
}

const int N = 2e5+5;

void print(vector<int> v)
{
    int k = v.size();
    cout << k << endl;
    cout.flush();

    for(auto x : v)
        cout << x << sp;
    cout << endl;
    cout.flush();
}

int get()
{
    int x;
    cin >> x;
    return x;
}

int32_t main()
{
    int n;
    cin >> n;

    int on = 0;

    pair<int, int> opt;
    for(int sq = 1; sq <= n; sq ++)
    {
        int tq = ceil_div(n, sq);
        int ans = n - tq - sq + 1;
        opt = max(opt, mp(ans, sq));
    }
    int sq = opt.second, tq = ceil_div(n, sq); 

    vector<int> a(n + 1, false);
    while(on < opt.first)
    {
        int k = sq;

        vector<int> v;
        for(int i = 1, t = 0; i <= n and t < k; i ++)
            if(i % sq != 1 and !a[i])
            {
                a[i] = true;
                v.pb(i);
                ++ on;
                ++ t;
            }

        print(v);

        int s = get();

        if(s == -1)
            assert(0);

        for(int i = 1; i <= k; i ++, s ++)
        {
            if(s > n)
                s -= n;

            on -= a[s];
            a[s] = false;            
        }
    }

    cout << 0 << endl;
    cout.flush();
}
