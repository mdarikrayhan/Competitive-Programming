#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#define ll long long
#define ld long double
#define ull unsigned ll
#define st string
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pb push_back
#define ins insert
#define F first
#define S second
#define int ll
using namespace std;
using namespace __gnu_pbds;
const int N = 2e5+5, INF = 2e18+1, MOD = 1e9+7, cnst = 512;
tree <pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> sat;
mt19937_64 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
//
void solve () {
    st s;
    cin >> s;
    int nom = s.find("Q");
    if (nom == -1) {
        cout << "Yes";
        return;
    }
    nom /= 2;
    int kol = 0;
    for (auto to: s) {
        if (to == 'Q') {
            kol ++;
        }
    }
    int k = sqrt(kol);
    int sp = (s.size() - kol) / (k + 1);
    st s1 = s.substr(nom, sp + k);
    st ans = "";
    for (auto to: s1) {
        if (to == 'H') {
            ans += "H";
        }
        else {
            ans += s1;
        }
    }
    if (ans == s) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return;
}
/*
*/
int32_t main()
{
    //
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen ("choco.in", "r", stdin);
    //freopen ("choco.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T --) {
		solve();
    }
    return 0;
}
