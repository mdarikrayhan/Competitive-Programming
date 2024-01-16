#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        pair<int, int> cord[4];
        for (int i = 0; i < 4; i++)
        {
            cin >> cord[i].first >> cord[i].second;
        }
        sort(cord, cord + 4);
        int side=cord[0].second-cord[1].second;
        cout<<side*side<<nl;
    }
    return 0;
}