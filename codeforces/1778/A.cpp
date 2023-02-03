#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int n, sum = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        vector<int> v;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1] && a[i] == 1)
            {
                v.push_back(sum-4);
            }
            else if (a[i] == a[i + 1] && a[i] == -1)
            {
                v.push_back(sum+4);
            }
            else
            {
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        cout << v[v.size() - 1] << nl;
    }
    return 0;
}