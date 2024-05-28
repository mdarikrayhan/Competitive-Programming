// LUOGU_RID: 160403340
#include <bits/stdc++.h>
using namespace std;
typedef array<int, 2> pii;
int n, m;
vector<pii> a[100020];
vector<int> ans;
priority_queue<pii, vector<pii>, greater<pii>> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[n - y + 1].push_back({x, i});
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : a[i])
            q.push(j);
        while (!q.empty() && q.top()[0] < i)
            q.pop();
        if (!q.empty())
            ans.push_back(q.top()[1]), q.pop();
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;
    return 0;
}