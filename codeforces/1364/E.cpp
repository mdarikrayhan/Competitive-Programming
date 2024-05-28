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

const int N = 2e5+5;




int32_t main()
{
    int n;
    cin >> n;

    vector<int> p(n);
    iota(all(p), 0);
    shuffle(all(p), RNG);

    int q = 0;
    auto ask = [&](int i, int j) -> int
    {
        ++ q;
        ++ i, ++ j;

        cout << "?" << sp << i << sp << j << endl;
        cout.flush();

        int x;
        cin >> x;

        return x;
    };
    auto get = [&](int l, int r) -> int
    {
        return (l + RNG() % (r - l + 1));
    };

    int leader;
    {
        int a = get(0, n - 1), b = get(0, n - 1);

        while(1)
        {
            while(a == b)
                a = get(0, n - 1), b = get(0, n - 1);

            int val = ask(a, b);
            if(__builtin_popcount(val) <= 6)
            {
                leader = a;
                break;
            }
            a = get(0, n - 1), b = get(0, n - 1);           
        }
    }

    int mn = inf;
    vector<int> g;
    for(int i = 0; i < n; i ++)
    {
        if(i == leader)
            continue;

        int val = ask(leader, i);

        if(val < mn)
        {
            mn = val;
            g.clear();
        }

        if(val == mn)
            g.pb(i);
    }
    
    if(g.size() == 1)
        g.pb(leader);
    

    while(g.size() > 2)
    {
        shuffle(all(g), RNG);

        int leader = g.front();

        int mn = inf;
        vector<int> _g;

        for(auto i : g)
        {
            if(i == g.front())  continue;

            int val = ask(g.front(), i);

            if(val < mn)
            {
                mn = val;
                _g.clear();
            }

            if(val == mn)
                _g.pb(i);
        }

        if(_g.size() == 1)
            _g.pb(leader);

        g = _g;
    }

    for(int a = g[0], b = g[1]; 1; )
    {
        int x = get(0, n - 1);

        while(x == a or x == b)
            x = get(0, n - 1);
        
        int ax = ask(a, x), bx = ask(b, x);

        if(ax == bx)
            continue;
        else if(ax < bx)
            leader = a;
        else if(bx < ax)
            leader = b;
        break;
    }

    vector<int> f(n);
    
    for(int i = 0; i < n; i ++)
    {
        if(i == leader)
        {
            f[i] = 0;
            continue;
        }

        f[i] = ask(i, leader);
    }

    cout << "!" << sp;
    for(auto x : f)
        cout << x << sp;
    
    cout << endl;
    cout.flush();
}