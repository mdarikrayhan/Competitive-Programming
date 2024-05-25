/*
Mayoeba Yabureru
*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n, l = 0;
    cin >> n;
    vector<int> a(n), ans(n, -1), sum(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        l += a[i];
    }
    l /= n;

    for (int i = n - 1; i >= 0; i --) {
        if (i != n - 1) sum[i] += sum[i + 1];
        int ad = sum[i];
        sum[i] --;
        if (i - l >= 0) sum[i - l] ++;
        if (a[i] + ad == i + 1) {
            ans[i] = 1;
            l --;
        }
        else ans[i] = 0;
    }
    for (int i = 0; i < n; i ++) cout << ans[i] << ' ';
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;

    while ( T -- ){
        solve();
    }
}