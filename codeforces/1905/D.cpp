#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        
        deque<pair<int, int>> q;
        int mn = INT_MAX, sum = 0, ans = 0;
        for (int i = n - 1; i >= 1; i--) {
            mn = min(mn, a[i]);
            q.push_front({mn, 1});
            sum += mn;
        }
        ans = sum;
        for (int i = 0; i < n - 1; i++) {
            int c = 1;
            q.front().second--;
            sum -= q.front().first;
            if (q.front().second == 0) q.pop_front();
            while (!q.empty() && q.back().first >= a[i]) {
                sum -= q.back().first * q.back().second;
                c += q.back().second;
                q.pop_back();
            }
            sum += c * a[i];
            q.push_back({a[i], c});
            ans = max(ans, sum);
        }
        cout << ans + n << endl;
    }
    return 0;
}