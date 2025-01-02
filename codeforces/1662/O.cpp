#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<vector<bool>> cwalls(22,vector<bool>(360));
    vector<vector<bool>> swalls(21,vector<bool>(360));

    for(int i = 0; i < n; i++) {
        char type; cin >> type;
        if(type == 'C') {
            int r, t1, t2; cin >> r >> t1 >> t2;
            for(int j = t1; j % 360 != t2; j++) {
                cwalls[r][j%360] = 1;
            }
        } else {
            int r1, r2, t; cin >> r1 >> r2 >> t;
            for(int j = r1; j < r2; j++) {
                swalls[j][t] = 1;
            }
        }
    }

    vector<vector<bool>> vis(21,vector<bool>(360));

    queue<array<int,2>> q;
    q.push({20,0});

    while(q.size()) {
        array<int,2> a = q.front();
        q.pop();
        if(vis[a[0]][a[1]]) continue;
        vis[a[0]][a[1]] = 1;

        //go outer
        int tor = a[0] + 1;
        int tot = a[1];
        if(tor <= 20 && cwalls[tor][tot] == 0) {
            q.push({tor,tot});
        }

        //go inner
        tor = a[0] - 1;
        tot = a[1];
        if(tor >= 0 && cwalls[a[0]][tot] == 0) {
            q.push({tor,tot});
        }

        //go clockwise
        tor = a[0];
        tot = (a[1] + 1) % 360;
        if(swalls[tor][tot] == 0) {
            q.push({tor,tot});
        }

        //go counterclockwise
        tor = a[0];
        tot = (a[1] + 359) % 360;
        if(swalls[tor][a[1]] == 0) {
            q.push({tor,tot});
        }
    }

    cout << (vis[0][0] ? "YES" : "NO") << '\n';

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casi; cin >> casi;
    while(casi-->0) solve();

    return 0;
}