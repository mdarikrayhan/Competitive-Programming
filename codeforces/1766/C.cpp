#include <bits/stdc++.h>
using namespace std;

vector<int> posx = {1, -1, 0, 0};
vector<int> posy = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<bool>> grid(2, vector<bool>(n));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;

                grid[i][j] = c == 'B';
            }
        }

        int pos = -1;

        for (int i = 0; i < n; i++) {
            if (grid[0][i] != grid[1][i]) {
                pos = i;
            }
        }

        if (pos == -1) {
            cout << "YES";
        }
        else {

            int start = (grid[0][pos]) ? 0 : 1;
            int cur;
            bool ok = true;

            cur = start;
            for (int i = pos + 1; i < n; i++) {
                
                if (!grid[cur][i]) {
                    ok = false;
                }

                if (grid[cur^1][i]) {
                    cur ^= 1;
                }
            
            }

            cur = start;
            for (int i = pos - 1; i >= 0; i--) {
                
                if (!grid[cur][i]) {
                    ok = false;
                }

                if (grid[cur^1][i]) {
                    cur ^= 1;
                }
            
            }


            cout << (ok ? "YES" : "NO");
        }

        cout << '\n';

    }

    return 0;
}