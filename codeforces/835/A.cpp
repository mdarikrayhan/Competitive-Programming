#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MX = 1000000000000000000;
const ll MOD = MX;
const ll N=1e6+5;

#define FOR(n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

void please_no_TLE() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void test_cases();
void single_solve();

int main() {
    /*freopen("output.txt" , "r" , stdin);
    freopen("pow.out" , "w" , stdout);*/

    please_no_TLE();

    single_solve();
    //test_cases();
}

ll fast_power(ll base, ll power) {
    ll result = 1;
    while(power > 0) {

        if(power & 1) {
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power >>= 1;
    }
    return result;
}

/*******************************/

void test() {

}

void test_cases() {
    ll t; cin >> t;
    while (t--) {
        test();
        cout << '\n';
    }
}

/*******************************/

void single_solve() {
    ll s, v1, v2, t1, t2; cin >> s >> v1 >> v2 >> t1 >> t2;

    ll su1 = 0, su2 = 0;

    su1 = (s * v1) + (2 * t1);
    su2 = (s * v2) + (2 * t2);

    if (su1 > su2) {
        cout << "Second";
    } else if ((su1 < su2)) {
        cout << "First";
    } else {
        cout << "Friendship";
    }
}