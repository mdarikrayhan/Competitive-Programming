#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, idx;
    double time, x[105], xu, yu, vb, vs, ans, dist, min_dist;

    while (cin >> n >> vb >> vs)
    {
        time = min_dist = INT_MAX * 1.0;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        cin >> xu >> yu;

        for (int i = 2; i <= n; i++)
        {
            dist = sqrt(pow(x[i] - xu, 2) + pow(yu, 2));
            ans = dist / vs + x[i] / vb;
            if (ans <= time && dist < min_dist)
            {
                time = ans;
                idx = i;
            }
        }
        cout << idx << endl;
    }
    return 0;
}
