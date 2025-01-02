#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define int long long
#define pb push_back
#define nl '\n'
#define fore(i, y) for(int i = 0; i < y; i++)
#define forr(i, x, y) for(int i = x;i<=y;i++)
#define forn(i, y, x) for(int i = y; i >= x; i--)
void run_case()
{
    int x;
    cin>>x;
    if(x == 1)
    {
        cout<<3<<nl;
    }
    else
    {
        if(__builtin_popcount(x) == 1)
        {
            cout<<x + 1<<nl;
        }
        else
        {
            fore(i , 31)
            {
                if((1<<i) & x)
                {
                    cout<<(1<<i)<<nl;
                    break;
                }
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        run_case();
}

