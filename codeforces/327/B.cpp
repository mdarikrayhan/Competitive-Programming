#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define ll long long
#define PI acos(-1)
#define PHI (long double)1.61803398875 //golden ratio
#define sin(a) sin((a)*PI/180)
#define cos(a) cos((a)*PI/180)
#define tan(a) tan((a)*PI/180)
void Ninja() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool descending(ll a,ll b) {
    return a > b;
}bool descending_Pair(pair<string , ll> pair1 ,pair<string , ll> pair2) {
    if (pair1.second == pair2.second) {
        return pair1.first < pair2.first;
    } else
        return pair1.second > pair2.second;
}bool is_prime(ll x) {
    if (x == 0 || x == 1) return false;
    else {
        for (int i = 2; i*i <= x ; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    }
}
vector<ll> devisors(ll n) {
    vector<ll> v;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if ((n / i) == i) {
                v.push_back(i);
            } else {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
    std::sort(v.begin(), v.end());
    return v;
}
ll sum_digit(ll n) {
    ll sum = 0;
    for (int i = n; i > 0; i /= 10) {
        sum += i % 10;
    }
    return sum;
}
void solve() {
    ll n;
    cin >> n;
    bool prime[10000001];
    memset(prime, true, sizeof prime);
    for (int i = 2; i * i <= 10000000; ++i) {
        if (prime[i]) {
            for (int j = 2 * i; j <= 10000000; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; n > 0; ++i) {
        if (prime[i]) {
            cout << i << " ";
            n--;
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Ninja();
    ll t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}