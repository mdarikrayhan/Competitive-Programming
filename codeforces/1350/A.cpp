#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int ans = n;
        for(int i = 2; i <= n; i++) {
            if(n % i == 0) {
                ans += i;
                break;
            }
        }
        ans += 2 * (k - 1);
        cout << ans << endl;
    }
    return 0;
}