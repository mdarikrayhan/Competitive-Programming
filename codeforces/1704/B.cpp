#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define F first
#define S second
using namespace std;
using lli = long long int;
using ll = long long;
using vi = vector<lli>;
using vint = vector<int>;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 1e9 + 7;
void solve(){
    int n, x; cin >> n >> x;
    vint a(n);
    vector<vector<int>> v(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = a[0] - x;
    int r = a[0] + x;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        l = max(l, a[i] - x);
        r = min(r, a[i] + x);
        if(l > r) {
            ans++;
            l = a[i] - x;
            r = a[i] + x;
        }
    }
    cout << ans << endl;
}
int main() {
    speed
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
