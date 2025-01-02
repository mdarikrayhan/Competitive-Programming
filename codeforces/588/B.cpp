#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#define endl            "\n"
#define ll              long long
#define dl              double
#define ld              long double
#define OOO             -1e18
#define OO              1e18
#define f(i, in, n)     for (ll (i) = (0); i < (n); i++)
#define f1(i, in, n)    for (ll (i) = (1); i <= (n); i++)
#define ve              vector < int > v;
#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define pi              3.141592654
#define se(n)           fixed<<setprecision(n)
#define cin(v)          for(auto&it:v)cin>>it;
#define ct(v)           for(auto it : v)cout<<it<<" ";
#define init            memset(dp, -1, sizeof dp);
using namespace std;
void File() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void Mentgreen() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
ll gcd(ll  a, ll  b) { return  b == 0 ? a : gcd(b, a % b); }
const int N = 3e5 + 5, MOD = 1e9 + 7;
void solve() {

    ll n; cin >> n;
    if (n == 1)return cout << 1 << endl, void();
    for (ll i = 2; i * i <= n; i++) {
        while (n % (i * i) == 0)n /= i;
    }
    cout << n << endl;

}
int main() {
    //File();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    Mentgreen;
    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}