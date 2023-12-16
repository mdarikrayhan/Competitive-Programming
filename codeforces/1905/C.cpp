#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j, k, m, c = 0;
        cin >> n;
        string a;
        cin >> a;
        vector<int> v;
        char b = 0;
        for (i = n - 1; i >= 0; i--)
        {
            if (b <= a[i])
            {
                v.push_back(i);
                b = a[i];
            }
        }
        m = v.size();
        for (i = 0; i < m / 2; i++)
        {
            swap(a[v[i]], a[v[m - i - 1]]);
        }

        if (!is_sorted(a.begin(), a.end()))
        {
            cout << -1 << endl;
        }
        else
        {
            for (i = n - 2; i >= 0; i--)
            {
                if (a[i] != a[i + 1])
                {
                    break;
                }
                c++;
            }
            cout << m - c - 1 << endl;
        }
    }
}
