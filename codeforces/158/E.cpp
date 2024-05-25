
#include <bits/stdc++.h>
using namespace std;

int main ()
    {
    ios::sync_with_stdio (0), cin.tie (0);

    int n, k, t, d, r = 0;

    cin >> n >> k;

    vector <int> M (n + 1), M_ (M);

    for (int i = 1; i <= n; ++i)
        {
        cin >> t >> d, --t;

        M_[0] = max (M[0], t) + d;

        for (int jmin = max (1, k - (n - i)), jmax = min (i, k),
                 j = jmin; j <= jmax; ++j)

            M_[j] = min (M[j - 1], max (M[j], t) + d);

        if (i > k) r = max (r, t - M[k]);

        M = M_;
        }

    cout << max (r, 86400 - M[k]);
    }
