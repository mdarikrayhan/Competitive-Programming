#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vii = vector<pii>;
using vll = vector<pll>;;
using vvi = vector<vi>;

#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int nc; cin >> nc;
    map<string, array<int, 55>> mp, mp1;
    vi arr = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    while(sz(arr) < 55) arr.pb(0);
    rep(cn, 0, nc){
        int n; cin >> n;
        rep(i, 0, n){
            string str; cin >> str;
            mp[str][0] += arr[i];
            mp[str][i+1]++;
            // mp1[str][i == 0 ? 0 : i+1]++;
            // mp1[str][1] += arr[i];
            // mp[str].f += i < sz(arr) ? arr[i] : 0;
            // if(i == 0) mp[str].s++;
        }
    }
    vector<pair<array<int, 55>, string>> ps, ps1;
    for(auto [key, val] : mp){
        ps.pb({val, key});
        auto v1(val);
        swap(v1[0], v1[1]);
        ps1.pb({v1, key});
    }
    // for(auto [key, val] : mp1){
    //     ps1.pb({val, key});
    // }
    sort(all(ps));
    sort(all(ps1));
    reverse(all(ps));
    reverse(all(ps1));
    cout << ps[0].s << "\n";
    cout << ps1[0].s << "\n";

    
    return 0;
}
