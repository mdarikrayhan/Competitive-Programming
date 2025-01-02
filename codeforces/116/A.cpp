#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int max = INT_MIN;
    int sum = 0,a,b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        sum = sum - a + b;
        if (sum > max)
        {
            max = sum;
        }
    }
    cout << max << nl;
    return 0;
}