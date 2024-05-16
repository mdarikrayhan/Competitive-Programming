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
    int n ;
    cin>>n;
    vector<int> v(n);
    int ans = 1000000000;
    int even = 0;
    fore(i , n)
    {
        cin>>v[i];
        int x = v[i];
        int cur = 0;
        while(x%2 == 0)
        {
            cur++;
            x/=2;
        }
        even+=(v[i]%2 == 0);
        ans = min(ans , cur);
    }
    if(ans == 0)
    {
        cout<<even<<nl;
    }
    else
        cout<<ans + n - 1<<nl;
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

