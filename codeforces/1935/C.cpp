// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
void ans(int v)
{
    if (v)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        std::sort(v.begin(), v.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                  { return a.second < b.second; });

        // for (auto it : v)
        // {
        //     cout << it.first << " " << it.second << endl;
        // }
        // cout << endl;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            priority_queue<int> pq;
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += v[j].first;
                pq.push(v[j].first);
                while (!pq.empty() && sum + (v[j].second) - v[i].second > k)
                {

                    int at = pq.top();
                    sum -= at;
                    pq.pop();
                }
                int m=pq.size();
                ans=max(m,ans);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}