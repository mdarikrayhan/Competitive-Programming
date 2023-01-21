#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int N = 1000000;
    vector<int> lp(N + 1);
    vector<int> pr;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
        {
            lp[i * pr[j]] = pr[j];
        }
    }
    int T = 1;
    cin >> T;
    for (int z = 1; z <= T; z++)
    {
        long long low, high, count = 0;
        cin >> low >> high;
        long long nsqrt = ceil(sqrt(high));

        for(auto v: pr)
        {
            if(v >= nsqrt)
                break;
            long long temp = v;
            while (true)
            {
                temp = temp * v;
                if (temp > high)
                    break;
                if (temp >= low)
                    count++;
            }
        }
        cout << count << nl;
    }
    return 0;
}