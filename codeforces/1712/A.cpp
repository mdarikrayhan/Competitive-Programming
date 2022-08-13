#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long>ab(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ab[i];
        }
        vector<long long>ba(ab.begin(), ab.end());
        sort(ba.begin(), ba.end());
        set<int>s;
        for(int i=0;i<k;i++)
        {
            s.insert(ab[i]);
            s.insert(ba[i]);
        }
        cout<<s.size()-k<<nl;
    }
    return 0;
}