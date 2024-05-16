#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;

        vector<int> a(n+1);
        for(int i=1; i<=n; i++)
            cin >> a[i];

        vector<int> b = a;
        reverse(b.begin()+1,b.end());

        int ans = 0, x = 1;

        while( x < n )
        {
            if( b[x+1] == b[1] ){
                x ++;
                continue;
            }
            ans ++;
            x *= 2;
        }

        cout << ans << '\n';
    }

    return 0;
}
