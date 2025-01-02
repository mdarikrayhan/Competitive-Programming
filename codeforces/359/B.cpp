#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstring>
#include <array>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, k;
int a[N];

void solve() {
    cin >> n >> k;

    for(int i = 1, j = 2 * n; i <= 2 * n; i ++ , j -- ) {
        a[i] = j;
    }

    for(int i = 1, t = 1; i <= 2 * n && t <= k; i += 2, t ++ ) {
        swap(a[i], a[i + 1]);
    }

    for(int i = 1; i <= 2 * n; i ++ ) {
        cout << a[i] << ' ';
    }

}

int main() {
    int t = 1;
    // cin >> t;
    while(t -- ) {
        solve();
    }
}