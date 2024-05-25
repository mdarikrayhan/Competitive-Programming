#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int x, y;
    cin >> x >> y;
    vector<long long int> v(x);
    for (int i = 0; i < x; i++)
        cin >> v[i];
    long long int max_count = 0, count = 1; 
    sort(v.begin(), v.end());
    for (long long int i = 0; i < x - 1; i++)
    {
        if (v[i + 1] - v[i] <= y)
        {
            count++;
        }
        else
        {
            if (count > max_count)
            {
                max_count = count;
            }
            count = 1; 
        }
    }
    if (count > max_count) 
    {
        max_count = count;
    }
    cout << x - max_count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cf;
    cin >> cf;
    while (cf--)
    {
        solve();
    }
    return 0;
}
