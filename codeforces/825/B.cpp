#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
bool valid(int r, int c) {
    return r >= 0 && r < 10 && c >= 0 && c < 10;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    vector<string> v(10);
    for (auto &s : v) {
        cin >> s;
    }

    int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1};
    int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

    bool ok = false;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 8; ++k) {
                int x = i, y = j, c = 0, cx = 0, cd = 0;
                while (c < 5 && valid(x, y)) {
                    c += 1;
                    cx += v[x][y] == 'X';
                    cd += v[x][y] == '.';
                    x += dx[k], y += dy[k];
                }
                if (cx == 4 && cd == 1) {
                    ok = true;
                }
            }
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
 
    return 0;
}