#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vll vector<long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define f(i,start,end) for(ll i=start;i<end;i++)
#define fr(i,end,start) for(ll i=end;i>=start;i--)
#define all(x) x.begin(),x.end()
const ll mod1 = 1000000007;
const ll mod2 = 998244353;

bool check(set<ll>& s1, set<ll>& s2) {
    for (auto i : s1) {
        if (s2.find(i) == s2.end()) {
            return true;
        }
    }
    return false;
}
//Code goes from here

void solve() {
    ll m, n;
    cin >> m >> n;

    vector<set<ll>> v1(m), v2(m);

    f(i, 0, m) {
        ll x;
        cin >> x;
        while (x--) {
            ll y;
            cin >> y;
            v1[i].insert(y);
        }
        bool no = 0;

        f(j, 0, i) {
            if (!check(v1[i], v2[j])) no = 1;
        }
        if (no) {
            cout << "impossible" << endl;
            return;
        }

        f(j, 1, n + 1) {
            if (v1[i].find(j) == v1[i].end()) {
                v2[i].insert(j);
            }
        }
    }

    cout << "possible" << endl;

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll tt = 1;
    // -cin>>tt;
    while (tt--) {
        solve();
    }
}