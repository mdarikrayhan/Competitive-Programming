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
        long long a, b, n, m, cost1 = 0;
        cin >> a >> b >> n >> m;
        long long mt = m + 1;
        long long mtc = m * a;

        cost1 = (n / mt) * mtc;
        long long left = n % mt;
        long long lca = left * a;
        long long lcb = left * b;
        cost1 = cost1 + min(lca, lcb);
        
        long long cost2 = n * b;

        cout << min(cost1, cost2) << nl;
    }
    return 0;
}