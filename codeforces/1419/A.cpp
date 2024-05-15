#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    if(n&1){
        bool raze = false;
        for (int i = 0; i < n; i += 2)
            if((s[i] - '0') % 2 != 0) raze = true;
        if(raze) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
    else{
        bool breach = false;
        for (int i = 1; i < n; i += 2)
            if((s[i] - '0') % 2 == 0) breach = true;
        if(breach) cout << 2 << '\n';
        else cout << 1 << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(12) << fixed;

    int t = 1; cin >> t;
    while(t--) solve();
    
    return 0;
}