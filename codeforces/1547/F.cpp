// LUOGU_RID: 160141070
#include <bits/stdc++.h>
#define ls (o << 1)
#define rs (o << 1 | 1)
using namespace std;
const int N = 2e5 + 6;
int a[N] , n , t , f[N << 2];
inline void push_up (int o)
{
    f[o] = __gcd (f[ls] , f[rs]);
}
inline void build_tree (int o , int l , int r)
{
    if (l == r) return f[o] = a[l] , void ();
    int mid = l + r >> 1;
    build_tree (ls , l , mid);
    build_tree (rs , mid + 1 , r);
    push_up (o);
}
inline int query (int o , int l , int r , int x , int y)
{
    if (x == l && r == y) return f[o];
    int mid = l + r >> 1;
    if (y <= mid) return query (ls , l , mid , x , y);
    else if (x > mid) return query (rs , mid + 1 , r , x , y);
    else return __gcd (query (ls , l , mid , x , mid) , query (rs , mid + 1 , r , mid + 1 , y));
}
inline int Query (int l , int r)
{
    if (r <= n) return query (1 , 1 , n , l , r);
    else
    {
        int tmp = r - n; r = n;
        return __gcd (query (1 , 1 , n , 1 , tmp) , query (1 , 1 , n , l , r));
    }
}
inline bool check (int len)
{
    int tmp = -1;
    for (int i = 1; i <= n; i++)
    {
        if (tmp == -1) tmp = Query (i , i + len - 1);
        else if (tmp != Query (i , i + len - 1))
            return 0;
    }
    return 1;
}
signed main ()
{
    ios::sync_with_stdio (0);
    cin.tie (0); cout.tie (0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build_tree (1 , 1 , n);
        int l = 1 , r = n , ans = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check (mid)) r = mid - 1 , ans = mid;
            else l = mid + 1;
        }
        cout << ans - 1 << "\n";
    }
    return 0;
}
//rtshr5juyejt
//sr4j6uyhxsr5wjxwsyj
//r6sthjtj6s4rwt6hjunr4t6
//srtjur5thujaq4huqaw4hu