// LUOGU_RID: 160345643
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n;
array<int, N> p, pos, f, sum;
array<bool, N> vis;

struct BIT
{
    array<int, N> tr;

    int LowBit(int x) {return x & -x;}

    void UpDate(int x, int val)
    {
        while (x <= n)
        {
            tr[x] += val;
            x += LowBit(x);
        }
    }    
    
    int Ask(int x)
    {
        int res = 0;
        while (x)
        {
            res += tr[x];
            x -= LowBit(x);
        }
        return res;
    }

    int Query(int l, int r)
    {
        return Ask(r) - Ask(l - 1);
    }

}tr1, tr2, tr3;

bool Check(int mid, int l, int r)
{
    int lmove = tr2.Query(l + 1, mid - 1);
    int rmove = tr2.Query(mid + 1, r);
    lmove = mid - l - lmove;
    rmove = r - mid - rmove;
    return lmove <= rmove;
}

int Find(int l, int r)
{
    int le = l, ri = r, ans = l;
    while (le <= ri)
    {
        int mid = le + ri >> 1;
        if (Check(mid, l, r)) ans = mid, le = mid + 1;
        else ri = mid - 1;
    }
    return ans;
}

void work()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int x = i - 1 - tr1.Ask(pos[i]);
        f[i] = f[i - 1] + x, tr1.UpDate(pos[i], 1);
    }
    int l = n, r = 1;
    for (int i = 1; i <= n; i++) 
    {
        tr2.UpDate(i, 1), tr3.UpDate(i, i);
        vis[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        l = min(l, pos[i]), r = max(r, pos[i]);
        tr2.UpDate(pos[i], -1), tr3.UpDate(pos[i], -pos[i]);
        vis[pos[i]] = 0;
        int mid = Find(l, r);
        int k1 = tr3.Query(l + 1, mid), kk1 = tr2.Query(l + 1, mid);
        int k2 = tr3.Query(mid + 1, r), kk2 = tr2.Query(mid + 1, r);
        sum[i] = (k1 - kk1 * l - (kk1 * (kk1 - 1)) / 2) + (kk2 * r - k2 - (kk2 * (kk2 - 1)) / 2);
    }
    for (int i = 1; i <= n; i++) cout << sum[i] + f[i] << " ";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1, opinput = 0;
    if (opinput) cin >> T;
    while (T--) work();
    return 0;
}