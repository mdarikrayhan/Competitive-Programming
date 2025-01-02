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
    for (int x = 1; x <= T; x++)
    {
        long long n, sum = 0;
        cin >> n;
        vector<int> v;
        v.reserve(n);
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp == 0)
            {
                if (!pq.empty())
                {
                    sum += pq.top();
                    pq.pop();
                }
            }
            else
            {
                pq.push(temp);
            }
        }
        cout << sum << nl;
    }
    return 0;
}
