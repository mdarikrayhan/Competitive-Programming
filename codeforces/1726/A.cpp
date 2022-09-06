#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n+5];
        int boroman = INT_MIN,
            chotoman = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i != 0)
            {
                if (boroman < arr[i])
                {
                    boroman = arr[i];
                }
            }
            if (i != n - 1)
            {
                if (chotoman > arr[i])
                {
                    chotoman = arr[i];
                }
            }
        }
        if (n == 1)
        {
            cout << "0" << '\n';
            continue;
        }
        int uttor = max(boroman - arr[0], arr[n - 1] - chotoman);
        for (int i = 0; i < n - 1; i++)
        {
            uttor = max(uttor, arr[i] - arr[i + 1]);
        }
        cout << uttor << '\n';
    }
    return 0;
}