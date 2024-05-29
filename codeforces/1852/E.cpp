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

const int N = 2e5+5;

struct node 
{
    pair<int, int> mn, mx;
    node() : mn(mp(inf, inf)), mx(mp(0, 0)) {};
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
        cur.mn = min(l.mn, r.mn);
        cur.mx = max(l.mx, r.mx);
    }
    node Query(int ver, int L, int R, int i, int j) 
    {
        if (j < L || i > R) return node();
        if (i <= L && R <= j) return st[ver];
        int M = (L + R) / 2;
        node left = Query(ver * 2, L, M, i, j), right = Query(ver * 2 + 1, M + 1, R, i, j), cur;
        merge(cur, left, right);
        return cur;
    }
    void pUpdate(int ver, int L, int R, int pos, int val) 
    {
        if (L == R) 
        {
            st[ver].mn = st[ver].mx = mp(val, pos);
            return;
        }
        int M = (L + R) / 2;
        if (pos <= M) pUpdate(ver * 2, L, M, pos, val);
        else pUpdate(ver * 2 + 1, M + 1, R, pos, val);
        merge(st[ver], st[ver * 2], st[ver * 2 + 1]);
    }
    node query(int l, int r) {if(l > r)     return node();  return Query(1, 1, N, l, r);}
    void update(int pos, int val) {pUpdate(1, 1, N, pos, val);}
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
        
        set<int> s, S;
        map<int, int> cmp, rmp, low;
        vector<int> a(n + 1), l(n + 1, 1e9), r(n + 1, 0);
        i64 sum = 0;
        for(int i = 1; i <= n; i ++)    cin >> a[i], s.insert(a[i]), sum += a[i];

        int timer = 0;
        for(auto x : s)
        {
            cmp[x] = ++timer;
            rmp[timer] = x;
        }
        cmp[0] = rmp[0] = 0;

        for(int i = 1; i <= n; i ++)
        {
            a[i] = cmp[a[i]];
            l[a[i]] = min(l[a[i]], i), r[a[i]] = max(r[a[i]], i);
        }

        vector<bool> use(n + 1, false);
        set<pair<int, int>> q;          //{index, value}
        set<int> lol, kek;

        for(int i = 1; i <= n; i ++)
        {
            if(i == l[a[i]] and i == r[a[i]])
            {
                auto it = q.lower_bound(mp(l[a[i]], 0));
                q.insert(mp(l[a[i]], a[i]));
                it = q.find(mp(l[a[i]], a[i]));
                S.insert(rmp[a[i]]);
                while(it != q.begin() and (* (--it)).second <= a[i])
                    q.erase(it), it = q.find(mp(l[a[i]], a[i]));
            }
            else if(i == l[a[i]])   continue;
            else if(i == r[a[i]])
            {
                auto it = q.lower_bound(mp(l[a[i]], 0));
                if(it != q.end() and (*it).second > a[i])
                {
                    lol.insert(a[i]);
                    continue;
                }
                else
                    S.insert(rmp[a[i]]);

                q.insert(mp(l[a[i]], a[i]));
                it = q.find(mp(l[a[i]], a[i]));
                while(it != q.begin() and (* (--it)).second <= a[i])
                    q.erase(it), it = q.find(mp(l[a[i]], a[i]));
            }
            else
                use[i] = true;
        }
        int opt = 0;
        set<int> lows;
        for(auto x : S)
        {
            if(!S.count(x - 1)) opt = x - 1;
            low[x] = opt;
            lows.insert(low[x]);
        }

        for(int i = 1; i <= n; i ++)
        {
            use[i] = use[i] or lol.count(a[i]);
            if(use[i])  kek.insert(i); 
        }

        pair<i64, pair<int, int>> ans = mp(sum, mp(0, -1));
        for(int i = 1; i <= n; i ++)
            if(use[i])
                sum -= rmp[a[i]];

        SegTree rq, lbq, rbq;
        rq.init(n), lbq.init(n), rbq.init(n);

        int rb = timer, lr = 1e9, rl = 0;
        while(!lows.empty())
        {
            int low = *lows.rbegin();
            lows.erase(low);
            
            vector<pair<int, int>> seg;
            while(rb > 0 and rmp[rb] > low)
            {
                if(!lol.count(rb))
                {
                    int val = rb;
                    seg.pb(mp(l[val], r[val]));
                    rl = max(rl, l[val]);
                    lr = min(lr, r[val]);

                    lbq.update(l[val], r[val]);
                    rbq.update(r[val], l[val]);

                    for(auto take = kek.lower_bound(l[val]); take != kek.end() and *take <= r[val]; take = kek.lower_bound(l[val]))
                    {
                        int i = *take;
                        rq.update(i, val);
                        kek.erase(i);
                        sum += rmp[val];
                    }
                }
                rb --;
            }

            if(kek.empty())
            {
                ans = max(ans, mp(sum, mp(0, low)));
                break;
            }

            if(low == 0)    break;

            bool found = (lbq.query(*kek.begin() + 1, *kek.rbegin() - 1).mn.first <= *kek.rbegin() - 1);

            if(found)
            {
                sum += (kek.size()) *(i64)low;
                ans = max(ans, mp(sum, mp(0, low)));
                break;
            }
            else
            {
                int bl = *kek.begin(), br = *kek.rbegin();

                int bound1 = lbq.query(br + 1, n).mn.first;
                if(bound1 != inf)
                {
                    auto [opt, ind] = rq.query(bound1 + 1, n).mn;
                    if(opt != inf)  ans = max(ans, mp(sum - rmp[opt] + ((int)kek.size() + 1) * (i64)low, mp(ind, low)));
                }
                int bound2 = rbq.query(1, bl - 1).mx.first;
                if(bound2 != inf)
                {
                    auto [opt, ind] = rq.query(1, bound2 - 1).mn;
                    if(low == 7)    debug(opt, ind);
                    if(opt != inf)  ans = max(ans, mp(sum - rmp[opt] + ((int)kek.size() + 1) * (i64)low, mp(ind, low)));
                }
            }
        }

        int lim = ans.second.second;
        if(lim == -1)
        {
            for(int i = 1; i <= n; i ++)    cout << rmp[a[i]] << " ";
            cout << endl;
            continue;
        }

        vector<int> b(n + 1);
        for(int i = 1; i <= n; i ++)
        {
            if(!use[i])     b[i] = rmp[a[i]];
            else    kek.insert(i);
        }
        for(int val = timer; rmp[val] > ans.second.second; val --)  if(!lol.count(val))
        {
            for(auto take = kek.lower_bound(l[val]); take != kek.end() and *take <= r[val]; take = kek.lower_bound(l[val]))
            {
                int i = *take;
                b[i] = rmp[val];
                kek.erase(i);
            }
        }

        b[ans.second.first] = ans.second.second;
        for(auto i : kek)   b[i] = ans.second.second;

        for(int i = 1; i <= n; i ++)    cout << b[i] << " ";
        cout << endl;
    }
}