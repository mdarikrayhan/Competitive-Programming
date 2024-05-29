#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<array>
using namespace std;
using LL = long long;
int d[2][105][105];
array<int, 3> pre[2][105][105];

int solve(int n, int m){
    memset(d, -1, sizeof d);
    queue<array<int, 3> > q;
    d[1][n][n] = 0;
    q.push({1, n, n});

    auto check = [&](int x, int y){
        return x == 0 || x >= y;
    };

    while(!q.empty()){
        auto [type, x, y] = q.front();
        q.pop();
        for(int a = 0; a <= m && a <= x; a++){
            for(int b = 0; a + b <= m && b <= y; b++){
                if (a + b == 0 || !check(a, b)) continue;
                int c1 = x - a, c2 = y - b;
                if (c1 < 0 || c2 < 0 || !check(c1, c2) || !check(n - c1, n - c2)) continue;
                int t1 = n - c1, t2 = n - c2;
                if (d[type ^ 1][t1][t2] == -1){
                    d[type ^ 1][t1][t2] = d[type][x][y] + 1;
                    q.push({type ^ 1, t1, t2});
                    pre[type ^ 1][t1][t2] = {type, x, y};
                }
            }
        }
    }
    // array<int, 3> cur{0, n, n};
    // while(1){
    //     auto [type, x, y] = cur;
    //     if (type == 0) cout << type << ' ' << x << ' ' << y << '\n';
    //     else cout << type << ' ' << 3 - x << ' ' << 3 - y << '\n';
    //     if (d[type][x][y] == 0) break;
    //     cur = pre[type][x][y];
    // }
    return d[0][n][n];
}

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    if (m <= 3){
        if (n <= 10) cout << solve(n, m) << '\n';
        else cout << -1 << '\n';
        return 0;
    }
    if (n * 2 <= m) cout << 1 << '\n';
    else if (m % 2 == 0){
        int T = m / 2 - 1;
        cout << (n - m / 2 + T - 1) / T * 2 + 1 << '\n';
    }
    else{
        int len1 = m / 2, len2 = len1 - 1;
        vector<int> ans{0};
        for(int i = 0; i < len1; i++) ans.push_back(1);
        for(int i = 0; i < len1; i++) ans.push_back(3);
        for(int i = 0; i < len2; i++) ans.push_back(5);
        for(int i = 0; i < len1; i++) ans.push_back(7);
        ans.resize(n + 1);
        for(int i = 3 * len1 + len2 + 1; i <= n; i++){
            ans[i] = ans[i - len2] + 2;
        }
        cout << ans[n] << '\n';
        // for(int i = 1; i <= n; i++){
        //     cout << ans[i] << " \n"[i == n];
        // }
    }

}