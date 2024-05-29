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
void __print(Mint x) {cerr << x;}


#define int int64_t
// #define Mint int64_t

const int N = 1e2+5;

struct Comb
{
    Mint fac[4 * N];
    Mint ncr[4 * N][4 * N];
    void pre()
    {
        fac[0] = 1;
        for(int i = 1; i < 4 * N; i ++)
            fac[i] = fac[i - 1] * i;
        
        for(int n = 0; n < 4 * N; n ++)
            for(int r = 0; r <= n; r ++)
                ncr[n][r] = fac[n]/(fac[n - r] * fac[r]);
    }
}comb;

int n, x;
int d[N], f[N], l[N], r[N];

int m;
vector<int> p;

pair<int, Mint> ans = mp(0, 0);
Mint dp[N][N];
Mint way[N][3][N][N];

pair<int, Mint> upd(pair<int, Mint> a, pair<int, Mint> b)
{
    if(a.first == b.first)
        return mp(a.first, a.second + b.second);
    else if(a.first > b.first)
        return a;
    else if(a.first < b.first)
        return b;
    return mp(0, 0);
}

map<pair<int, int>, Mint> ncr;

bool dbg = false;

Mint store[N][N][N];
Mint get(int b, int pos, int neg)
{
    int len = p[b + 1] - p[b];

    if(pos == 0)
    {
        if(len != neg)
            return 0;
        else
            return 1;
    }

    len -= pos + neg;

    if(len < 0)
        return 0;

    -- pos;


    if(store[b][pos][neg] != 0)
        return store[b][pos][neg];

    Mint x = 1;

    for(int i = len + 1; i <= len + pos; i ++)
        x *= i;
    
    for(int i = 1; i <= pos; i ++)
        x /= i;

    store[b][pos][neg] = x;

    return x;
}

int32_t main()
{
    fastio();
    comb.pre();

    cin >> n >> x;
    x = 0;

    cin >> d[1];
    int _n = 1;
    for(int l = 2, e; l <= n; l ++)
    {
        cin >> e;

        if(e == 0)  
            continue;

        if((d[_n] > 0) != (e > 0))
            d[++ _n] = e;
        else
            d[_n] += e;
    }

    n = _n;

    if(n == 0)
    {
        cout << 1 << " " << 1 << endl;
        exit(0);
    }    

    f[0] = x;
    for(int i = 1; i <= n; i ++)
        f[i] = f[i - 1] + d[i];
    
    for(int i = 0; i <= n; i ++)
    {
        if(i == 0)
            l[i] = r[i] = x;
        else
        {
            l[i] = f[i - 1], r[i] = f[i];
            if(l[i] > r[i]) swap(l[i], r[i]), -- r[i];
            else    ++ l[i];
        }
    }

    int mx = *max_element(f, f + n + 1);
    for(int i = 0; i <= n; i ++)
    {
        p.pb(f[i]);
        if(f[i] != mx)
            p.pb(f[i] + 1);
    }

    sort(all(p));
    p.erase(unique(all(p)), p.end());
    m = p.size();
    p.pb(mx + 1);

    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
            for(int k = 0; k < N; k ++)
                store[i][j][k] = 0;

    //compute the coefficients here
    for(int b = 0; b < m; b ++)
    {
        int len = p[b + 1] - p[b];
        int cnt = 0;
        for(int i = 0; i <= n; i ++)
            cnt += (l[i] <= p[b] and p[b + 1] - 1 <= r[i]);

        for(int x = 0; x <= cnt; x ++)
            for(int y = 0; (x + y <= cnt); y ++)
                for(int fx = 0, fy = 2; fx <= 2; fx ++, fy --)
                    for(int tx = fx; tx <= x; tx ++)
                        for(int ty = fy; ty <= y; ty ++)
                            way[b][fx][x][y] += comb.ncr[x - fx][tx - fx] * comb.ncr[y - fy][ty - fy] * get(b, tx, ty);
    }

    //ith segment is from p[i] to p[i + 1] - 1

    ans = upd(ans, mp(1, 1));
    for(int i = 1; i <= n; i ++)
    {
        if(d[i] > 0)
            ans = upd(ans, mp(d[i], 1));
        else
            ans = upd(ans, mp(1, -d[i]));
    }

    for(int s = 0; s <= n; s ++)
    {
        for(int i = 0; i <= n; i ++)
            fill(dp[i], dp[i] + N, 0);

        int l = ::l[s], r = ::r[s];

        for(int b = 0; b < m; b ++)
            if(l <= p[b] and p[b + 1] - 1 <= r)
            {
                dp[s][b] = 1;

                if(d[s] < 0)
                    break;
            }

        //dp[i][j] = {x, y} is basically:
        //number of ways to reach i, be in the jth segment
        //stores maximum x where x is the number of intra block transitions
        //y is the number of sequences with x transitions
        //remember that no block is ever used in an incomplete manner

        for(int i = s + 1; i <= n; i ++)
        {
            int l = ::l[i], r = ::r[i];

            for(int b = 0; b < m; b ++)
            {
                if(l <= p[b] and p[b + 1] - 1 <= r)
                {
                    int cnt_pos = 0, cnt_neg = 0;

                    bool right_bound = (d[i] > 0);

                    for(int j = i; j >= s; j --)
                    {
                        int _l = ::l[j], _r = ::r[j];

                        if(_l <= p[b] and p[b + 1] - 1 <= _r)
                        {
                            cnt_pos += (d[j] > 0);
                            cnt_neg += (d[j] < 0);

                            bool left_bound = (d[j] > 0);

                            if(j == i)
                                dp[i][b] += (d[i] > 0 ? dp[i][b - 1] + dp[i - 1][b - 1] : dp[i - 1][b - 1]) * (d[i] > 0 ? 1 : (p[b + 1] - p[b] > 1 ? 0 : 1));
                            else
                                dp[i][b] += (d[j] > 0 ? dp[j][b - 1] : dp[j - 1][b - 1]) * way[b][left_bound + right_bound][cnt_pos][cnt_neg];
                        }
                    }
                }
            }

            for(int b = 0; b < m; b ++)
                dp[i][b] += dp[i - 1][b];
        }

        for(int e = s + 1; e <= n; e ++)
        {
            int _l = ::l[e], _r = ::r[e];

            for(int b = m - 1; b >= 0; b --)
                if(_l <= p[b] and p[b + 1] - 1 <= _r and l <= _r)
                {
                    ans = upd(ans, mp(_r - l + 1, dp[e][b] - dp[e - 1][b]));
                    break;
                }
        }
    }

    cout << ans.first << sp << ans.second << endl;
}