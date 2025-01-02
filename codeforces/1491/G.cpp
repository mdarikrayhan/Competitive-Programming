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

int n;
int p[N];
vector<pair<int, int>> op; 

bool vis[N];
vector<int> lone;
vector<vector<int>> cycles;

int32_t main()
{
    fastio();

    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> p[i]; 

    for(int i = 1; i <= n; i ++)    if(!vis[i])
    {
        vector<int> cycle;
        int j = i;
        while(!vis[j])
        {
            vis[j] = true;
            cycle.pb(j);
            j = p[j];
        }

        if(cycle.size() == 1)   lone.pb(i);
        else    cycles.pb(cycle);
    }

    int m = cycles.size();

    auto exchange = [&](int i, int j) -> void
    {
        op.pb(mp(i, j));
    };

    for(int c = 2; c <= m; c += 2)
    {
        auto c1 = cycles[c - 2], c2 = cycles[c - 1];

        exchange(c1.front(), c2.front());
        for(int i = 1; i < c2.size(); i ++)
            exchange(c1.front(), c2[i]);
        for(int i = 1; i < c1.size(); i ++)
            exchange(c2.front(), c1[i]);
        exchange(c1.front(), c2.front());

        for(auto i : c1)
            lone.pb(i);
        for(auto i : c2)
            lone.pb(i);
    }

    if(m % 2)
    {
        auto cycle = cycles.back();

        if(cycle.size() == 2)
        {
            auto other = lone.back();

            exchange(other, cycle.front());
            exchange(other, cycle.back());
            exchange(other, cycle.front());
        }
        else
        {
            exchange(cycle[0], cycle[2]);
            for(int i = 3; i < cycle.size(); i ++)
                exchange(cycle[0], cycle[i]);
            exchange(cycle[0], cycle[1]);
            exchange(cycle[1], cycle[2]);
            exchange(cycle[0], cycle[2]);
        }
    }

    cout << (int)op.size() << endl;
    for(auto [i, j] : op)
        cout << i << sp << j << endl;
}