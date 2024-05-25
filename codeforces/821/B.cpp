#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int _tc){
    int m, b; cin>>m>>b;
    int ans = 0;
    for(int y=0; y<=b; ++y){
        int x = m*(b-y);
        ans = max(ans, (x+1)*(y+1)*(x+y)/2);
    }
    cout<<ans<<endl;
}

signed main()
{
#ifdef ARGON
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
    freopen("error.in", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve(tc);
    }
}