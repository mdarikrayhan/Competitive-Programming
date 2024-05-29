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

const int MOD = 998244353;
const int64_t inf = 0x3f3f3f3f, INF = 1e18, BIG_MOD = 489133282872437279;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// #define int int64_t

const int N = 2e5+5;

struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};

int n;

int id[N], par[N];
vector<vector<int>> adj(N);
map<pair<int, int>, int> edge;

Mint dp[N][3];

int32_t main()
{
    fastio();
    cin >> n;

    for(int i = 1, u, v; i < n; i ++)   cin >> u >> v, adj[u].pb(v), adj[v].pb(u), edge[mp(u, v)] = edge[mp(v, u)] = i;

    auto dfs = [&](int u, auto &&dfs) -> void
    {
        for(auto v : adj[u])
            if(v != par[u])
                par[v] = u, id[v] = edge[mp(u, v)], dfs(v, dfs);

        if(u == 1)  return;

        if(u != 1 and adj[u].size() == 1)
        {
            //default
            dp[u][0] = 0;
            dp[u][1] = 1;
            dp[u][2] = 1;

            return;
        }

        adj[u].erase(find(all(adj[u]), par[u]));
        adj[u].pb(u);

        sort(all(adj[u]), [&](int a, int b) {return id[a] < id[b];});

        int c = (int)adj[u].size();

        vector<Mint> pre(c + 5, 1), suf(c + 5, 1);

        for(int i = 1; i <= c; i ++)
        {
            int v = adj[u][i - 1];
            if(u == v)
                pre[i] = pre[i - 1];
            else
                pre[i] = pre[i - 1] * (dp[v][0] + dp[v][1]);
        }
        for(int i = c; i >= 1; i --)
        {
            int v = adj[u][i - 1];
            if(u == v)
                suf[i] = suf[i + 1];
            else
                suf[i] = suf[i + 1] * (dp[v][0] + dp[v][2]);
        }
        bool cross = false;

        for(int i = 1; i <= c; i ++)
        {
            int v = adj[u][i - 1];

            if(u == v)
            {
                dp[u][1] = pre[i - 1] * suf[i + 1];
                cross = true;
                continue;
            }

            if(!cross)
                dp[u][0] += (pre[i - 1] * dp[v][2] * suf[i + 1]);
            else
                dp[u][2] += (pre[i - 1] * dp[v][2] * suf[i + 1]);
        }

        dp[u][2] += pre[c];
    };
    dfs(1, dfs);

    Mint ans = 0;

    int c = adj[1].size();
    sort(all(adj[1]), [&](int a, int b) {return id[a] < id[b];});
    vector<Mint> pre(c + 5, 1), suf(c + 5, 1);

    for(int i = 1; i <= c; i ++)
        pre[i] = pre[i - 1] * (dp[adj[1][i - 1]][0] + dp[adj[1][i - 1]][1]);
    for(int i = c; i >= 1; i --)
        suf[i] = suf[i + 1] * (dp[adj[1][i - 1]][0] + dp[adj[1][i - 1]][2]);

    for(int i = 1; i <= c; i ++)
        ans += pre[i - 1] * dp[adj[1][i - 1]][2] * suf[i + 1];
    ans += pre[c];

    cout << ans << endl;
}


/*
define 
dp[u][0] to be the number of states wherein u is not present during the (u, parent) edge
dp[u][1] to be the number of states wherein u is present during the (u, parent) edge, and also gets removed 
dp[u][2] to be the number of states wherein u is present during the (u, parent) edge, and does not get removed

let u be removed during the ith considered edge, at the ith thing, we must take dp[i][2], before all of it we must take dp[u][0] or dp[u][1], and after it, we take
dp[u][0] or dp[u][2]

thats it
*/