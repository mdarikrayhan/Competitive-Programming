#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 998244353;

int dx[]{1,0}, dy[]{0,1};

template<typename T>
std::ostream& operator<<(std::ostream& os, const vector<vector<T>> adj) {
    for(auto x : adj) {
        for(auto y : x) os << y << " ";
        os << "\n";
    }
    return os;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> vis(n+1,vector<int>(m+1,-1));
    map<int,vector<pair<int,int>>> shots;


    shots[42069].push_back({420,69});

    int r; cin >> r;
    for(int i = 0; i < r; i++) {
        int t, d, c; cin >> t >> d >> c;
        shots[t].push_back({d,c});
    }

    vis[0][0] = 0;
    int prevtime = 0;
    for(auto [u, v] : shots) {
        queue<array<int,3>> q;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(vis[i][j] != -1) {
                    q.push({i,j,prevtime});
                    vis[i][j] = -1;
                }
            }
        }
        if(q.empty()) break;
        while(q.size()) {
            array<int,3> a = q.front();
            q.pop();
            if(a[2] > u || vis[a[0]][a[1]] != -1) continue;
            if(a[0] == n && a[1] == m && a[2] < u) {
                cout << a[2] << '\n';
                return;
            }
            vis[a[0]][a[1]] = a[2];
            for(int i = 0; i < 2; i++) {
                int nr = a[0] + dx[i];
                int nc = a[1] + dy[i];
                if(nr >= 0 && nr <= n && nc >= 0 && nc <= m) {
                    q.push({nr,nc,a[2]+1});
                }
            }
        }

        for(auto [d, c] : v) {
            if(d == 1) {
                for(int i = 0; i <= m; i++) {
                    vis[c][i] = -1;
                }
            } else {
                for(int i = 0; i <= n; i++) {
                    vis[i][c] = -1;
                }
            }
        }
        if(vis[n][m] != -1) {
            cout << vis[n][m] << '\n';
            return;
        }
        // cout << "time : " << u << '\n';
        // cout << "adj\n" << vis;
        prevtime = u;
    }
    cout << "-1\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casi; cin >> casi;
    while(casi-->0) solve();

    return 0;
}