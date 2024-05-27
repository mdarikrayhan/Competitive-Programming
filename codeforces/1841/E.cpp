#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 998244353;

template<typename T, typename D>
std::ostream& operator<<(std::ostream& os, map<T,D> m) {
    for(auto &x: m) os << x.first << " " << x.second << " | ";
    return os;
}

void add_col(stack<pair<ll,ll>> &s, map<ll,ll> &m, ll i, ll num) {
    ll lo = 0;
    while(s.size() && num >= s.top().first) {
        ll l = i - s.top().second - 1;
        ll amt = s.top().first - lo;
        m[l] += amt;
        lo = s.top().first;
        s.pop();
    }
    if(lo != num && s.size()) {
        ll l = i - s.top().second - 1;
        ll amt = num - lo;
        m[l] += amt;
    }
    s.push({num,i});
}

void solve() {
    ll n; cin >> n;
    stack<pair<ll,ll>> s;
    map<ll,ll> m;
    add_col(s,m,-1,n);
    for(int i = 0; i < n; i++) {
        ll num; cin >> num;
        add_col(s,m,i,num);
    }
    add_col(s,m,n,n);

    ll a; cin >> a;
    map<ll,ll>::iterator it = --m.end();
    ll res = 0;

    // cout << "m : " << m << '\n';

    while(a) {
        pair<ll,ll> p = *it;
        it--;
        if(a >= p.first * p.second) {
            a -= p.first * p.second;
            res += (p.first - 1) * p.second;
        } else {
            ll rows = (a + p.first - 1) / p.first;
            res += a - rows;
            a = 0;
        }
    }
    cout << res << '\n';

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casi; cin >> casi;
    while(casi-->0) solve();

    return 0;
}