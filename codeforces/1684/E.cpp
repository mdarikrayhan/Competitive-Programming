#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    int mex = 0;
    for (int j = 0; j < k || mp.count(mex); mex++)
    {
        if(!mp.count(mex))
        {
            j++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &[x, y] : mp)
    {
        if(x > mex)
            pq.push(y);
    }
    while (!pq.empty() && k)
    {
        int t = pq.top();
        pq.pop();
        if(k >= t)
            k -= t;
        else
        {
            t -= k;
            pq.push(t);
            break;
        }
    }
    printf("%d\n", pq.size());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
