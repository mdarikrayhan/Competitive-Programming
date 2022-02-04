#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, c = 0;
    cin >> n;
    int a[100000];
    i = 0;
    for (i = 0; i < n; i++)
        cin >> a[i];

    for (i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1])
            c++;
    }
    cout << c << endl;

    return 0;
}