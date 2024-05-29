#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[500001], cost[500001], tot, num[500001], nowres[500001], sum, ans;
priority_queue<int> q;
int cmp(int a, int b)
{
    return a > b;
}
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        ans+=a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1] || i == 1)
            cost[++tot] = a[i], num[tot]++;
        else
            num[tot]++;
    }
    for (int i = 1; i <= tot; i++)
    {
        int sz=q.size();
        int sy = min(sum - sz * 2, num[i]);
        int now = 0;
        int res = min(num[i], sum) - sy;
        for (int j = 1; j <= sy; j++)
            nowres[++now] = cost[i];
        for (int j = 1; j <= res; j+=2)
        {
            int x = -q.top();
            q.pop();
            if (x < cost[i])
            {
                nowres[++now] = cost[i];
                if (j < res)
                    nowres[++now] = cost[i];
            }
            else
            {
                nowres[++now] = x;
                if (j < res)
                    nowres[++now] = 2 * cost[i] - x;
            }
        }
        for (int j = 1; j <= now; j++)
        {
            if (nowres[j] >= 0)
                q.push(-nowres[j]);
        }
        sum += num[i];
    }
    while (!q.empty())
    {
        ans += q.top();
        q.pop();
    }
    printf("%lld\n", ans);
    return 0;
}