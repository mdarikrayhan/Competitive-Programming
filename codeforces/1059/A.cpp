/***************************************************/
/*https://codeforces.com/problemset/problem/1059/A  */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int l, coss;
} p[1000100];
bool cmp(node aa, node bb)
{
    return aa.l < bb.l;
}
main()
{
    memset(p, 0, sizeof(p));
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, L, a;
    cin >> n >> L >> a;
    for (int i = 0; i < n; i++)
        cin >> p[i].l >> p[i].coss; // sort(p,p+n,cmp);
    int ans = 0;
    ans += p[0].l / a;
    for (int i = 0; i < n - 1; i++)
    {
        if (p[i].l + p[i].coss < p[i + 1].l)
            ans += (p[i + 1].l - p[i].coss - p[i].l) / a;
    }
    if (n != 0)
        ans += (L - p[n - 1].l - p[n - 1].coss) / a;
    else
        ans += L / a;
    cout << ans;
}