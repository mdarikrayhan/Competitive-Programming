#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    bool a[8][8]{};
    for (int i = 0; i < n; ++i) {
        char r, f;
        cin >> r >> f;
        a[r - 'a'][f - '1'] = true;
    }
    int dx[8]{-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8]{1, -1, 2, -2, 2, -2, 1, -1};
    auto check = [](int x, int y) {
        return 0 <= x && x < 8 && 0 <= y && y < 8;
    };
    vector<string> ans;
    for (int i = 0; i < n; ++i) {
        int r = i % 8, f = i / 8;
        if (a[r][f]) continue;
        pair<int, int> p[8][8]{};
        p[r][f] = {-1, -1};
        bool vis[8][8]{};
        vis[r][f] = true;
        queue<pair<int, int>> q;
        q.emplace(r, f);
        vector<string> cans;
        while (!q.empty()) {
            auto[x, y] = q.front();
            q.pop();
            int j = x + 8 * y;
            if (a[x][y] && j > i) {
                vector<pair<int, int>> path;
                int cx = x, cy = y;
                while (~cx && ~cy) {
                    path.emplace_back(cx, cy);
                    auto l = p[cx][cy];
                    cx = l.first, cy = l.second;
                }
                std::reverse(path.begin(), path.end());
                for (int k = 0; k < path.size()-1; ++k) {
                    cx = path[k].first, cy = path[k].second;
                    int nx = path[k + 1].first, ny = path[k + 1].second;
                    string cur, nxt;
                    cur.push_back('a' + cx);
                    cur.push_back('1' + cy);
                    nxt.push_back('a' + nx);
                    nxt.push_back('1' + ny);
                    if (a[nx][ny] && (nx != x || ny != y)) cans.push_back(nxt+"-"+cur);
                }
                for (int k = path.size()-2; ~k; --k) {
                    cx = path[k].first, cy = path[k].second;
                    int nx = path[k + 1].first, ny = path[k + 1].second;
                    string cur, nxt;
                    cur.push_back('a' + cx);
                    cur.push_back('1' + cy);
                    nxt.push_back('a' + nx);
                    nxt.push_back('1' + ny);
                    if (!(a[nx][ny] && (nx != x || ny != y))) cans.push_back(nxt+"-"+cur);
                }
                a[x][y] = false;
                a[r][f] = true;
                break;
            }
            for (int k = 0; k < 8; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (!check(nx, ny) || vis[nx][ny]) continue;
                vis[nx][ny] = true;
                q.emplace(nx, ny);
                p[nx][ny] = {x, y};
            }
        }
        for (auto &s : cans)
            ans.push_back(s);
    }
    cout << ans.size() << '\n';
    for (auto &s : ans)
        cout << s << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
}
 		 				 		 	 		 			  	 	  			