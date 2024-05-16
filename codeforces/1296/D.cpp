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
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<ll> v(n), rem;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ll mid = v[i] / (a + b) - 1;
        v[i] -= mid * (a + b);
        if (v[i] > (a + b))v[i] -= (a + b);
        if (a >= v[i])ans++;
        else rem.push_back(v[i] - a);
    }
    std::sort(rem.begin(), rem.end());
    for (auto x: rem) {
        if (k >= (x + a - 1) / a) {
            k -= (x + a - 1) / a;
            ans++;
        }
    }
    cout << ans << endl;
}