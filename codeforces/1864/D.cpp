#include <iostream>
#include <vector>

using namespace std;

void solv() {
    int n, ans = 0;
    cin >> n;
    vector<string> a(n);

    for (auto &it: a)
        cin >> it;

    vector val(n, vector<bool>(n)), sum(n, vector<bool>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool aici = sum[i][j];

            if (i == 1) {
                for (int k = max(0, j - 1); k <= min(j + 1, n - 1); ++k)
                    aici ^= sum[i - 1][k];
            } else if (i > 1) {
                if (j != 0) aici ^= sum[i - 1][j - 1];
                if (j != n - 1) aici ^= sum[i - 1][j + 1];
                if (j != 0 && j != n - 1) aici ^= sum[i - 2][j];

                aici ^= val[i - 1][j];
            }

            if (aici ^ a[i][j] - '0') {
                ++ans;
                aici = !aici;
                val[i][j] = true;
            }

            sum[i][j] = aici;
        }
    }


    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solv();
}
