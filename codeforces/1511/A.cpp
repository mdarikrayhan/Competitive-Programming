#include <bits/stdc++.h>
using namespace std;
// #define int unsigned long long

signed main()
{
    int t;
    cin >> t;
    int i;
    while (t--)
    {
        int n;
        cin >> n;
        int a, u = 0, d = 0;
        for (i = 0; i < n; i++)

        {
            cin >> a;
            if(a==1)u++;
            else if(a==2)d++;
            
            else u++;
        }
        cout<<u<<endl;
    }
}