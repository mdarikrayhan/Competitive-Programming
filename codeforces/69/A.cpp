#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t;
    // cin >> t;
    t = 1;

    while(t--) {
        int n;
        cin >> n;

        int x = 0, y = 0, z = 0;
        for(int i = 0; i < n; i++) {
            int f, s, t;
            cin >> f >> s >> t;
            x += f;
            y += s;
            z += t;
        }

        if(x == 0 && y == 0 && z == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}  
