#include <bits/stdc++.h>
using namespace std;

int main() {
    int t ;
    cin >> t;

    while(t--){
        int n,k;
        cin >> n >> k;

        int ans = n - (n%k);
        ans += min(n%k,k/2);
        cout << ans << "\n";
    }

    return 0;
}
