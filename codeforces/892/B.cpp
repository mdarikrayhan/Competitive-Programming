#include <iostream>
#include <vector>
#include <string>
#define int long long
 
using namespace std;
 
 
void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 1;
    int s = a[n-1];
    for (int i = n - 2; i >= 0; i--) {
        if (s == 0) {
            cnt++;
        }
        s--;
        s = max(s, a[i]);
    }
    cout << cnt;
}
 
 
signed main() {
    int tt = 1;
    while (tt--) {
        run();
    }
}