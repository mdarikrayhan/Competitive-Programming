#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstring>
#include <array>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
ll a[N];
int n;
int x, y, z; // 最小值，中间值，最大值的个数

void solve() {
    cin >> n;
    ll mx = INT_MIN, mn = INT_MAX, mid = -1;
    for(int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    for(int i = 1; i <= n; i ++ ) {
        if(a[i] == mn) {
            x ++ ;
        } else if(a[i] == mx) {
            z ++ ;
        } else {
            mid = a[i];
            y ++ ;
        }
    }

    if(mid == -1) {
        // 即没有中间值的情况
        mid = (mx + mn) >> 1;
    }

    if(mx - mn <= 1) {
        // 最值相差至多为1，那么直接输出原数组
        cout << n << endl;
        for(int i = 1; i <= n; i ++ ) {
            cout << a[i] << ' ';
        }
    } else {
        // 最值相差为2的情况
        // 我们可以用x和z去变成两个y，也可以用两个y去变成一个x和一个z
        // 我们先考虑第一种情况
        int nx1 = x - min(x, z);
        int ny1 = y + min(x, z) * 2;
        int nz1 = z - min(x, z);
        int p1 = min(x, nx1) + min(y, ny1) + min(z, nz1);
        // 我们再考虑第二种情况
        int nx2 = x + y / 2;
        int ny2 = y - y / 2 * 2;
        int nz2 = z + y / 2;
        int p2 = min(x, nx2) + min(y, ny2) + min(z, nz2);

        if(p1 < p2) {
            cout << p1 << endl;
            for(int i = 1; i <= nx1; i ++ ) {
                cout << mn << ' ';
            }
            for(int i = 1; i <= ny1; i ++ ) {
                cout << mid << ' ';
            }
            for(int i = 1; i <= nz1; i ++ ) {
                cout << mx << ' ';
            }
        } else {
            cout << p2 << endl;
            for(int i = 1; i <= nx2; i ++ ) {
                cout << mn << ' ';
            }
            for(int i = 1; i <= ny2; i ++ ) {
                cout << mid << ' ';
            }
            for(int i = 1; i <= nz2; i ++ ) {
                cout << mx << ' ';
            }
        }

    }

}

int main() {
    int t = 1;
    // cin >> t;
    while(t -- ) {
        solve();
    }
}