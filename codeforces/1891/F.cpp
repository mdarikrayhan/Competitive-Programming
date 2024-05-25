/*जय श्री महाकाल!*/
/* जय श्री गणेश! */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define int long long
#define double long double
#define inp0(a, n)              \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define out1(x) cout << x << endl;
#define out2(a, b) cout << a << " " << b << endl;
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;
#define out0(a, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << a[i] << " ";    \
    }                           \
    cout << endl;
#define sz(s) (long long)(s.size())
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define rep(i, a, b) for (long long i = a; i < b; ++i)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define vi vector<long long>
#define vv vector<vector<long long>>
const int MOD = 1e9 + 7;
#define INF (int)1e18

#define dbg(x) cout << #x << " is " << x << endl;
#define dbgarr(x)                      \
    cout << #x << " is:" << endl;      \
    for (int i = 0; i < x.size(); i++) \
    {                                  \
        cout << x[i] << " ";           \
    }                                  \
    cout << endl;
#define dbgarrp(x)                                               \
    cout << #x << " is:" << endl;                                \
    cout << "( ";                                                \
    for (int i = 0; i < x.size(); i++)                           \
    {                                                            \
        cout << "[" << x[i].first << " " << x[i].second << "],"; \
    }                                                            \
    cout << " )";                                                \
    cout << endl;

constexpr int N = (int)5e5 + 10;
#define dbg(x) cout << #x << " is " << x << endl;

int janm_hone_ke_pahle_ka_sum[N], bit[N];
int n;

void init()
{
    fill(bit, bit + n + 1, 0ll);
}

void add(int s, int val)
{
    for (int x = s; x <= n; x += x & -x)
    {
        bit[x] += val;
    }
}

int sum(int s)
{
    int res = 0;
    for (int x = s; x > 0; x -= x & -x)
    {
        res += bit[x];
    }
    return res;
}

vector<int> adj[N];
int Start[N], End[N], timer;

void dfs(int u)
{
    Start[u] = ++timer;
    for (int v : adj[u])
    {
        dfs(v);
    }
    End[u] = timer;
}

void solve()
{
    int q;
    cin >> q;

    vector<tuple<int, int, int>> query(q);
    n = 1;
    adj[1].clear();
    janm_hone_ke_pahle_ka_sum[1] = 0;
    timer = 0;

    for (auto &[t, v, x] : query)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> v;
            adj[v].push_back(++n);
            adj[n].clear();
            x = n;
        }
        else if (t == 2)
        {
            cin >> v >> x;
        }
        else
        {
            assert(false);
        }
    }
    dfs(1);
    init();

    for (auto &[t, v, x] : query)
    {
        if (t == 1)
        {

            janm_hone_ke_pahle_ka_sum[x] = sum(Start[x]);
        }
        else if (t == 2)
        {
            add(Start[v], +x);
            add(End[v] + 1, -x);
        }
        else
        {
            assert(false);
        }
    }

    for (int i = 1; i <= n; i++)
    {

        cout << sum(Start[i]) - janm_hone_ke_pahle_ka_sum[i] << " \n"[i == n];
    }
}

signed main()
{

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
