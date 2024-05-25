#include<iostream>
using namespace std;
const int N = 5e5 + 5;
long long p[N], x[N], n, ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        char s; cin >> s;
        if (s == 'A') x[i] = 1;
        ans += x[i] * p[i];
    }
    long long a = ans, b = ans;
    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) a -= p[i];
        else a += p[i];
        ans = max(ans, a);
    }
    for (int i = n; i >= 1; i--) {
        if (x[i] == 1) b -= p[i];
        else b += p[i];
        ans = max(ans, b);
    }
    cout << ans;
}