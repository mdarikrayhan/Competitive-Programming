#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > table(n, vector<int>(m));

    // Read the table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> table[i][j];
        }
    }

    long long total_sets = 0;

    // Count subsets in rows
    for (int i = 0; i < n; ++i) {
        int count0 = 0, count1 = 0;
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == 0) {
                ++count0;
            } else {
                ++count1;
            }
        }
        total_sets += (1LL << count0) - 1;
        total_sets += (1LL << count1) - 1;
    }

    // Count subsets in columns
    for (int j = 0; j < m; ++j) {
        int count0 = 0, count1 = 0;
        for (int i = 0; i < n; ++i) {
            if (table[i][j] == 0) {
                ++count0;
            } else {
                ++count1;
            }
        }
        total_sets += (1LL << count0) - 1;
        total_sets += (1LL << count1) - 1;
    }

    cout << total_sets - m*n << endl;
    return 0;
}
