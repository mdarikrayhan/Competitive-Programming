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
    for (int e = 1; e <= T; e++)
    {
        long long n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] == 1)
                arr[i - 1] = arr[i - 1] + 1;
            if (arr[i] == 1)
                arr[i] = arr[i] + 1;
            if ((arr[i] % arr[i - 1]) == 0)
            {
                arr[i] = arr[i] + 1;
            }
        }
        for(auto x: arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}