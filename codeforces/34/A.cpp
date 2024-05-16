#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, min = INT_MAX;
    cin >> n;
    int a[n], ans[2];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            int x = abs(a[n - 1] - a[i]);
            int y = abs(a[i] - a[i + 1]);
            if (x < y)
            {
                if (x < min)
                {
                    min = x;
                    ans[0] = n;
                    ans[1] = i + 1;
                }
            }
            else
            {
                if (y < min)
                {
                    min = y;
                    ans[0] = i + 1;
                    ans[1] = i + 2;
                }
            }
        }
        else if (i == n - 1)
        {
            int x = abs(a[i - 1] - a[i]);
            int y = abs(a[i] - a[0]);
            if (x < y)
            {
                if (x < min)
                {
                    min = x;
                    ans[0] = i;
                    ans[1] = i + 1;
                }
            }
            else
            {
                if (y < min)
                {
                    min = y;
                    ans[0] = i + 1;
                    ans[1] = 1;
                }
            }
        }
        else
        {
            for (int j = i - 1; j <= i + 1; j++)
            {
                if (j != i)
                {
                    int x = abs(a[j] - a[i]);
                    if (x < min)
                    {
                        min = x;
                        ans[0] = j + 1;
                        ans[1] = i + 1;
                    }
                }
            }
        }
    }
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}