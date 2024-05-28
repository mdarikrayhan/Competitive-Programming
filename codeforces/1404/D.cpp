#include<bits/stdc++.h>
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

    int n;
    cin >> n;
    if (n % 2 == 0){
        cout << "First" << endl;
        for(int i = 1; i <= n; i++){
            cout << i << ' ';
        }
        for(int i = 1; i <= n; i++){
            cout << i << ' ';
        }
        cout << endl;
        int t;
        cin >> t;
        return 0;
    }
    cout << "Second" << endl;
    vector<vector<int> > pos(n + 1);
    for(int i = 1; i <= 2 * n; i++){
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    vector<vector<int> > g(2 * n + 1);
    for(int i = 1; i <= n; i++){
        g[i].push_back(i + n);
        g[i + n].push_back(i);
        g[pos[i][0]].push_back(pos[i][1]);
        g[pos[i][1]].push_back(pos[i][0]);
    }

    vector<int> c(2 * n + 1, -1);

    auto dfs = [&](auto &&dfs, int u, int color) -> void {
        c[u] = color;
        for(auto j : g[u]){
            if (c[j] != -1) continue;
            dfs(dfs, j, color ^ 1);      
        }
    };

    for(int i = 1; i <= 2 * n; i++){
        if (c[i] == -1){
            dfs(dfs, i, 0);
        }
    }

    LL sum[2]{};
    vector<int> ans[2];
    for(int i = 1; i <= 2 * n; i++){
        ans[c[i]].push_back(i);
        sum[c[i]] += i;
    }
    for(int i = 0; i < 2; i++){
        if (sum[i] % (2 * n) == 0){
            for(auto x : ans[i]){
                cout << x << ' ';
            }
            cout << endl;
            int t; 
            cin >> t;
            return 0;
        }
    }

}