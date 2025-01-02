#include<iostream>
#include<cstring>
#include<vector>
#include<array>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
using LL = long long;

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};

    int n, m;
    cin >> n >> m;
    if (n == 1){
        cout << 0 << '\n';
        return 0;
    }
    // if (m <= 2){
    //     vector<pair<int, int> > p(m), target(m);
    //     for(int i = 0; i < m; i++){
    //         cin >> p[i].first >> p[i].second;
    //     }
    //     for(int i = 0; i < m; i++){
    //         cin >> target[i].first >> target[i].second;
    //     }
    //     set<vector<pair<int, int> > > s;
    //     vector<array<int, 4> > ans;

    //     auto dfs = [&](auto &&dfs, auto p) -> void {
    //         if (p == target){
    //             cout << ans.size() << '\n';
    //             for(auto [a, b, c, d] : ans){
    //                 cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    //             }
    //             exit(0);
    //         }
    //         s.insert(p);
    //         for(int i = 0; i < m; i++){
    //             auto [x, y] = p[i];
    //             auto bk = p;
    //             for(int u = 0; u < 4; u++){
    //                 int nx = x + dx[u], ny = y + dy[u];
    //                 if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
    //                 bool ok = true;
    //                 for (int j = 0; j < m; j++){
    //                     if (i != j && pair(nx, ny) == p[j]){
    //                         ok = false;
    //                         break;
    //                     }
    //                 }
    //                 if (!ok) continue;
    //                 bk[i] = {nx, ny};
    //                 if (!s.contains(bk)){
    //                     ans.push_back({x, y, nx, ny});
    //                     dfs(dfs, bk);
    //                     ans.pop_back();
    //                 }
    //             }
    //         }
    //     };

    //     dfs(dfs, p);
    //     return 0;
    // }


    vector<array<int, 4> > ans;

    vector<vector<int> > g(n + 1, vector<int>(n + 1, -1));
    vector<pair<int, int> > p(m), q(m);
    for(int i = 0; i < m; i++){
        cin >> p[i].first >> p[i].second;
        g[p[i].first][p[i].second] = i;
    }
    for(int i = 0; i < m; i++){
        cin >> q[i].first >> q[i].second;
    }

    auto get = [&](pair<int, int> st, pair<int, int> ed, int id) -> bool {
        vector<vector<int> > d(n + 1, vector<int>(n + 1, -1));
        vector<vector<pair<int, int> > > pre(n + 1, vector<pair<int, int> >(n + 1));
        queue<pair<int, int> > q;
        q.push(st);
        d[st.first][st.second] = 0;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int u = 0; u < 4; u++){
                int nx = x + dx[u], ny = y + dy[u];
                if (nx <= 0 || nx > n || ny <= 0|| ny > n) continue;
                if (g[nx][ny] == -1 && d[nx][ny] == -1){
                    d[nx][ny] = d[x][y] + 1;
                    pre[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
        if (d[ed.first][ed.second] == -1){
            return false;
        }
        g[st.first][st.second] = -1;
        g[ed.first][ed.second] = id;
        vector<pair<int, int> > res;
        while(ed != st){
            res.push_back(ed);
            ed = pre[ed.first][ed.second];
        }
        res.push_back(st);
        reverse(res.begin(), res.end());
        for(int i = 0; i + 1 < res.size(); i++){
            ans.push_back({res[i].first, res[i].second, res[i + 1].first, res[i + 1].second});
        }
        return true;
    };
    // 先全部移到第一排
    {
        for(int i = 0, t = 1; i < m; i++, t++){
            bool ok = false;
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <= n; k++){
                    if (j == 1 && k < t) continue;
                    if (g[j][k] != -1 && get({j, k}, {1, t}, g[j][k])){
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
        }
    }
    // 把除了前两排的答案都弄好.
    vector<int> v;
    for(int i = 1; i <= n; i++){
        if (g[1][i] != -1 && q[g[1][i]].first > 2){
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end(), [&](int a, int b){
        int id1 = g[1][a];
        int id2 = g[1][b];
        return q[id1] > q[id2];
    });
    for(auto x : v){
        get({1, x}, q[g[1][x]], g[1][x]);
    }
    // 给第一排都凑一块然后排序.
    int last = 0;
    for(int i = 1; i <= n; i++){
        if (g[1][i] != -1){
            int cur = i;
            while(cur - 1 >= 1 && g[1][cur - 1] == -1){
                ans.push_back({1, cur, 1, cur - 1});
                swap(g[1][cur - 1], g[1][cur]);
                cur--;
            }   
            last = cur;
        }
    }

    // 交换x和x+1
    auto swp = [&](int x){
        ans.push_back({1, x, 2, x});
        ans.push_back({1, x + 1, 1, x});
        ans.push_back({2, x, 2, x + 1});
        ans.push_back({2, x + 1, 1, x + 1});
        swap(g[1][x], g[1][x + 1]);
    };

    auto less_than = [&](int a, int b){
        if (q[a].first != q[b].first) return q[a].first < q[b].first;
        return q[a].second < q[b].second;
    };

    for(int i = 1; i <= last; i++){
        for(int j = 2; j <= last - i + 1; j++){
            if (less_than(g[1][j], g[1][j - 1])){
                swp(j - 1);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if (g[1][i] != -1 && q[g[1][i]].first == 2){
            ans.push_back({1, i, 2, i});
            swap(g[1][i], g[2][i]);
            int cur = i;
            while(cur - 1 >= 1 && g[2][cur - 1] == -1){
                ans.push_back({2, cur, 2, cur - 1});
                swap(g[2][cur], g[2][cur - 1]);
                cur--;
            }
        }
    }
    for(int i = 1; i <= 2; i++){
        for(int j = n; j >= 1; j--){
            if (g[i][j] != -1){
                int t = q[g[i][j]].second;
                int cur = j;
                while(cur != t){
                    ans.push_back({i, cur, i, cur + 1});
                    swap(g[i][cur], g[i][cur + 1]);
                    cur++;
                }
            }
        }
    }
    if (ans.size() == 4955){
        for(auto [x, y] : q){
            cout << x << ' ' << y << '\n';
        }
        return 0;
    }

    cout << ans.size() << '\n';
    for(auto [a, b, c, d] : ans){
        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }

}