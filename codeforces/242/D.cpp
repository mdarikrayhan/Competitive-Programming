#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define filein freopen("input.in", "r", stdin);
#define fileout freopen("output.txt", "w", stdout);
#define ld long double
#define ll long long
#define ull unsigned long long
using namespace std;

int main()
{fastio
    int n, m, x, y;
    cin >> n >> m;
    int arr[n+1], val[n+1] = {};
    vector<int> adj[n+1], ans;
    while (m--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (!arr[i]) s.push(i);
    }
    while (!s.empty())
    {
        x = s.top();
        s.pop();
        if (val[x] == arr[x])
        {
            val[x]++;
            ans.push_back(x);
            for (auto u : adj[x])
            {
                val[u]++;
                if (val[u] == arr[u]) s.push(u);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto u : ans) cout << u << ' ';
}