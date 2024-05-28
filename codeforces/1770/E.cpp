#include <iostream>
#include <vector>
using namespace std;

#define MAXN 300005
#define MOD 998244353ll
#define I1 998244354ll
#define I2 499122177ll

using ll = long long;
using pii = pair<int, int>;

int siz[MAXN];
ll p[MAXN];

int fa[MAXN];

vector<int> e[MAXN];
vector<pii> ed;

ll pow(ll b, ll p, ll m)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        b = b * b % m;
        p >>= 1;
    }
    return r;
}

int n, k;

void dfs(int u, int f)
{
    fa[u] = f;
    siz[u] = p[u];
    for (int v : e[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
        siz[u] += siz[v];
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int a;
        cin >> a;
        p[a]++;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ed.push_back({u, v});
    }
    dfs(1, 1);
    ll res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u = ed[i].first, v = ed[i].second;
        if (fa[u] != v) // 只有一边的点的 siz 才是文中所谓的 x
        {
            swap(u, v);
        }
        // u to v
        ll pb = p[u] * (I1 - p[v]) % MOD;
        res = (res + pb * (siz[u] - 1) % MOD * (k - siz[u] + 1) % MOD) % MOD;
        res = (res + (I1 - pb) * siz[u] % MOD * (k - siz[u]) % MOD) % MOD;
        // v to u
        pb = (I1 - p[u]) * p[v] % MOD;
        res = (res + pb * (siz[u] + 1) % MOD * (k - siz[u] - 1) % MOD) % MOD;
        res = (res + (I1 - pb) * siz[u] % MOD * (k - siz[u]) % MOD) % MOD;
        p[u] = p[v] = (p[u] + p[v]) % MOD * I2 % MOD;
    }
    res = res * pow(k, MOD - 2, MOD) % MOD;
    res = res * pow(k - 1, MOD - 2, MOD) % MOD;
    cout << res << endl;
    return 0;
}
