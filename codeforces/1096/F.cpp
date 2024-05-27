/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pint pair<int, int>
#define db double
#define fi first
#define se second
const int maxN = 2e5 + 0307;
const int MOD = 998244353;
const int INF = 1e18;
int pw(int x, int n)
{
    if (n == 1)
        return x;
    if (n == 0)
        return 1;
    int val = pw(x, n / 2);
    if (n % 2 == 0)
    {
        return val * val % MOD;
    }
    else
    {
        return (val * val % MOD) * x % MOD;
    }
}
struct Segment_Tree
{
    vector<int> st;
    int n;
    Segment_Tree()
    {
    }
    Segment_Tree(int n)
    {
        this->n = n;
        st.assign(4 * n + 37, 0);
    }
    void update(int id, int l, int r, int pos, int val)
    {
        int mid = (l + r) >> 1;
        if (l == r)
        {
            st[id] = val;
            return;
        }
        if (pos <= mid)
        {
            update(id * 2, l, mid, pos, val);
        }
        else
        {
            update(id * 2 + 1, mid + 1, r, pos, val);
        }
        st[id] = st[id * 2] + st[id * 2 + 1];
    }
    int getSum(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
        {
            return 0;
        }
        if (u <= l && r <= v)
        {
            return st[id];
        }
        int mid = (l + r) >> 1;
        ;
        int s1 = getSum(id * 2, l, mid, u, v);
        int s2 = getSum(id * 2 + 1, mid + 1, r, u, v);
        return s1 + s2;
    }
};
void solve()

{
    int n;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1), num(n + 1), gt(n + 1, 1), save;
    vector<int> check(n + 1, -1);
    // num[i] so luong j ma a[j] =-1 ma j < i
    // pos[i] so luong so khong xuat hien trong mang ma < i
    for (int i = 1; i <= n; i++)
    {
        gt[i] = (gt[i - 1] * i) % MOD;
    }
    int ans = 0;
    Segment_Tree tree(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != -1)
        {
            ans += tree.getSum(1, 1, n, a[i], n);
            tree.update(1, 1, n, a[i], 1);
            check[a[i]] = i;
        }
        else
        {
            num[i] += 1;
        }
        num[i] += num[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (check[i] == -1)
        {
            save.push_back(i);
            pos[i] = pos[i - 1] + 1;
        }
        else
        {
            pos[i] += pos[i - 1];
        }
        // cout << num[i] << " " << pos[i] << "\n";
    }
    int sz = save.size();
    ans = ans * gt[sz] % MOD;
    for (int i = 1; i <= n; i++)
    {
        if (check[i] != -1)
        {
            ans += (gt[sz - 1] * pos[i] % MOD) * (num[n] - num[check[i]]);
            ans %= MOD;
            ans += (gt[sz - 1] * (sz - pos[i]) % MOD) * num[check[i]];
            ans %= MOD;
        }
    }
    for (int i = 2; i <= save.size(); i++)
    {
        int val = sz * (sz - 1) / 2;
        ans += ((i - 1) * gt[sz - 2] % MOD) * (val % MOD) % MOD;
        ans %= MOD;
    }
    // tính số lượng nghịch thế tạo thành từ các vị trí -1
    // cout << ans << " " << gt[sz] << " " << ans * (pw(gt[sz], MOD - 2)) % MOD;
    cout << ans * (pw(gt[sz], MOD - 2)) % MOD;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--)
    {
        solve();
    }
    return 0;
}
