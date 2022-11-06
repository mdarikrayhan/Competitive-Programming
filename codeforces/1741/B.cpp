#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 2)
        {
            cout << 2 << ' ' << 1 << '\n';
        }
        else if (n == 3)
            cout << -1 << '\n';
        else
        {
            cout << n - 1 << ' ' << n << ' ';
            for (int i = 1; i < n - 1; i++)
                cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}