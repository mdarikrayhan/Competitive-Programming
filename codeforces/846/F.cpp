#include "bits/stdc++.h"

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define fox(i, n) rep(i, 0, n)
#define rin(i, a, b) rep(i, a, b+1)

using ll = long long;



int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<int, int> m;
    ll tot = 0;
    rin(i, 1, n) {
        int x; cin >> x;

        int p = m[x];
        m[x] = i;

        tot += (ll)2 * (i-p) * (n-i+1) - 1;
    }


    cout << fixed << setprecision(10) << (long double) tot / n / n << '\n';
}