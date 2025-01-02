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

struct node
{
    Mint sum = 0;
    node() : sum(0){};
};

struct SegTree
{
    int N;
    vector<node> st;
    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
    }
    void merge(node &cur, node &l, node &r)
    {
        cur.sum = l.sum + r.sum;
    }

    node Query(int ver, int L, int R, int i, int j)
    {
        if (j < L || i > R)
            return node();
        if (i <= L && R <= j)
            return st[ver];
        int M = (L + R) / 2;
        node left = Query(ver * 2, L, M, i, j), right = Query(ver * 2 + 1, M + 1, R, i, j), cur;
        merge(cur, left, right);
        return cur;
    }
    node pQuery(int ver, int L, int R, int pos)
    {
        if (L == R)
            return st[ver];
        int M = (L + R) / 2;
        if (pos <= M)
            return pQuery(ver * 2, L, M, pos);
        else
            return pQuery(ver * 2 + 1, M + 1, R, pos);
    }
    void pUpdate(int ver, int L, int R, int pos, int val)
    {
        if (L == R)
        {
            st[ver].sum = val;
            return;
        }
        int M = (L + R) / 2;
        if (pos <= M)
            pUpdate(ver * 2, L, M, pos, val);
        else
            pUpdate(ver * 2 + 1, M + 1, R, pos, val);

        merge(st[ver], st[ver * 2], st[ver * 2 + 1]);
    }

    node query(int l, int r)
    {
        if(l > r)   return node();
        return Query(1, 1, N, l, r);
    }
    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }

    void show(int n)
    {
        for(int i = 1; i <= n; i ++)    cerr << query(i, i).sum << sp;
        cerr << endl;
    }
};

int32_t main()
{
    fastio();
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        vector<pair<int, int>> ord = {mp(0, 0)};
        for(int i = 1; i <= n; i ++)    cin >> a[i], ord.pb(mp(a[i], i));
        
        sort(all(ord));
        vector<int> ind(n + 1);
        map<int, int> occ, loc;
        for(int i = 1; i <= n; i ++)
        {
            ind[ord[i].second] = i;
            if(occ.find(ord[i].first) == occ.end()) occ[ord[i].first] = i;
            loc[ord[i].first] = i;
        }

        SegTree cnt_dp, sum_dp;
        cnt_dp.init(n), sum_dp.init(n);

        for(int i = 1; i <= n; i ++)
        {
            Mint cnt_before = 1 + cnt_dp.query(1, occ[a[i]] - 1).sum;
            Mint sum_before = cnt_before + sum_dp.query(1, occ[a[i]] - 1).sum;

            cnt_dp.update(ind[i], (int)cnt_before);
            sum_dp.update(ind[i], (int)sum_before);
        }

        SegTree rcnt_dp;
        rcnt_dp.init(n);

        set<pair<int, int>> suffix = {mp(0, n + 1)};
        vector<Mint> wait(n + 1, 0);

        for(int i = n; i >= 1; i --)
        {
            if(a[i] > (*suffix.rbegin()).first)
            {
                suffix.insert(mp(a[i], i));
                rcnt_dp.update(ind[i], 1);
                continue;
            }

            auto bit = suffix.upper_bound(mp(a[i], n));

            if(bit == suffix.end())     //fake maximum
            {
                wait[i] = 1;
            }
            else
            {
                int big = (*bit).first;

                Mint cnt_ahead = (rcnt_dp.query(loc[a[i]] + 1, occ[big] - 1).sum + 1);

                rcnt_dp.update(ind[i], (int)cnt_ahead);
            }
        }

        SegTree ans_dp;
        ans_dp.init(n);

        Mint ans = 0;

        for(int i = n; i >= 1; i --)
        {
            auto it = suffix.upper_bound(mp(a[i], n));  
            if(it == suffix.end() or (*it).second < i or suffix.count(mp(a[i], i)))
            {
                ans_dp.update(ind[i], (int)(rcnt_dp.query(ind[i], ind[i]).sum + wait[i]));
                continue;
            }
            
            int bound = occ[(*it).first];
            Mint x = sum_dp.query(ind[i], ind[i]).sum, y = ans_dp.query(bound, n).sum + 1 - 1;

            ans += (x) * (y);
            ans_dp.update(ind[i], (int)(rcnt_dp.query(ind[i], ind[i]).sum + wait[i]));
        }

        cout << ans << endl;
    }
}

// where are youuuuuuuuuuuuuuuuu