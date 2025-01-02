#include<bits/stdc++.h>

using namespace std;

#define int long long
int t, n, k, a[100005];

signed main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        bool check = false;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] == k) check = true;
        }
        bool ans = false;
        a[n + 1] = 0;
a[n+2]=0;
        for (int i = 1; i <= n; i++) {
            if(a[i] >= k && (a[i + 1] >= k || a[i + 2] >= k)) {
                ans = true;
                break;
            }
        }
        if(n == 1 && a[1] == k) ans = true;
        if(!ans || !check) cout << "no\n";
        else cout << "yes\n";
    }
}