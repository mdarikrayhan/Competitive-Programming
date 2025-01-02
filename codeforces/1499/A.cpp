// LUOGU_RID: 159113764
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010;

void solve(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int mn = min(a, b);
    int mb = min(n - a, n - b);
    c -= mn, d -= mb;
    int e = abs(a - b);
    int g = e / 2;
    c -= g, d -= g;
    if(c <= 0 && d <= 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

signed main(){
    int t;
    cin >> t;
    while(t --)
    solve();

    return 0;
}