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
const int64_t inf = 1e9, INF = 1e18, BIG_MOD = 489133282872437279;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

template<typename Node>
struct SparseTable
{
    vector<vector<Node>> table;
    vector<int> logValues;

    int n, maxLog;
    vector<int> a;

    SparseTable(int n1, vector<int> &arr)
    {
        n = n1, a = arr, table.resize(n), logValues.resize(n + 1), maxLog = log2(n);
        logValues[1] = 0;

        for(int i = 2; i <= n; i ++)    logValues[i] = logValues[i/2] + 1;
        for(int i = 0; i < n; i ++)
        {
            table[i].resize(maxLog + 1);
            fill(all(table[i]), Node());
        }

        build();
    }

    void build()
    {
        for(int i = 0; i < n; i ++)
            table[i][0] = Node(a[i]);
        
        for(int i = 1; i <= maxLog; i ++)
            for(int j = 0; (j + (1 << i)) <= n; j ++)
                table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
    }

    Node queryNormal(int left, int right)
    {
        Node ans = Node();
        for(int j = logValues[right - left + 1]; j >= 0; j --)
            if((1 << j) <= right - left + 1)
            {
                ans.merge(ans, table[left][j]);
                left += (1 << j);
            }
        return ans;
    }
    Node queryIdempotent(int left, int right)
    {
        int j = logValues[right - left + 1];
        Node ans = Node();
        ans.merge(table[left][j], table[right - (1 << j) + 1][j]);
        return ans;
    }
};
struct Node
{
    int mn, mx;
    Node()                 //identity element
    {
        mn = inf;
        mx = -inf;
    }
    Node(int v)
    {
        mn = mx = v;
    }
    void merge(Node &l, Node &r)
    {
        mn = min(l.mn, r.mn);
        mx = max(l.mx, r.mx);
    }
};

// #define int int64_t

const int MAXN = 1.2e5+5;

struct Fenwick          //one indexed
{
    vector<int64_t> bit;
    int n;

    Fenwick(int n) 
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    int64_t sum(int idx) 
    {
        int64_t ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int64_t sum(int l, int r) 
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int64_t delta) 
    {
        for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
    }
};

struct node
{
    int active = 0;
    int64_t val = 0;
    node() : active(0), val(0) {};
};
struct SegTree
{
    int N;
    vector<node> st;
    vector<bool> cLazy;
    vector<int64_t> lazy;
    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
        cLazy.assign(4 * N + 5, false);
        lazy.assign(4 * N + 5, 0);
    }
    void merge(node &cur, node &l, node &r)
    {
        cur.active = l.active + r.active;
        cur.val = l.val + r.val;
    }

    // be careful about that one lifting case in range add, range max qr for ex
    void propagate(int ver, int L, int R)
    {
        if (L != R) // passing on lazy shit to children
        {
            cLazy[ver * 2] = cLazy[ver * 2 + 1] = 1;
            lazy[ver * 2] += lazy[ver], lazy[ver * 2 + 1] += lazy[ver];
        }
        st[ver].val += st[ver].active * lazy[ver];
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
    void pUpdate(int ver, int L, int R, int pos, int status)
    {
        if (cLazy[ver])
            propagate(ver, L, R);
        if (L == R)
        {
            st[ver].active = status, st[ver].val = 0;
            return;
        }
        int M = (L + R) / 2;
        if (pos <= M)
            pUpdate(ver * 2, L, M, pos, status);
        else
            pUpdate(ver * 2 + 1, M + 1, R, pos, status);

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
    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }
    void update(int l, int r, int val)
    {
        Update(1, 1, N, l, r, val);
    }
};

struct node1
{
    int mx = -inf;
    node1() : mx(-inf){};
};
struct SegTree2
{
    int N;
    vector<node1> st;
    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
    }
    void merge(node1 &cur, node1 &l, node1 &r)
    {
        cur.mx = max(l.mx, r.mx);
    }

    // be careful about that one lifting case in range add, range max qr for ex
    
    void pUpdate(int ver, int L, int R, int pos, int val)
    {
        if (L == R)
        {
            st[ver].mx = val;
            return;
        }
        int M = (L + R) / 2;
        if (pos <= M)
            pUpdate(ver * 2, L, M, pos, val);
        else
            pUpdate(ver * 2 + 1, M + 1, R, pos, val);

        merge(st[ver], st[ver * 2], st[ver * 2 + 1]);
    }

    int get(int v, int lv, int rv, int l, int r, int x) // get index of latest element in [l, r] > x variant
    {
        if (lv > r || rv < l)
            return -1;
        if (l <= lv && rv <= r)
        {
            if (st[v].mx <= x)
                return -1;
            while (lv != rv)
            {
                int mid = lv + (rv - lv) / 2;
                if (st[v * 2 + 1].mx > x)
                    v = v * 2 + 1, lv = mid + 1;
                else
                    v = v * 2, rv = mid;
            }
            return lv;
        }
        int mid = lv + (rv - lv) / 2;

        int rs = get(2 * v + 1, mid + 1, rv, l, r, x);
        if (rs != -1)
            return rs;
        return get(2 * v, lv, mid, l, r, x);
    }

    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }
    int findLatest(int l, int r, int minimum) // return last element in [l, r] >= minimum, just modify the fn body to convert it into finding the first element, finding element <= or < or > x etc etc
    {
        return get(1, 1, N, l, r, minimum);
    }
};

int n, q;
vector<int> p(MAXN), ind(MAXN);
vector<pair<int, int>> b(MAXN);

int64_t ans[MAXN];
vector<pair<int, int>> qr[MAXN];

int32_t main()
{
    fastio();
    
    cin >> n;

    for(int i = 1; i <= n; i ++)    cin >> p[i], ind[p[i]] = i;
    SparseTable<Node> mrq((int)n + 1, ind);

    for(int i = 1; i < n; i ++)
    {
        int x = p[i], y = p[i + 1];
        if(x > y)   swap(x, y);

        auto qr = mrq.queryIdempotent(x, y);
        b[i] = mp(qr.mn, qr.mx);
    }

    cin >> q;
    for(int i = 1, l, r; i <= q; i ++)  cin >> l >> r, qr[r].pb(mp(i, l));
    
    SegTree rq;
    SegTree2 orq;

    rq.init(n + 1);
    orq.init(n + 1);
    Fenwick rrq(n + 1);

    rq.update(1, 1);
    set<int> lb = {1};
    for(auto il : qr[1])
        ans[il.first] = 1;
    orq.update(1, b[1].second);

    for(int r = 2; r <= n; r ++)
    {
        auto it = lb.upper_bound(b[r - 1].first);
        while(it != lb.end())
        {
            int x = *it;
            lb.erase(x);

            int val = rq.query(x).val;
            rq.update(x, 0);
            rrq.add(x, val);

            it = lb.upper_bound(b[r - 1].first);
        }

        int get = max((int)1, orq.findLatest(1, r, b[r - 1].second) + 1);

        if(b[r - 1].second == r)            //valid rb
            rq.update(get, n, 1);

        for(auto il : qr[r])
        {
            int i = il.first, l = il.second;

            ans[i] = rq.query(l, r).val + rrq.sum(l, r) + (r - l + 1);
        }

        if(b[r].first == r)
            rq.update(r, 1), lb.insert(r);
        
        orq.update(r, b[r].second);
    }

    for(int i = 1; i <= q; i ++)    cout << ans[i] << endl;
}