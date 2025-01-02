#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define forn(i, n) for (ll i = 0; i < (n); i++)
#define fornn(i,a, n) for (ll i = a; i < (n); i++)
#define INF  1e18+7
#define MO std::ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
void solve()
{
    ll x,k;
    cin >> k >>x;
    ll l=1,r = 2*k -1,ans = 2*k-1;
    while(l<=r)
    {
        ll mid = l+ (r-l)/2;
        ll total = 0;
        if(mid <= k)
        {
            total = (mid*(mid+1))/2;
        }else
        {
            ll u= (k*(k+1))/2;
            ll b = k- (mid-k)-1;
            total = u +((k-1) * k /2)- (b*(b+1))/2;
        }
        if(total >=x)
        {
            ans = mid;
            r= mid-1;
        }else l = mid+1;
    }
    cout << ans << endl;
}
int main()
{
    MO;
    ll t=1;
    cin >> t;
    forn(i,t)
        solve();
}