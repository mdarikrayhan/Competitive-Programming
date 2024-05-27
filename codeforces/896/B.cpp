#include<bits/stdc++.h>
using namespace std;
int n , m , c;
int a[100000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> c;
    for (int i = 1;i <= n;i++) a[i] = 0x7f7f7f7f;
    int l = n , r = n;
    while (1) {
        int t;
        cin >> t;
        int pos = 0;
        if (t <= c / 2) {
            for (int i = 1;i <= l;i++) {
                if (t < a[i]) {
                    a[i] = t , pos = i;
                    break;
                }
            }
        }
        else {
            for (int i = n;i >= l;i--) {
                if (t > a[i] || a[i] == 0x7f7f7f7f) {
                    a[i] = t;
                    pos = i;
                    l = min(l , pos - 1);
                    break;
                }
            }
        }

        cout << pos << endl;
        fflush(stdout);
        int flg = 1;
        for (int i = 1;i <= n;i++) {
            if (a[i] == 0x7f7f7f7f) flg = 0;
        }
        if (flg) break;
    }
}