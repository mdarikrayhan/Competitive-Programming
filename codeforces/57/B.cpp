#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    long long res;
    vector<long long> a, b, c, q;
    
    cin >> n >> m >> k;
    a.resize(m);
    b.resize(m);
    c.resize(m);
    q.resize(k);

    for (int i = 0; i < m; i ++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i < k; i ++)
    {
        cin >> q[i];
    }

    res = 0;
    for (int i = 0; i < k; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            if ((q[i] <= b[j]) && (a[j] <= q[i]))
                res += c[j] + (q[i] - a[j]);

        }
    }

    cout << res << "\n";

    return 0;
}