#include <bits/stdc++.h>
using namespace std;
#define newLine '\n'
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int , int> idx;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            idx[x] = i;
        }
        int mn = min(idx[1] , idx[2]);
        int mx = max(idx[1] , idx[2]);
        if (idx[n] >= mn && idx[n] <= mx) {
            cout << 1 << " " << 1 << newLine;
        } else if (idx[n] >= mn && idx[n] >= mx) {
            cout << mx << " " << idx[n] << newLine;
        } else {
            cout << idx[n] << " " << mn << newLine;
        }
    }
}