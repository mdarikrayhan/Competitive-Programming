#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

struct DSU
{
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int find(int x) 
    {
        //return x == f[x] ? x : find(f[x]);
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) 
    {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

void solve()
{
    int n, q;
    std::cin >> n >> q;
    DSU d(n);
    std::vector<int> nxt(n);
    std::iota(nxt.begin(), nxt.end(), 1);
    while(q--)
    {
        int u, v, t;
        std::cin >> t >> u >> v;
        u--, v--;
        if(t == 1)
        {
            d.merge(u, v);
        }
        else if(t == 3)
        {
            if(d.same(u, v))
            {
                std::cout << "YES\n";
            }
            else
            {
                std::cout << "NO\n";
            }
        }
        else
        {
            for(int i = u; nxt[i] <= v;)
            {
                d.merge(i, nxt[i]);
                int c = nxt[i];
                nxt[i] = nxt[nxt[i]];
                i = c;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
  	 			 	 				 				 					 	  	