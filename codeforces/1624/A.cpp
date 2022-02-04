#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int n;
    cin >> n;
    long long int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << arr[n - 1] - arr[0] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}