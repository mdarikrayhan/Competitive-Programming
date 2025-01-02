#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0;
    do
    {
        if (count == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << nl;
            break;
        }
        count++;
    } while (prev_permutation(arr, arr + n));

    return 0;
}