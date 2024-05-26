// Author: Debjit Saha

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define int long long
#define lld long double
// #define int long long
#define endl '\n'
#define tab '\t'
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vb vector<bool>
#define rep(n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=0;i<n;i++)
#define yes(check) cout << (check ? "YES\n" : "NO\n")
#define gcd(a,b) __gcd(a,b)
const int mod=1e9+7;

void solve() {
    int n, m;
    cin >> n >> m;
    if(n==2) {
        cout << 0 << endl;
        return;
    }

    vb row(n+1, 1), col(n+1, 1);
    rep(m) {
        int a, b;
        cin >> a >> b;
        if(a>1 && a<n) row[a] = 0;

        b = n-b+1;
        if(b>1 && b<n) col[b] = 0;
    }
    int cnt=0;
    for(int i=2; i<n; i++)
        cnt += row[i] + col[i];
    if(n%2 && row[n/2+1] && col[n/2+1]) cnt--;
    cout << cnt;
}

signed main() {
    fast;

    // int t; cin >> t;
    // while(t--) solve();

    solve();
    return 0;
}