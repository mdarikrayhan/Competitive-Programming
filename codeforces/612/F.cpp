// LUOGU_RID: 160379585
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 2000 + 10;
constexpr int maxm = maxn * maxn * 2;
int d[maxm], l[maxm], e[maxm];
struct edge
{
    int v, w;
    bool operator<(const edge& b) const
    {
        return w > b.w;
    }
    edge(int _v=0, int _w=0) : v(_v), w(_w) {}
};
int a[maxn];
int p[maxn][maxn][2];
int get(int n, int i, int j)
{
    if ((j - i + n) % n <= (i - j + n) % n) return (j - i + n) % n;
    else return -((i - j + n) % n);
}
void out(int x)
{
    cout << (x >= 0 ? '+' : '-') << abs(x) << '\n';
}
void chk(int x, int y, int z)
{
    if (d[x] > d[y] + abs(z)) d[x] = d[y] + abs(z), l[x] = y, e[x] = z;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    --s;
    int m = n;
    map<int, vector<int> > mp;
    for (int i=0;i<n;++i)
    {
        cin >> a[i];
        mp[a[i]].emplace_back(i);
    }
    int st = ++m, ok = 0;
    memset(d, 0x3f, sizeof(d));
    d[st] = 0;
    for (auto [x, v] : mp)
    {
        int k = v.size();
        if (!ok)
        {
            for (int i : v) chk(i, st, get(n, s, i));
            ok = 1;
        }
        for (int i=0;i<k;++i)
            for (int j=0;j<k;++j) p[i][j][0] = ++m, p[i][j][1] = ++m;
        for (int i=0;i<k;++i) chk(p[i][i][0], v[i], 0);
        int mn = 0x3f3f3f3f;
        for (int i=0;i<n;++i) if (a[i] > x) mn = min(mn, a[i]);
        for (int c=0;c+1<k;++c)
            for (int i=0,j=c;i<k;++i,j=(j+1)%k)
            {
                chk(p[(i + k - 1) % k][j][0], p[i][j][0], get(n, v[i], v[(i + k - 1) % k]));
                chk(p[(i + k - 1) % k][j][0], p[i][j][1], get(n, v[j], v[(i + k - 1) % k]));
                chk(p[i][(j + 1) % k][1], p[i][j][1], get(n, v[j], v[(j + 1) % k]));
                chk(p[i][(j + 1) % k][1], p[i][j][0], get(n, v[i], v[(j + 1) % k]));
            }
        for (int i=0;i<k;++i)
        {
            if (mn == 0x3f3f3f3f)
            {
                chk(n, p[i][(i + k - 1) % k][0], 0);
                chk(n, p[i][(i + k - 1) % k][1], 0);
            }
            else for (int j : mp[mn])
            {
                chk(j, p[i][(i + k - 1) % k][0], get(n, v[i], j));
                chk(j, p[i][(i + k - 1) % k][1], get(n, v[(i + k - 1) % k], j));
            }
        }
    }
    cout << d[n] << '\n';
    vector<int> pt;
    for (int u=n;u!=st;u=l[u]) if (e[u]) pt.emplace_back(e[u]);
    if (pt.size() != n) pt.emplace_back(0);
    for (; pt.size(); pt.pop_back()) out(pt.back());
    return 0;
}