#include<bits/stdc++.h>
#define jettdash ios_base::sync_with_stdio(0),cin.tie(0) ,cout.tie(0)
#define ll long long
#define yn(flag) cout<<((flag) ? "YES\n":"NO\n");
#define endl "\n"
#define clr(dp) memset(dp,-1,sizeof dp)
#define all(a) a.begin(),a.end()
#define getmax(v) *max_element(all(v))
#define getmin(v) *min_element(all(v))
#define sum(v) accumulate(all(v),0ll)
int MOD=1e9+7;
using namespace std;

int main() {
    jettdash;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    vector<long double> aa(n), bb(n);
    for (int i = 0; i < n; i++) {
        aa[i] = a[i];
        bb[i] = b[i];
    }
    map<long double, int> mb;
    int ok = 0;
    for (int i = 0; i < n; i++) {
        if (!aa[i] && !bb[i])ok++;
        if (!aa[i])continue;
        mb[bb[i] / aa[i]]++;
    }
    int ans = 0;
    for (auto p: mb) {
        ans = max(ans, p.second);
    }
    ans += ok;
    cout << ans << endl;
}