#include "bits/stdc++.h"

using namespace std;
const int MAX_ARRAY = 1000000;

// #define MULTIPLE


void solve() {
    int table[101][101] = { 0 };
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        for(int i = x1; i <= y1; i++) {
            for(int j = x2; j <= y2; j++) {
                table[i][j]++;
            }
        }
    }
    int ans{};
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            ans += table[i][j];
        }
    }
    cout << ans << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout.tie(nullptr);

    int tests{ 1 };
#ifdef MULTIPLE
    cin >> tests;
#endif
    while(tests--) {
        solve();
    }
    return 0;
}