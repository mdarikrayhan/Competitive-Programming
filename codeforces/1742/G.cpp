#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> nums(n);
        ll m_or = 0;
        for (auto i = 0; i < n; i++)
            cin >> nums[i];

        vector<bool> vis(n, false);
        ll k = 31;

        for (auto i = 1; i <= min(n, k); i++) {
            ll l = -1;
            ll max_val = 0;
            for (auto j = 0; j < n; j++) {
                if (vis[j]) continue;
                if ((m_or | nums[j]) > max_val) {
                    max_val = m_or | nums[j];
                    l = j;
                }
            }
            if (l != -1) {
                vis[l] = true;
                m_or |= nums[l];
                cout << nums[l] << " ";
            }
        }

        for (auto i = 0; i < n; i++) {
            if (!vis[i])
                cout << nums[i] << " ";
        }

        cout << endl;
    }

    return 0;
}