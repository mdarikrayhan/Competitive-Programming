//Ajay Kumar
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define TEST_CASES int t; cin >> t; while (t--)

int main() {
    TEST_CASES {
        int n;
        cin >> n;

        vector<int> frequency(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            frequency[x]++;
        }

        ll totalPairs = static_cast<ll>(n) * (n - 1) / 2;
        vector<ll> f(n + 1, 0);

        for (int i = n; i > 0; --i) {
            ll count = 0;
            for (int j = i; j <= n; j += i) {
                count += frequency[j];
                f[i] -= f[j];
            }
            f[i] += count * (count - 1) / 2;
        }

        for (int i = 1; i <= n; ++i) {
            if (frequency[i] > 0) {
                for (int j = i; j <= n; j += i) {
                    totalPairs -= f[j];
                    f[j] = 0;
                }
            }
        }

        cout << totalPairs << "\n";
    }

    return 0;
}
