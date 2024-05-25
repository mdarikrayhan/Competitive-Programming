// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, s = 0;
//     cin >> n;
//     int a[101][101];
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//             cin >> a[i][j];
//     vector<int> save;
//     for (int i = 1; i <= n; i++)
//     {
//         int m = INT_MIN;
//         for (int j = 1; j <= n; j++)
//         {
//             if (a[i][j] > m && m != 0)
//             {
//                 m = a[i][j];
//             }
//         }
//         save.push_back(m);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (save[i] != n - 1 && s == 0)
//         {
//             save[i] = n;
//             s = 1;
//         }
//         cout << save[i] << " ";
//     }
//     cout << endl;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, s = 0;
    cin >> n;
    int a[n][n], ans[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] > ans[i])
                ans[i] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == n - 1 && s == 0)
        {
            ans[i] = n;
            s = 1;
        }
        cout << ans[i] << " ";
    }
    return 0;
}
