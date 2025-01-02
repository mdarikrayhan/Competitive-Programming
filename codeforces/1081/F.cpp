// LUOGU_RID: 160599195
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 305;
int n, m, a[N], b[N];
int query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int x; cin >> x; return x;
}
int ask(int l, int r) {
    int now;
    do {
        now = query(l, r);  
        now = query(l, r);
    } while (now == m);
    int x = now - (n - m) + r - l + 1;
    do {
        now = query(l, r);  
        now = query(l, r);
    } while (now != m);
    return x / 2;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    if (n == m * 2 + 1 || n == m * 2 - 1) {
        F(i, 1, n - 1) a[i] = ask(i, i + 1);
        a[n] = m;
        for (int i = 1; i < n; i += 2) a[n] -= a[i];
        dF(i, n - 1, 1) a[i] = a[i] - a[i + 1];
    } else {
        F(i, 1, n) a[i] = ask(i, i);
    } 
    cout << "! "; F(i, 1, n) cout << a[i]; cout << endl;
    return 0;
}
