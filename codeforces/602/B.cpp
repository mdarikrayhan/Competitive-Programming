#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &v: a) {
        cin >> v;
    }

    vector<int> cnt(1e5 + 5);
    int ans = 0;
    int j = 0;
    int difference = 0;

    for (int i = 0; i < n; ++i) {
        if (cnt[a[i]] == 0) {
            difference++;
        }
        cnt[a[i]]++;

        while (difference > 2) {
            if (cnt[a[j]] == 1) {
                difference--;
            }
            cnt[a[j]]--;
            j++;
        }

        ans = max(ans, i - j + 1);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
