#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long double sum = accumulate(v.begin(), v.end(), 0);
    long double avg = sum / n;
    cout<<setprecision(12)<<fixed;

    cout<<avg<<nl;
    return 0;
}