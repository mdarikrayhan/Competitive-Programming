#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define fi first
#define se second
#define endl "\n"
const int MOD = 1e9 + 7;
void Solve()
{   
    int n; cin >> n;
    for(int i = 2*n + 2; i <= 4*n; i += 2)
        cout << i << ' ';
 
    cout << '\n';
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        Solve();
    }
    return 0;
}