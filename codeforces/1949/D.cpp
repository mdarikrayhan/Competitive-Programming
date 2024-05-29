#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
using LL = long long;
int dp[30][30];
pair<int, int> pre[30][30];
int f[20][1 << 20];

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
    vector<string> s(n);
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < n; j++){
            cnt0 += (s[i][j] == 'F');
            cnt1 += (s[i][j] == 'S');
        }
    }

    auto get = [&](vector<string> &s){
        const int INF = 1e9;
        vector<vector<int> > g[2];
        g[0].resize(n), g[1].resize(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                g[s[i][j] == 'F'][i].push_back(j);
                g[s[i][j] == 'F'][j].push_back(i);
            }
        }

        auto dis = [&](int type){
            int ans = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < 1 << n; j++){
                    f[i][j] = -INF;
                }
            }
            for(int i = 0; i < n; i++) f[i][1 << i] = 0;
            for(int i = 0; i < 1 << n; i++){
                for(int j = 0; j < n; j++){
                    if (!(i >> j & 1)) continue;
                    for(auto k : g[type][j]){
                        if (!(i >> k & 1)){
                            f[k][i | (1 << k)] = max(f[k][i | (1 << k)], f[j][i] + 1);
                        }
                    }
                    ans = max(ans, f[j][i]);
                }
            }
            return ans;
        };
        int t = max(dis(0), dis(1));
        return t <= (3 * n + 3) / 4;
    };

    auto solve = [&](char c){
        vector<vector<pair<int, int> > > g(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if (s[i][j] != '?'){
                    g[i].push_back({j, s[i][j] == c});
                    g[j].push_back({i, s[i][j] == c});
                }
            }
        }
        vector<int> type(n);

        int target = (n + 2) / 3;
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;

        vector<vector<int> > pt;

        int v[24]{};
        for(int i = 0; i < n; i++){
            if (!v[i]){
                vector<int> p;

                auto dfs = [&](auto &&dfs, int u) -> void {
                    v[u] = 1;
                    p.push_back(u);
                    for(auto [j, w] : g[u]){
                        if (!v[j]){
                            dfs(dfs, j);
                        }
                    }
                };
                dfs(dfs, i);

                pt.push_back(p);

                const int s = p.size();
                for(int j = 0; j < 1 << s; j++){
                    for(int k = 0; k < s; k++){
                        type[p[k]] = j >> k & 1;
                    }
                    int cnt = 0;
                    for(auto x : p){
                        for(auto [j, t] : g[x]){
                            int cur = (type[x] == 0 || type[j] == 0);
                            cnt += (cur != t);
                        }
                    }
                    int cnt0 = s - __builtin_popcount(j);
                    for(int k = 0; k + cnt0 <= target; k++){
                        if (dp[pt.size()][k + cnt0] > dp[pt.size() - 1][k] + cnt){
                            dp[pt.size()][k + cnt0] = dp[pt.size() - 1][k] + cnt;
                            pre[pt.size()][k + cnt0] = {k, j};
                        }
                    }
                }
            }
        }
        int mn = dp[pt.size()][target];
        for(int i = pt.size() - 1; i >= 0; i--){
            auto [k, state] = pre[i + 1][target];
            for(int j = 0; j < pt[i].size(); j++){
                type[pt[i][j]] = state >> j & 1;
            }
            target = k;
        }

        auto bk = s;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (bk[i][j] == '?'){
                    if (type[i] == 0 || type[j] == 0) bk[i][j] = c;
                    else bk[i][j] = (c == 'F' ? 'S' : 'F');
                }
            }
        }
        if (n > 20 || get(bk)){
            for(auto &str : bk){
                cout << str << '\n';
            }
            exit(0);
        }
    };
    if (cnt0 > cnt1){
        solve('S');
    }
    else{
        solve('F');
    }


}