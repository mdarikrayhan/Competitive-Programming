#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    for (ll tc = 0; tc < t; tc++)
    {
        ll n,q;
        cin>>n>>q;
        ll dp[1001][1001];
        for (ll i = 0; i < 1001; i++)
        {
            for (ll j = 0; j < 1001; j++)
            {
                dp[i][j]=0;
            }
            
        }

        for (ll i = 0; i < n; i++)
        {
            ll x,y;
            cin>>x>>y;
            dp[x][y]+=x*y;
        }

        for (ll i = 1; i < 1001; i++)
        {
            for (ll j = 1; j < 1001; j++)
            {
                dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
            
        }

        for (ll i = 0; i < q; i++)
        {
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            ll minus=dp[c-1][d-1]-dp[a][b];
            ll plus=(dp[c-1][d-1]-dp[a][d-1])+(dp[c-1][d-1]-dp[c-1][b]);
            cout<<plus-minus<<endl;
        }
        
        
    }
    
}