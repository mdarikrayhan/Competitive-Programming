#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define int ll
#define pii pair<int,int>
#define vc vector<int>
#define endl '\n'
#define pb push_back
#define yes() cout<<"YES\n"
#define no() cout<<"NO\n"
const int inf = 2e9;
const int llinf = 1e18 - 1;
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int n, m, k;
void solve() {
    int k1, k2;
    cin >> n >> k1 >> k2;
    vc a(k1 + 1), b(k2 + 1);
    for (int i = 1; i <= k1; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k2; i++) {
        cin >> b[i];
    }
    sort(a.begin() + 1, a.end()), sort(b.begin() + 1, b.end());
    if (a[k1] > b[k2])yes();
    else no();
}
/*
 
 
*/
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    for (int i = 1; i <= _; i++) {
        solve();
    }
    return 0;
}