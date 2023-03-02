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
    for (int x = 1; x <= T; x++)
    {
        long long n, sum = 0;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp == 0)
            {
                if (v.size() == 0)
                {
                    continue;
                }
                sort(v.begin(), v.end());
                sum += v[v.size() - 1];
                v.pop_back();
            }
            else
            { // added power
                v.push_back(temp);
            }
        }
        cout << sum << nl;
    }
    return 0;
}