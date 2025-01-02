#include <bits/stdc++.h>
using namespace std;
#define ll long long
//
const int N = 1e5;
int n , k;
int a[N] , b[N];

bool is_valid (ll cakes) {
    ll cost = 0;
    for (int i = 0; i < n; i++) {
        ll need = cakes * a[i];
        if (need > b[i])
            cost += (need - b[i]);
        if (cost > k)
            return false;
    }
    return cost <= k;
}

int main () {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll start = 0 , end = 1e10 , mid , ans = 0;
    while (!(start > end)) {
        mid = start + (end - start) / 2;
        if (is_valid(mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << ans;
}