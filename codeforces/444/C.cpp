#include <bits/stdc++.h>
 
using namespace std;

#define int long long
#define inf 0x3F3F3F3F3F3F3F3F

const int MXN = 1e5 + 5;

int st[MXN << 2], lz[MXN << 2];
int v[MXN];

void relax(int l, int r, int x)
{
    if (!lz[x]) return;
    st[x] += (r - l + 1) * lz[x];
    if (l == r)
    {
        lz[x] = 0;
        return;
    }
    lz[2*x] += lz[x];
    lz[2*x + 1] += lz[x];
    lz[x] = 0;
}
void add(int l, int r, int x, int lx, int rx, int val)
{
    if (lx > rx) return;
    relax(l, r, x);
    if (l > rx || r < lx) return;
    if (l >= lx && r <= rx)
    {
        lz[x] += val;
        relax(l, r, x);
        return;
    }
    int mid = (l + r) >> 1;
    add(l, mid, 2*x, lx, rx, val);
    add(mid + 1, r, 2*x + 1, lx, rx, val);
    st[x] = st[2*x] + st[2*x + 1];
}
int get(int l, int r, int x, int lx, int rx)
{
    if (lx > rx) return 0;
    if (l > rx || r < lx) return 0;
    relax(l, r, x);
    if (l >= lx && r <= rx) return st[x];
    int mid = (l + r) >> 1;
    return get(l, mid, 2*x, lx, rx) + get(mid + 1, r, 2*x + 1, lx, rx);
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
        v[i] = i;
    }
    s.insert(n + 1);
    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            if (s.find(l) == s.end()) v[l] = v[*--s.lower_bound(l)];
            if (s.find(r + 1) == s.end()) v[r + 1] = v[*--s.lower_bound(r + 1)];
            s.insert(l);
            s.insert(r + 1);
            auto it = s.begin();
            while ((it = s.lower_bound(l)) != s.end() && *it <= r)
            {
                int lx = *it, rx = *next(it) - 1;
                add(1, n, 1, lx, rx, abs(x - v[lx]));
                s.erase(it);
            }
            s.insert(l);
            v[l] = x;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << get(1, n, 1, l, r) << '\n'; 
        }
    }
}