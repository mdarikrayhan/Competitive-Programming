// LUOGU_RID: 160414427
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 200000 + 10;
using pii = pair<i64, i64>;
int a[maxn], b[maxn], t[maxn], c[maxn];
int p[maxn], q[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    for (int i=1;i<=n;++i) cin >> a[i], p[i] = i;
    for (int i=1;i<=n;++i) cin >> b[i], q[i] = i;
    for (int i=2;i<=n;++i)
    {
        if (a[i - 1] < a[i]) a[i] = a[i - 1], p[i] = p[i - 1];
        if (b[i - 1] < b[i]) b[i] = b[i - 1], q[i] = q[i - 1];
    }
    for (int i=1;i<=m;++i) cin >> t[i] >> c[i];
    int l = 1, r = n + 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        vector<i64> v;
        for (int i=1;i<=m;++i)
        {
            if (t[i] == 1) v.emplace_back((i64) a[mid] * c[i]);
            else v.emplace_back((i64) b[mid] * c[i]);
        }
        sort(v.begin(), v.end());
        i64 t = 0;
        for (int i=0;i<k;++i) t += v[i];
        if (t <= s) r = mid;
        else l = mid + 1;
    }
    if (r > n) return cout << "-1\n", 0;
    cout << r << '\n';
    vector<pii> v;
    for (int i=1;i<=m;++i)
    {
        if (t[i] == 1) v.emplace_back(pii((i64) a[r] * c[i], i));
        else v.emplace_back(pii((i64) b[r] * c[i], i));
    }
    sort(v.begin(), v.end());
    for (int i=0;i<k;++i) cout << v[i].second << ' ' << (t[v[i].second] == 1 ? p[r] : q[r]) << '\n';
    return 0;
}