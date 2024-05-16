//In The Name Of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fraction(w) cout.unsetf(ios::floatfield); cout.precision(w); cout.setf(ios::fixed, ios::floatfield);

typedef long long ll;
typedef long double ld;

const char nl = '\n';
const int mxx = 1e4 + 123;
ll a[mxx];
ll range = 1e4;

ll cube(ll n) {
    return n*n*n;
}


void solve() {
    ll x; cin >> x;

    for(ll i=1 ; i<=1e4 ; i++) {
        a[i] = cube(i);
    }

    bool flag = false;

    for(ll i=1 ; i<=1e4 ; i++) {
        ll b = x - cube(i);

        bool check = binary_search(a+1,a+range,b);
        if(check) {
            flag = true;
            break;
        }
    }

    if(flag) cout << "YES" << nl;
    else cout << "NO" << nl;
}

int main()
{
    optimize();

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}