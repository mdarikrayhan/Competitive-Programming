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

const int MOD = 998244353;
const int64_t inf = 0x3f3f3f3f, INF = 1e18, BIG_MOD = 489133282872437279;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// #define int int64_t

const int N = 6e3+5;


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
int a[2 * N + 1000], _l[2*N + 1000], _r[2 * N + 5];

Mint fac[2*N], inv[2*N];

int &cnt(int i)
{return a[n + i];}
int &l(int i)
{return _l[n + i];}
int &r(int i)
{return _r[n + i];}


Mint ncr(int n, int r)
{
    return (fac[n] * inv[r] * inv[n - r]);
}


int32_t main()
{
    fastio();

    fac[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < 2*N; i ++)   fac[i] = fac[i - 1] * i, inv[i] = 1/fac[i];

    int t;
    cin >> t;
    while(t --)
    {
        cin >> n;

        fill(a, a + 2 * n + 10, 0);

        for(int i = 1, x; i <= n; i ++)    cin >> x, cnt(x) += 1;

        Mint ans = 0;

        int mn = n, mx = -n;
        for(int i = -n; i <= n; i ++)
            if(cnt(i) > 0)
            {
                mn = min(mn, i);
                mx = max(mx, i);
            }
        
        if(mn == mx)
        {
            cout << ((mn == -1 or mn == 1) and n == 1) << endl;
            continue;
        }

        for(int start = -1; start <= 1; start += 2)
        {
            for(int end = -n; end <= n; end ++)
            {
                Mint here = (mn <= start and start <= mx and mn <= end and end <= mx and (cnt(start) > 0) and (cnt(end) > 0));

                if(here == 0)   continue;

                fill(_l, _l + 2 * n + 10, 0);
                fill(_r, _r + 2 * n + 10, 0);

                cnt(start) --;

                for(int i = mn; i <= mx; i ++)
                {
                    if(start == end)
                    {
                        l(i + 1) = cnt(i) - r(i - 1);
                        r(i) = l(i + 1);
                    }
                    else if(start < end)
                    {
                        if(i < start or i >= end)
                        {
                            l(i + 1) = cnt(i) - r(i - 1);
                            r(i) = l(i + 1);
                        }
                        else
                        {
                            l(i + 1) = cnt(i) - r(i - 1);
                            r(i) = l(i + 1) + 1;
                        }
                    }
                    else if(end < start)
                    {
                        if(i < end or i >= start)
                        {
                            l(i + 1) = cnt(i) - r(i - 1);
                            r(i) = l(i + 1);
                        }
                        else
                        {
                            l(i + 1) = cnt(i) - r(i - 1);
                            r(i) = l(i + 1) - 1;
                        }
                    }
                }

                for(int i = mn; i <= mx; i ++)
                {
                    if((i != start and cnt(i) == 0) or l(i) < 0 or r(i) < 0 or (r(i - 1) + l(i + 1) != cnt(i)) or (i == mn and l(i) > 0) or (i == mx and r(i) > 0))
                    {
                        here = 0;
                    }


                    if(start == end)
                    {
                        if(i < start)
                        {
                            if(r(i) == 0)   here = 0;
                            else    here *= fac[l(i) + r(i) - 1] * inv[l(i)] * inv[r(i) - 1];
                        }
                        else if(i == start)
                        {
                            if(l(i) + r(i) == 0)    here = 0;
                            else    here *= fac[l(i) + r(i)] * inv[l(i)] * inv[r(i)];
                        }
                        else if(i > start)
                        {
                            if(l(i) == 0)   here = 0;
                            else    here *= fac[l(i) + r(i) - 1] * inv[l(i) - 1] * inv[r(i)];
                        }
                    }
                    else
                    {
                        if(i < end)
                        {
                            if(r(i) == 0)   here = 0;
                            else    here *= fac[l(i) + r(i) - 1] * inv[l(i)] * inv[r(i) - 1];
                        }
                        else if(i == end)
                        {
                            here *= fac[l(i) + r(i)] * inv[l(i)] * inv[r(i)];
                        }
                        else if(i > end)
                        {
                            if(l(i) == 0)   here = 0;
                            else    here *= fac[l(i) + r(i) - 1] * inv[l(i) - 1] * inv[r(i)];
                        }
                    }
                }

                cnt(start) ++;
                ans += here;
            }
        }

        cout << ans << endl;
    }
}