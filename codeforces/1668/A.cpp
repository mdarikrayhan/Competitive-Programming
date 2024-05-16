#include <bits/stdc++.h>
 
using namespace std;
int t, n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n<m) {
            swap(n, m);
        }
        if (m==1 && n>=3) {
            cout << -1 << "\n";
        } else {
            cout << 2*n-2-(n+m)%2 << "\n";
        }
    }
    return 0;
}