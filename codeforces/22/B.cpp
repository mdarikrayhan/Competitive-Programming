#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);

    
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int ans = 0;

    for (int start_row = 0; start_row < n; ++start_row) {
        for (int start_col = 0; start_col < m; ++start_col) {
            if (grid[start_row][start_col] == '1') continue;

            for (int end_row = start_row; end_row < n; ++end_row) {
                for (int end_col = start_col; end_col < m; ++end_col) {
                    bool valid = true;

                    for (int i = start_row; i <= end_row && valid; ++i) {
                        for (int j = start_col; j <= end_col; ++j) {
                            if (grid[i][j] == '1') {
                                valid = false;
                                break;
                            }
                        }
                    }

                    if (valid) {
                        int width = end_col - start_col + 1;
                        int height = end_row - start_row + 1;
                        int per = 2 * (width + height);
                        ans = max(ans, per);
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
