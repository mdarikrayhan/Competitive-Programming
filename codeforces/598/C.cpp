#include <bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>> , rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
*/
using namespace std;

#define ll long long
#define X real()
#define Y imag()

typedef long double ld;
typedef complex<double> point;
const double PI=acos(-1),EPS=1e-8;
const int N=1e5+5;


//7awel marra fe 7eatak
void solve() {

    int n, a, b;
    ld m = 2 * PI, x, y;
    cin >> n;

    vector<pair<ld, int>> vp(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vp[i] = {atan2(y, x), i + 1};
    }
    sort(vp.begin(), vp.end());
    a = vp[0].second, b = vp[n - 1].second, m = vp[0].first+2*PI - vp[n - 1].first;
    for (int i = 0; i < n - 1; i++) {
        if (m > vp[i + 1].first - vp[i].first) {
            m = vp[i + 1].first - vp[i].first;
            a = vp[i].second;
            b = vp[i + 1].second;
        }
    }
    cout << a << " " << b;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tests = 1;
    //cin >> tests;
    while (tests--) {
        solve();
        cout << '\n';
    }
    return 0;
}
