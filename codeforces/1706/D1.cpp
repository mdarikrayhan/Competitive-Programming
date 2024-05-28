#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 3005;

int a[N];

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    if (m > *max_element(a, a + n)) {
        printf("0\n");
        return;
    }
    int ret = 1e9, mn = *min_element(a, a + n);
    for (int i = 1; i <= mn; i++) {
        int mx = -1;
        for (int j = 0; j < n; j++) {
            int t = a[j] / min(m, a[j] / i);
            if (t < i) {
                mx = -1;
                break;
            }
            mx = max(mx, t);
        }
        if (mx != -1) ret = min(ret, mx - i);
    }
    printf("%d\n", ret);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    
    return 0;
}