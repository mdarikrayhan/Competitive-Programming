#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        char op;
        long long a, b,ans=0;
        cin >> a >> b>> op;

        if (op == '+')
            ans = a + b;
        else if (op == '-')
            ans = a - b;
        else if (op == '*')
            ans = a * b;
        else if (op == '/')
            ans = a / b;
        else if (op == '%')
            ans = a % b;

        cout << "Case " << i << ": " << ans << nl;
    }
    return 0;
}