// LUOGU_RID: 159827116
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define X first
#define Y second
#define SZ(x) (int)x.size()
#define all(A) A.begin(), A.end()
#define mins(a, b) a = min(a, b)
#define maxs(a, b) a = max(a, b)
#define pb push_back
#define Mp make_pair
#define kill(x) cout << x << '\n', exit(0)
#define md(a) (a % MOD + MOD) % MOD
#define lc id << 1
#define rc lc | 1
#define mid ((l + r) >> 1)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e9 + 23;
const ll MOD = 998244353;
const int MXN = 1e5 + 23;
const int LOG = 23;

bool cmp(pair<pll, pll> a, pair<pll, pll> b)
{
    pll x = a.X, y = b.X;
    /*
    x = x.X/x.Y,  y = y.X/y.Y
    x < y => x.X*y.Y < y.X*x.Y
    */
    return x.X * y.Y < y.X * x.Y || (x.X * y.Y == y.X * x.Y && a.Y < b.Y);
}

ll power(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}

int n;
ll x[MXN], v[MXN], p[MXN][2], ip[MXN][2];

ll seg[MXN << 2][2][2];
void Merge(int l, int r, int id)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            seg[id][i][j] = 0;
            for (int k = 0; k < 2; k++)
                seg[id][i][j] = (seg[id][i][j] + seg[lc][i][k] * seg[rc][k][j] % MOD * ip[mid][k]) % MOD;
        }
}
void Build(int l = 0, int r = n - 1, int id = 1)
{
    if (r - l == 1)
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                seg[id][i][j] = p[l][i] * p[r][j] % MOD;
        return;
    }
    Build(l, mid, lc);
    Build(mid, r, rc);
    Merge(l, r, id);
}
void Upd(int pos, int msk, int l = 0, int r = n - 1, int id = 1)
{
    if (r - l == 1)
    {
        seg[id][msk >> 1][msk & 1] = 0;
        return;
    }
    if (pos < mid)
        Upd(pos, msk, l, mid, lc);
    else
        Upd(pos, msk, mid, r, rc);
    Merge(l, r, id);
}

void solve()
{
    cin >> n;
    if(n == 1) kill(0);
    vector<pair<ll, pll>> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> v[i] >> p[i][1];
        vec.pb({x[i], {v[i], p[i][1]}});
    }
    sort(all(vec));
    for (int i = 0; i < n; i++)
    {
        x[i] = vec[i].X;
        v[i] = vec[i].Y.X;
        p[i][1] = vec[i].Y.Y * power(100, MOD - 2) % MOD;
        p[i][0] = (1 - p[i][1] + MOD) % MOD;
        ip[i][1] = power(p[i][1], MOD-2);
        ip[i][0] = power(p[i][0], MOD-2);
    }
    vector<pair<pll, pll>> frac;
    for (int i = 0; i < n - 1; i++)
    {
        frac.pb({{x[i + 1] - x[i], v[i] + v[i + 1]}, {i, 2}});
        if (v[i] > v[i + 1])
            frac.pb({{x[i + 1] - x[i], v[i] - v[i + 1]}, {i, 3}});
        if (v[i] < v[i + 1])
            frac.pb({{x[i + 1] - x[i], v[i + 1] - v[i]}, {i, 0}});
    }
    sort(all(frac), cmp);
    Build();
    ll tot = 1, E = 0;
    for (auto x : frac)
    {
        Upd(x.Y.X, x.Y.Y);
        ll nw = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                nw = (nw + seg[1][i][j]) % MOD;
        E = (E + (tot - nw + MOD) * x.X.X % MOD * power(x.X.Y, MOD - 2)) % MOD;
        tot = nw;
    }
    cout << E << '\n';
}

int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}