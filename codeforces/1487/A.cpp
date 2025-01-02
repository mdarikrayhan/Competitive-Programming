#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int nm = 101;
    for (int i = 0; i < n; i++) {
        if(a[i] < nm) nm = a[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] == nm) cnt++;
    }

    cout << n - cnt << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
