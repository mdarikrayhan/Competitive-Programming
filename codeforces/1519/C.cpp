#include <bits/stdc++.h>
using namespace std;
int t, n, b, a[200001];
long long s[200001], d[200001];
vector<int> v[200001];
void solve()
{
    fill(d, d + n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i], v[i].clear();
    for (int i = 1; i <= n; i++)
        cin >> b, v[a[i]].push_back(b);
    for (int i = 1; i <= n; i++)
    {
        sort(v[i].rbegin(), v[i].rend());
        int k = v[i].size();
        for (int j = 1; j <= k; j++)
            s[j] = s[j - 1] + v[i][j - 1];
        for (int j = 1; j <= k; j++)
            d[j] += s[k - k % j];
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        solve();
        cout << endl;
    }
    return 0;
}