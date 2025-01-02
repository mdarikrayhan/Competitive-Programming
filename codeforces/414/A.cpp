#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> v;
    ll cur = 1;
    while (n >= 4) {
        v.push_back(cur);
        cur += 1;
        v.push_back(cur);
        cur += 1;
        n -= 2;
        k -= 1;
    }
    if (n == 1) {
        v.push_back(1e9);
        if (k == 0) {
            for (ll i : v)
                cout << i << " ";
        } else {
            cout << -1;
        }
        return 0;
    }
    if (k <= 0) {
        cout << -1;
    } else {
        v.push_back(10000019 / k * k + k);
        v.push_back(10000019 / k * k + k + k);
        if (n == 3)
            v.push_back(1e9);
        for (ll i : v)
            cout << i << " ";
    }
}