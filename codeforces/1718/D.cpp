#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("03")

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define all(a) a.begin(),a.end()
#define endl "\n"
#define sp " " 
#define pb push_back
#define mp make_pair
#define vecvec(type, name, n, m, value) vector<vector<type>> name(n + 1, vector<type> (m + 1, value))

template<typename T>
using iset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;             //for multiset, use less_equal and erase x in multiset a -> a.erase(a.find_by_order(a.order_of_key(x)))

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
const int inf = 1e9;
const int64_t INF = 1e18, BIG_MOD = 489133282872437279;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// #define int int64_t

const int N = 2e5+5;

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
            table[i][0] = Node(a[i], i);
        
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
    pair<int, int> mx;
    Node()                 //identity element
    {
        mx = mp(-inf, -inf);
    }
    Node(int v, int i)
    {
        mx = mp(v, i);
    }
    void merge(Node &l, Node &r)
    {
        mx = max(l.mx, r.mx);
    }
};


int32_t main()
{
    fastio();
    int t;
    cin >> t;
    while(t --)
    {
        int n, q;
        cin >> n >> q;

        vector<int> p(n + 1), a(n + 1);
        for(int i = 1; i <= n; i ++)    cin >> p[i];
        
        int k = 0;
        a[0] = inf;
        for(int i = 1; i <= n; i ++)    cin >> a[i], k += (a[i] == 0);

        vector<int> s(k);
        for(int i = 1; i < k; i ++) cin >> s[i];

        set<pair<int, int>> qr;
        for(int i = 1, d; i <= q; i ++) cin >> d, qr.insert(mp(d, i));
        vector<bool> ans(q + 1, false);

        SparseTable<Node> rq(n + 1, p); 
        vector<vector<int>> adj(n + 1);

        bool can = true;
        auto build = [&](int l, int r, int p, auto &&build)    -> void
        {
            if(l > r)   return;

            int mid = rq.queryIdempotent(l, r).mx.second;
            adj[p].pb(mid);

            build(l, mid - 1, mid, build);
            build(mid + 1, r, mid, build);
        };
        build(1, n, 0, build);

        vector<int> sub(n + 1, 0);
        vector<array<int, 3>> seg;

        auto dfs = [&](int u, int mn, auto &&dfs)   -> void
        {
            sub[u] = a[u];

            for(auto v : adj[u])
                dfs(v, min(mn, (a[u] > 0 ? a[u] : inf)), dfs), sub[u] = max(sub[u], sub[v]);
            
            if(u == 0)  return;

            if(a[u] != 0 and sub[u] > a[u]) can = false;
            else if(a[u] == 0)
            {
                int l = sub[u] + 1, r = mn - 1;
                if(l > r)   can = false;
                else    seg.pb({u, l, r});
            }
        };
        dfs(0, a[0], dfs);

        if(!can)
        {
            for(int i = 1; i <= q; i ++)    cout << "NO" << endl;
            continue;
        }

        vector<int> l_ord(k, -1);             //ith point ko basically kya assign hota hai
        set<int> fix(s.begin() + 1, s.begin() + k);
        set<int> walk = {0, inf};
        map<int, vector<pair<int, int>>> lb, rb;

        for(auto [u, l, r] : seg)
        {
            walk.insert({l, r});
            lb[l].pb(mp(u, r));
            rb[r].pb(mp(u, l));
        }
        for(auto x : fix)
            walk.insert(x);


        int ind = 0;
        set<pair<int, int>> stk;        //stores {bound, index} pairs 
        for(auto x : walk)
        {
            while(!stk.empty() and (*stk.begin()).first < x)    stk.erase(stk.begin());

            if(lb.find(x) != lb.end())
                for(auto [u, r] : lb[x])
                    stk.insert(mp(r, u));
            
            if(fix.count(x))
            {
                ++ ind;
                if(!stk.empty())
                {
                    l_ord[ind] = (*stk.begin()).first;
                    stk.erase(stk.begin());
                }
            }
        }

        l_ord[0] = 0;
        if(count(all(l_ord), -1) > 0)   can = false;

        if(!can)
        {
            for(int i = 1; i <= q; i ++)
                cout << "NO" << endl;
            continue;
        }

        while(!qr.empty() and (*qr.rbegin()).first > *walk.rbegin())
        {
            auto [v, i] = *qr.rbegin();
            qr.erase(mp(v, i));
        }

        iset<int> left;
        int bad = 0;
        for(int i = 1; i < k; i ++)
        {
            if(l_ord[i] != -1)
                left.insert(l_ord[i]);
            else    ++ bad;            
        }

        ind = k - 1;
        stk.clear();

        for(auto it = walk.rbegin();;)
        {
            int x = *it;
            int nxt = *(++ it);

            while(!stk.empty() and (*stk.rbegin()).first > x)
            {
                auto it = stk.end();
                stk.erase(-- it);
            }


            if(rb.find(x) != rb.end())
                for(auto [u, l] : rb[x])
                    stk.insert(mp(l, u));

            if(fix.count(x))
            {
                if(l_ord[ind] != -1)    left.erase(left.find_by_order(left.order_of_key(l_ord[ind])));
                else    -- bad;

                if(!stk.empty())
                {
                    auto it = stk.end();
                    stk.erase(-- it);
                }
                else
                    break;

                -- ind;
            }

            int only_this = 0;
            while(!stk.empty() and (*stk.rbegin()).first == x)
            {
                ++ only_this;
                auto it = stk.end();
                stk.erase(-- it);
            }
            int sz = stk.size(), get_left = left.size() - left.order_of_key(nxt + 1);


            bool result = true;    //if we place in the segment (nxt, x]
            if(bad) result = false;

            if(only_this > 0)
            {
                if(get_left > sz)   result = false;
            }
            else
            {
                if(get_left >= sz)  result = false;
            }


            while(!qr.empty() and (*qr.rbegin()).first == x)
            {
                auto [_, i] = *qr.rbegin();
                ans[i] = result;
                qr.erase(mp(_, i));
            }

            result = true;
            if(bad) result = false;
            if(get_left >= sz)  result = false;

            while(!qr.empty() and (*qr.rbegin()).first > nxt)
            {
                auto [_, i] = *qr.rbegin();
                ans[i] = result;
                qr.erase(mp(_, i));
            }

            if(nxt == 0)    break;
        }

        for(int i = 1; i <= q; i ++)    cout << (ans[i] ? "YES" : "NO") << endl;
    }
}

/*
weak tests, the typo at line 238 should have caused the previous submission to fail on tests like:

1
11 1
1 2 3 4 5 6 7 8 11 10 9
2 0 5 0 0 8 0 11 0 12 0 
15 1 10 9 3
7
*/