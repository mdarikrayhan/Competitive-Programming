#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
       int a,b,c;
  cin >> a >> b >> c;
 
        if(a > max(b, c)) {
            cout << 0 << " ";
        } else {
            cout << max(b, c) - a + 1 << " ";
        }
        if(b > max(a, c)) {
            cout << 0 << " ";
        } else {
            cout << max(a, c) - b + 1 << " ";
        }
        if(c > max(b, a)) {
            cout << 0 << " ";
        } else {
            cout << max(b, a) - c + 1 << " ";
        }
        cout<<endl;
    }
    return 0;
}