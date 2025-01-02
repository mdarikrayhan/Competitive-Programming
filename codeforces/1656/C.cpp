// LUOGU_RID: 159208156
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int a[N];
void solve() {
    int n;
    cin >> n;
    int flag1 = 0, flag0 = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(a[i] == 1) flag1 = 1;
        if(a[i] == 0) flag0 = 0;
    }
    sort(a + 1, a + n + 1);
    if(flag1) {
        for(int i = 2; i <= n; i ++) {
            if(a[i] - a[i - 1] == 1) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while(T --) solve();
}