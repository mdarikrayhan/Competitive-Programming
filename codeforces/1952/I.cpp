#include "bits/stdc++.h"

using namespace std;
#define ff first
#define ss second
#define rall(vec) vec.rbegin(), vec.rend()
typedef long long ll;
#define eb emplace_back
#define ins insert
#define all(vec) vec.begin(), vec.end()
#define gcd(a, b) __gcd(a, b)
#define len(a) (int)a.size()
#define lcm(a, b) (1ll * (a) * (b))/ gcd(a, b)
#define mod 1000000007ll
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define lw(a, l) lower_bound(a.begin(), a.end(), l)
#define up(a, r) upper_bound(a.begin(), a.end(), r)
#define np(a) next_permutation(all(a))
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define fast std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

istream &operator>>(istream &cin, vector<auto> &a);
istream &operator>>(istream &cin, vector<vector<auto>> &a);
ostream &operator<<(ostream &cout, vector<auto> a);
ostream &operator<<(ostream &cout, vector<vector<auto>> a);
istream &operator>>(istream &cin, vector<auto> &a) {
    for (auto &x: a)
        cin >> x;
    return cin;
}
istream &operator>>(istream &cin, vector<vector<auto>> &a) {
    for (int i = 0; i < len(a); ++i) {
        for (int j = 0; j < len(a[i]); ++j)
            cin >> a[i][j];
    }
    return cin;
}
ostream &operator<<(ostream &cout, vector<auto> a) {
    for (auto i: a)
        cout << i << ' ';
    cout << '\n';
    return cout;
}
ostream &operator<<(ostream &cout, vector<vector<auto>> a) {
    for (int i = 0; i < len(a); ++i) {
        for (int j = 0; j < len(a[i]); ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return cout;
}
ostream &operator<<(ostream &cout, map<auto, auto> mp) {
    for (auto &[x, y]: mp)
        cout << x << ' ' << y << '\n';
    return cout;
}
ostream &operator<<(ostream &cout, unordered_map<auto, auto> mp) {
    for (auto x: mp)
        cout << x.ff << ' ' << x.ss << '\n';
    return cout;
}
ostream &operator<<(ostream &cout, set<auto> s) {
    for (auto i : s)
        cout << i << ' ';
    cout << '\n';
    return cout;
}
ostream &operator<<(ostream &cout, unordered_set<auto> s) {
    for (auto i: s)
        cout << i << ' ';
    return cout;
}
void solve();
main() {
    // fast;
#ifdef selenophile
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;    
    for (int i = 1; i <= t; ++i){
        solve();
    }
    return EXIT_SUCCESS;
}
void solve(){
    char c;
    int a, b; cin >> a >> c >> b;
    cout <<  a + b + a * a + b * b + (a - b) + abs(a) * 2 * b - a * b - 2 ;
}