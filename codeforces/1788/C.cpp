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
    for (int i = 1; i <= T; i++)
    {
        int n;
        cin >> n;
        if (n & 1)
        {
            cout << "Yes" << nl;
            int odd=2*n;
            for(int i=1;i<=n;i+=2){
                cout<<i<<" "<<odd<<" "<<nl;
                odd--;
            }
            for(int i=2;i<=n;i+=2){
                cout<<i<<" "<<odd<<" "<<nl;
                odd--;
            }
        }
        else
        {
            cout << "No" << nl;
        }
    }
    return 0;
}