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
using i64 = int64_t;

const int N = 2e3+5;

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


struct ConvexHullDynamic
{

	struct Line
	{
		ll a, b; //y = ax + b
		double xLeft; //Stores the llersection wiith previous line in the convex hull. First line has -INF

		enum Type {line, maxQuery, minQuery} type;
		ll val;

		explicit Line(ll aa=0, ll bb=0): a(aa), b(bb), xLeft(-INF), type(Type::line), val(0) {}

		ll valueAt(ll x) const
		{
			return a*x + b;
		}
		friend bool isParallel(const Line &l1, const Line &l2)
		{
			return l1.a == l2.a;
		}
		friend double llersectX(const Line &l1, const Line &l2)
		{
			return isParallel(l1, l2)?INF:1.0*(l2.b-l1.b)/(l1.a-l2.a);
		}
		bool operator<(const Line& l2) const
		{
			if(l2.type == line)
				return this->a < l2.a;
			if(l2.type == maxQuery)
				return this->xLeft < l2.val;
			if(l2.type == minQuery)
				return this->xLeft > l2.val;
            return 0;
		}
	};

	bool isMax;
	set<Line> hull;

	bool hasPrev(set<Line>::iterator it)
	{
		return it!=hull.begin();
	}	
	bool hasNext(set<Line>::iterator it)
	{
		return it!=hull.end() && next(it)!=hull.end();
	}
	bool irrelevant(const Line &l1, const Line &l2, const Line &l3)
	{
		return llersectX(l1, l3) <= llersectX(l1, l2);
	}
	bool irrelevant(set<Line>::iterator it)
	{
		return hasPrev(it) && hasNext(it) && ( 
			(isMax && irrelevant(*prev(it), *it, *next(it))) 
			|| (!isMax && irrelevant(*next(it), *it, *prev(it))));
	}
	//Updates xValue of line polled by it
	set<Line>::iterator updateLeftBorder(set<Line>::iterator it)
	{
		if(isMax && !hasPrev(it) || !isMax && !hasNext(it))
			return it;
		double val=llersectX(*it, isMax?(*prev(it)):(*next(it)));
		Line temp(*it);
		it=hull.erase(it);
		temp.xLeft=val;
		it=hull.insert(it, temp);
		return it;
	}

	explicit ConvexHullDynamic(bool isMax): isMax(isMax) {}

	void addLine(ll a, ll b) //Add ax + b in logN time
	{
		Line l3=Line(a, b);
		auto it=hull.lower_bound(l3);

		//If parallel liune is already in set, one of the lines becomes irrelevant
		if(it!=hull.end() && isParallel(*it, l3))
		{
			if(isMax && it->b<b || !isMax && it->b>b)
				it=hull.erase(it);
			else
				return;
		}

		it=hull.insert(it, l3);
		if(irrelevant(it))
		{
			hull.erase(it);
			return;
		}

		//Remove lines which became irrelevant after inserting
		while(hasPrev(it) && irrelevant(prev(it)))
			hull.erase(prev(it));
		while(hasNext(it) && irrelevant(next(it)))
			hull.erase(next(it));

		//Update xLine
		it=updateLeftBorder(it);
		if(hasPrev(it))
			updateLeftBorder(prev(it));
		if(hasNext(it))
			updateLeftBorder(next(it));
	}

	pair<ll, pair<ll, ll>> getBest(ll x)
	{
		Line q;
		q.val=x;
		q.type = isMax?Line::Type::maxQuery : Line::Type::minQuery;

		auto bestLine=hull.lower_bound(q);
		if(isMax)
			--bestLine;
        
		return mp(bestLine->valueAt(x), mp(bestLine->a, bestLine->b));
	}
}cht(1);


int n, m, q;
vector<pair<int, int>> adj[N];
vector<vector<i64>> dis(N, vector<i64> (N, -INF));

int32_t main()
{
    fastio();
    cin >> n >> m >> q;

    for(int i = 1, u, v, w; i <= m; i ++)   cin >> u >> v >> w, adj[u].pb(mp(v, w)), adj[v].pb(mp(u, w));

    Mint ans = 0;
    dis[1][0] = 0;
    for(int s = 1; s <= min(q, n); s ++)
    {
        for(int u = 1; u <= n; u ++)
            for(auto [v, w] : adj[u])
                if(dis[v][s - 1] != -INF)
                    dis[u][s] = max(dis[u][s], dis[v][s - 1] + w);
        for(int u = 1; u <= n; u ++)
            for(auto [v, w] : adj[u])
                if(dis[u][s] != -INF)
                    cht.addLine(w, - (i64)w * s + dis[u][s]);

        ans += cht.getBest(s).first;
    }
    
    if(q > n)
    {
        int lb = n;
        while(lb != q)
        {
            int s = lb + 1, e = q, cor = lb + 1;
            auto qr = cht.getBest(lb + 1);

            while(s <= e)
            {
                int mid = (s + e) >> 1;
                if(cht.getBest(mid).second == qr.second)    s = mid + 1, cor = mid;
                else    e = mid - 1;
            }
            Mint _cor = cor, _lb = lb, qrsf = qr.second.first, qrss = qr.second.second;

            ans += ((_cor * (_cor + 1))/2 - (_lb * (_lb + 1))/2) * qrsf + (_cor - _lb) * qrss;
            lb = cor;
        }
    }

    cout << ans << endl;
}