#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long n, m, dsu[100069], ans[1000069], lo[1000069], hi[1000069];
bool ye = 1;

struct edge
{
    long long u, v, c, id;
    bool operator<(const edge other) const
    {
        return c<other.c;
    }
} ed[1000069], ed1[100069];

vector<long long> qu[100069];

long long fd(long long x)
{
    if (dsu[x] != x) dsu[x] = fd(dsu[x]);
    return dsu[x];
}

int main() 
{
    long long i, j;
    scanf("%lld%lld", &n, &m);
    for (i=1; i<=n; i++) dsu[i] = i;
    for (i=1; i<=m; i++)
    {
        scanf("%lld%lld%lld", &ed[i].u, &ed[i].v, &ed[i].c);
        ed[i].id = i;
    }    
    sort(ed+1, ed+m+1);
    for (i=1, j=0; i<=m; i++)
    {
        ans[i] = -1;
        if (fd(ed[i].u) != fd(ed[i].v)) 
        {
            dsu[fd(ed[i].u)] = fd(ed[i].v);
            ed1[++j] = ed[i];
        }
        else 
        {
            qu[n/2].push_back(i);
            lo[ed[i].id] = 1;
            hi[ed[i].id] = n-1;
        }
    }
    for (;ye;)
    {
        ye = 0;
        for (i=1; i<=n; i++) dsu[i] = i;
        for (i=1; i<=n-1; i++)
        {
            dsu[fd(ed1[i].u)] = fd(ed1[i].v);
            for (; qu[i].size(); )
            {
                ye = 1;
                auto [u, v, c, id] = ed[qu[i].back()];
                if (fd(u) == fd(v)) 
                {
                    ans[id] = ed1[i].c;
                    hi[id] = i-1;
                }
                else lo[id] = i+1;
                if (lo[id]<=hi[id]) qu[(lo[id]+hi[id])/2].push_back(qu[i].back());
                qu[i].pop_back();
            }
        }
    }
    for (i=1; i<=m; i++)
    {
        if (ans[i] != -1) printf("%lld\n", ans[i]);
    }
}