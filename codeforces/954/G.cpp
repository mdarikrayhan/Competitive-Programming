/*
Problem: 954G
Date: 28-05-2024 01:00 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

// scan line
// number of archers that can shoot i is:
// sum_{j=i-r}^{i+r} a[j]
// increment a[i + r] by max(0, v - S)
// as we scan, add a[i + r], subtract a[i - r - 1]

const int N = 5e5 + 5;
int n, r;
ll k, a[N], b[N];

ll check(ll v) {
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        b[i] = a[i];
        if(i <= r) {
            sum += b[i];
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(i + r <= n) sum += b[i + r];
        if(i - r - 1 > 0) sum -= b[i - r - 1];
        if(sum < v) {
            ans += v - sum;
            if(ans > k) return ans;
            b[min(i + r, n)] += v - sum;
            sum = v;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll l = 0, r = 2e18;
    while(l < r) {
        ll m = l + (r - l) / 2;
        if(check(m) <= k) {
            l = m + 1;
        }else {
            r = m;
        }
    }
    cout << (l - 1) << '\n';
}