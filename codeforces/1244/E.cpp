#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[100'000];
ll k, p[100'001];

bool possible(int diff) {
    for (int lp = 0; lp < n; ++lp) {
        int rp = upper_bound(a, a+n, a[lp] + diff)-a;
        ll steps_needed = (ll)lp*a[lp] - p[lp] + p[n] - p[rp] - (ll)(n-rp)*(a[lp] + diff);
        if (steps_needed <= k) return true; 
    }
    for (int rp = 0; rp < n; ++rp) {
        int lp = lower_bound(a, a+n, a[rp] - diff)-a;
        ll steps_needed = (ll)lp*(a[rp]-diff) - p[lp] + p[n] - p[rp] - (ll)(n-rp)*a[rp];
        if (steps_needed <= k) return true;
    }
    return false;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; ++i) p[i+1] += p[i] + a[i];

    int l = 0, r = 1e9;
    while (l < r) {
        int diff = l + (r - l) / 2;
        if (possible(diff)) r = diff;
        else l = diff + 1;
    }
    cout << l << '\n';
}