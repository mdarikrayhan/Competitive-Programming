#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, d; cin >> n >> d;
    vector<int> A(n +1);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end());
    if(A[1] + A[2] <= d || A[n] <= d) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}