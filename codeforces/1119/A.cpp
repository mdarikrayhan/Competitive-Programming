#include <bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p, cr, pr, F = 0, L;
    cin >> n >> p;
    pr = p;
    for(int i = 1; i < n; ++ i) {
        cin >> cr;
        if(cr != pr) {
            if(!F) {
                F = i;
            }
            L = i;
        }
        pr = cr;
    }
    cout << (p == cr ? max(L, n - F) : n) - 1; 
}
