#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k)
{
    if (k >= n - k)
    {
        cout << -1 << endl;
        return;
    }
    cout << n * k << endl;
    for (int i = 1; i <= n - k; i++)
    {
        for (int j = 1; j <= k; j++)    
            cout << i << " " << i + j << endl;
    }
    for (int i = n - k + 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i + j <= n)
                cout << i << " " << i + j << endl;
            else
                cout << i << " "<< i + j - n << endl;
        }
    }

}
int main()
{
    int n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;
}