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
    for (int i = 1; i <= T; i++)
    {
        long long int n;
        cin >> n;
        n--;
        long long int ans = sqrt(n);
        cout << ans << nl;
    }
    return 0;
}