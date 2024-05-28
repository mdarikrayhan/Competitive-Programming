#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define time_taken_start int begtime = clock();
#define time_taken_end                                                                    \
    int endtime = clock();                                                                \
    cerr << "\n\n"                                                                        \
         << "Time elapsed: " << (endtime - begtime) * 1000 / CLOCKS_PER_SEC << " ms\n\n"; \
    return 0;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define Mod 1000000007
#define mod 998244353
#define inf 100000000000000007
#define eps 0.000000000001
#define pi acosl(-1)
#define pdd pair<ld, ld>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define vpl vector<pll>
#define vll vector<ll>
#define mseti multiset<ll>
#define msetd multiset<ll, greater<ll>>
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define stp fixed << setprecision(20)
#define endl '\n'

void printv(vector<int> &v)
{
    for (auto e : v)
        cout << e << " ";
    cout << endl;
}

int find(int p, vector<int> &par)
{
    if (par[p] == p)
        return p;
    return par[p] = find(par[p], par);
}

void Union(int x, int y, vector<int> &par, vector<int> &sz)
{
    int p1 = find(x, par);
    int p2 = find(y, par);
    if (p1 != p2)
    {
        if (sz[p1] >= sz[p2])
        {
            par[p2] = p1;
            sz[p1] += sz[p2];
        }
        else
        {
            par[p1] = p2;
            sz[p2] += sz[p1];
        }
    }
}

ld a = 0, b = 0, m = 0, vx = 0, vy = 0, vz = 0, x = 0, y = 0, z = 0;

void update(ld t)
{
    x += t * vx;
    y += t * vy;
    z += t * vz;
}

void solve()
{
    cin >> a >> b >> m >> vx >> vy >> vz;
    x = a / 2.0;
    y = m;
    z = 0;
    while (y > 0)
    {
        ld nx, ny, nz, t = 1;
        nx = x + vx;
        ny = y + vy;
        nz = z + vz;
        if (nz > b)
            t = min(t, abs((b - z) / (ld)vz));
        if (nz < 0)
            t = min(t, abs((z) / (ld)vz));
        if (nx < 0)
            t = min(t, abs((x) / (ld)vx));
        if (nx > a)
            t = min(t, abs((a - x) / (ld)vx));
        if (ny < 0)
            t = min(t, abs(y / (ld)vy));
        update(t);
        if (z == 0 || z == b)
            vz = -vz;
        if (x == 0 || x == a)
            vx = -vx;
    }
    cout << fixed << setprecision(6) << x << " " << z << endl;
}

int main()
{
    FAST
#ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    time_taken_start
        ll tt = 1;
    // cin>>t;
    for (ll i = 0; i < tt; i++)
    {
        // cout<<"Case #"<<i+1<<": ";
        solve();
    }
    time_taken_end
}