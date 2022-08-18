#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    
    {
        int n;
        cin >> n;
        int arr[n + 10];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        cout << ((arr[n - 1] + arr[n - 2]) - arr[0] - arr[1]) << nl;
    }
    return 0;
}