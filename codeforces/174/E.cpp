#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    int mx = max(*max_element(all(a)), *max_element(all(b)));
    vector<int> inv(mx + 1, -1);
    for (int i = 0; i < m; ++i) inv[b[i]] = i;

    int ans = 0;
    int dist = 0;
    for (int L = 0, R = 0; L < n; ++L) {
        while (inv[a[R % n]] != -1 && R - L < n) {
            if (L < R) {
                int newDist = dist + (inv[a[R % n]] + m - inv[a[(R + n - 1) % n]]) % m;
                if (newDist >= m) break;
                dist = newDist;
            }
            ++R;
        }
        ans = max(ans, R - L);
        if (L == R) {
            ++R;
        } else if (L + 1 < R) {
            dist -= (inv[a[(L + 1) % n]] + m - inv[a[L]]) % m;
        }
    }
    cout << ans << '\n';
}