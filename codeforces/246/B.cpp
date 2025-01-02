#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;

    vector<ll> a(n);

    ll sm = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }

    ll num = sm / n;
    if (sm % n != 0) cout << n - 1 << "\n";
    else cout << n << "\n";
}
