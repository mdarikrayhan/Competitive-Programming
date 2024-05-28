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

const int MAXN = 2e5+5;



struct node
{
    int64_t mn = INF, mx = -INF, lm = -INF, mr = -INF, ans = -INF, val = 0;
    node() : mn(INF), mx(-INF), lm(-INF), mr(-INF), ans(-INF), val(0) {};
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
        cur.mn = min(l.mn, r.mn);
        cur.mx = max(l.mx, r.mx);

        cur.lm = max(+l.mx - 2 * (r.mn), max(l.lm, r.lm));
        cur.mr = max(-2 * (l.mn) + r.mx, max(l.mr, r.mr));

        cur.ans = max(max(l.mx + r.mr, l.lm + r.mx), max(l.ans, r.ans));
    }

    // be careful about that one lifting case in range add, range max qr for ex
    void propagate(int ver, int L, int R)
    {
        if (L != R) // passing on lazy shit to children
        {
            cLazy[ver * 2] = cLazy[ver * 2 + 1] = 1;
            lazy[ver * 2] += lazy[ver], lazy[ver * 2 + 1] += lazy[ver];
        }

        st[ver].val += lazy[ver], st[ver].mn += lazy[ver], st[ver].mx += lazy[ver];
        st[ver].lm -= lazy[ver], st[ver].mr -= lazy[ver];

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

        if(cLazy[ver*2])  propagate(ver*2, L, M);
        if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver], st[ver * 2], st[ver * 2 + 1]);
    }
    void pUpdate(int ver, int L, int R, int pos, int type, int val)
    {
        if (cLazy[ver])
            propagate(ver, L, R);
        if (L == R)
        {
            st[ver].val = val;

            if(type == 1)
            {
                st[ver].mx = val;
                st[ver].mn = +INF;
            }
            else
            {
                st[ver].mn = val;
                st[ver].mx = -INF;
            }
            return;
        }
        int M = (L + R) / 2;
        if (pos <= M)
            pUpdate(ver * 2, L, M, pos, type, val);
        else
            pUpdate(ver * 2 + 1, M + 1, R, pos, type, val);

        if(cLazy[ver*2])  propagate(ver*2, L, M);
        if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

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
    void put(int pos, int type, int val)
    {
        pUpdate(1, 1, N, pos, type, val);
    }
    void update(int l, int r, int val)
    {
        Update(1, 1, N, l, r, val);
    }

    void show(int n)
    {
        for(int i = 1; i <= n; i ++)    cerr << query(i).val << sp;
        cerr << endl;
    }
}rq;

int n, q;
string s;

int get(int i)
{
    return (s[i] == '(' ? 1 : -1);
}

int32_t main()
{
    fastio();
    cin >> n >> q;
    cin >> s;
    s = "0" + s;

    rq.init(2 * (n - 1));
    for(int i = 1, sum = 0; i <= 2 * (n - 1); i ++)
        sum += get(i), rq.put(i, get(i), sum);

    auto qr = rq.query(1, 2 * (n - 1)); 
    cout << max(qr.ans, qr.mx) << endl;
    
    for(int i = 1, a, b; i <= q; i ++)
    {
        cin >> a >> b;

        if(a != b)
        {
            if(a > b)   swap(a, b);

            int a_val = rq.query(a).val, b_val = rq.query(b).val;
            int add = -get(a) + get(b);

            rq.put(a, get(b), a_val);
            rq.put(b, get(a), b_val);

            rq.update(a, b - 1, +add);

            swap(s[a], s[b]);
        }

        auto qr = rq.query(1, 2 * (n - 1));

        cout << max(qr.ans, qr.mx) << endl;
    }
}