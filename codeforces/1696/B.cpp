#include <bits/stdc++.h>
using namespace std;
int a[100005];
int t;
int n;
int ans;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] > 0 && a[i - 1] == 0)
                ans++;
        }
        cout << min(ans, 2) << "\n";
    }
}