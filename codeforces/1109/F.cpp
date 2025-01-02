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

const int MOD = 1e9+7;
const int64_t inf = 0x3f3f3f3f, INF = 1e18, BIG_MOD = 489133282872437279;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// #define int int64_t
using i64 = int64_t;
const int N = 2e5+5, X = 1e3+5;


//dsu stuff
struct op
{
    bool did;
    int u, v;
    op(bool did, int u, int v) : did(did), u(u), v(v) {};
};

int bad = 0;
int par[N], siz[N];
stack<op> his;

int get(int u)  {return (u == par[u] ? u : get(par[u]));}
void unite(int u, int v)
{
    u = get(u), v = get(v);
    if(u == v)
    {
        ++ bad;
        his.push(op(0, u, v));
        return;
    }

    if(siz[u] < siz[v]) swap(u, v);
    par[v] = u, siz[u] += siz[v];

    his.push(op(1, u, v));
}

void roll_back()
{
    auto [did, u, v] = his.top();
    his.pop();

    if(!did)
    {
        -- bad;
        return;
    }

    siz[u] -= siz[v];
    par[v] = v;
}


struct node
{
    pair<int, int> mx = mp(-inf, 0);
    node() : mx(mp(-inf, 0)){};
};
struct SegTree
{
    int N;
    vector<node> st;
    vector<bool> cLazy;
    vector<int> lazy;
    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
        cLazy.assign(4 * N + 5, false);
        lazy.assign(4 * N + 5, 0);
    }
    void merge(node &cur, node &l, node &r)
    {
        cur = l;
        if(r.mx.first == l.mx.first)    cur.mx.second += r.mx.second;
        else if(r.mx.first > l.mx.first)    cur = r; 
    }

    // be careful about that one lifting case in range add, range max qr for ex
    void propagate(int ver, int L, int R)
    {
        if (L != R) // passing on lazy shit to children
        {
            cLazy[ver * 2] = cLazy[ver * 2 + 1] = 1;
            lazy[ver * 2] += lazy[ver], lazy[ver * 2 + 1] += lazy[ver];
        }
        st[ver].mx.first += lazy[ver];
        cLazy[ver] = lazy[ver] = 0;
    }

    node Query(int ver, int L, int R, int i, int j)
    {
        if (cLazy[ver])
            propagate(ver, L, R);
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
        if (cLazy[ver])
            propagate(ver, L, R);
        if (L == R)
            return st[ver];
        int M = (L + R) / 2;
        if (pos <= M)
            return pQuery(ver * 2, L, M, pos);
        else
            return pQuery(ver * 2 + 1, M + 1, R, pos);
    }
    void Update(int ver, int L, int R, int i, int j, int val)
    {
        if (cLazy[ver])
            propagate(ver, L, R);
        if (j < L || i > R)
            return;
        if (i <= L && R <= j)
        {
            cLazy[ver] = 1, lazy[ver] += val;
            propagate(ver, L, R);
            return;
        }
        int M = (L + R) / 2;
        Update(ver * 2, L, M, i, j, val), Update(ver * 2 + 1, M + 1, R, i, j, val);

        // if(cLazy[ver*2])  propagate(ver*2, L, M);
        // if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver], st[ver * 2], st[ver * 2 + 1]);
    }
    void pUpdate(int ver, int L, int R, int pos, int val)
    {
        if (cLazy[ver])
            propagate(ver, L, R);
        if (L == R)
        {
            st[ver].mx = mp(val, 1);
            return;
        }
        int M = (L + R) / 2;
        if (pos <= M)
            pUpdate(ver * 2, L, M, pos, val);
        else
            pUpdate(ver * 2 + 1, M + 1, R, pos, val);

        // if(cLazy[ver*2])  propagate(ver*2, L, M);
        // if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver], st[ver * 2], st[ver * 2 + 1]);
    }

    node query(int pos)
    {
        return pQuery(1, 1, N, pos);
    }
    node query(int l, int r)
    {
        return Query(1, 1, N, l, r);
    }
    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }
    void update(int l, int r, int val)
    {
        Update(1, 1, N, l, r, val);
    }

    void show(int n)
    {
        for(int i = 1; i <= n; i ++)    cerr << query(i).mx.first << sp;
        cerr << endl;
    }
};

int n, m;
vecvec(int, g, X, X, 0);
vector<pair<int, int>> p(N);
vector<vector<int>> adj(N);

int add(int l, int r, int bl = 1, int br = 0)
{
    int cnt = 0;
    for(int i = l; i <= r; i ++)
        for(auto v : adj[i])
            if((l <= v and v <= i) or (bl <= v and v <= br))
                unite(i, v), ++ cnt;
    return cnt;
}
void rem(int cnt)
{
    while(cnt --)
        roll_back();
}

int32_t main()
{
    fastio();
    for(int i = 1; i < N; i ++) par[i] = i, siz[i] = 1;

    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            cin >> g[i][j], p[g[i][j]] = mp(i, j);

            if(i != 1)  adj[g[i - 1][j]].pb(g[i][j]), adj[g[i][j]].pb(g[i - 1][j]);
            if(j != 1)  adj[g[i][j - 1]].pb(g[i][j]), adj[g[i][j]].pb(g[i][j - 1]);
        }

    vector<int> rb(n * m + 1);
    for(int i = 1; i <= n * m; i ++)    rb[i] = i;
    function<void(int, int, int, int)> cut = [&](int l, int r, int al, int ar)
    {
        int m = (l + r)/2;

        if(al == l)     //nothing inside
        {
            int cnt = 0;

            for(rb[m] = m; rb[m] <= ar; ++ rb[m])
            {
                for(auto v : adj[rb[m]])
                    if(m <= v and v <= rb[m])
                        unite(rb[m], v), ++ cnt;

                if(bad)
                {
                    for(auto v : adj[rb[m]])
                        if(m <= v and v <= rb[m])
                            roll_back(), -- cnt;
                    -- rb[m];
                    break;
                }
            }

            rem(cnt);
            rb[m] = min(rb[m], ar);

            if(l <= m - 1)
            {
                if(al <= m - 1)
                    cut(l, m - 1, l, ar);
                else
                {
                    int cnt2 = add(m, al - 1);
                    cut(l, m - 1, al, ar);
                    rem(cnt2);
                }
            }
            if(m + 1 <= r)
            {
                if(rb[m] <= r)
                    cut(m + 1, r, m + 1, ar);
                else
                {
                    int cnt2 = add(r + 1, rb[m] - 1);
                    cut(m + 1, r, rb[m], ar);
                    rem(cnt2);
                }
            }
        }
        else            //[r + 1, al - 1] inside
        {
            int lcnt = add(m, r, r + 1, al - 1), rcnt = 0;

            for(rb[m] = al; rb[m] <= ar; rb[m] ++)
            {
                for(auto v : adj[rb[m]])
                    if((m <= v and v <= rb[m]) or (r + 1 <= v and v <= al - 1))
                        unite(rb[m], v), ++ rcnt;

                if(bad)
                {
                    for(auto v : adj[rb[m]])
                        if(m <= v and v <= rb[m])
                            roll_back(), -- rcnt;
                    -- rb[m];
                    break;
                }
            }
            rem(lcnt + rcnt);
            rb[m] = min(rb[m], ar);

            if(l <= m - 1)
            {
                assert(m - 1 < al);
                int bcnt = add(m, r, r + 1, al - 1);
                cut(l, m - 1, al, rb[m]);
                rem(bcnt);
            }
            if(m + 1 <= r)
            {
                assert(r < rb[m]);
                int bcnt = add(al, rb[m] - 1, r + 1, al - 1);
                cut(m + 1, r, rb[m], ar);
                rem(bcnt);
            }
        }
    };
    cut(1, n * m, 1, n * m);

    i64 ans = 0;

    SegTree rq;
    rq.init(n * m);
    for(int i = 1; i <= n * m; i ++)    rq.update(i, -(i - 1));

    for(int l = 1, bound = 1; l <= n * m; l ++)
    {
        bound = max(bound, l);
        while(bound <= rb[l])
        {
            for(auto v : adj[bound])
                if(l <= v and v <= bound)
                    rq.update(bound, n * m, +1);
            ++ bound;
        }

        ans += rq.query(l, bound - 1).mx.second;

        for(auto v : adj[l])
            if(l <= v and v <= bound - 1)
                rq.update(v, n * m, -1);
        rq.update(l, n * m, +1);
    }
    cout << ans << endl;
}