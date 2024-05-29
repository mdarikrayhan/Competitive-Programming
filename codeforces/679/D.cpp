#include<iostream>
#include<cstring>
#include<vector>
#include<bitset>
#include<iomanip>
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

    const int INF = 1e9;
    int n, m;
    cin >> n >> m;
    vector<vector<int> > d(n, vector<int>(n, INF));
    vector<vector<int> > g(n);
    for(int i = 0; i < n; i++) d[i][i] = 0;

    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        d[a][b] = d[b][a] = 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    double ans = 0;

    vector<double> mxs(n);

    for(int i = 0; i < n; i++){
        double sum = 0;

        vector<vector<int> > pos(n);

        for(int j = 0; j < n; j++){
            pos[d[i][j]].push_back(j);
        }

        for(int j = 0; j < n; j++){
            if (pos[j].size() == 1){
                sum += 1.0 / n;
            }
            else if (pos[j].size() >= 2){
                double mx = 1.0 / pos[j].size();
                vector<double> p(n);
                for(auto x : pos[j]){
                    for(auto t : g[x]){
                        p[t] += 1.0 / g[x].size();
                    }
                }
                vector<int> cand;
                for(int k = 0; k < n; k++){
                    if (p[k] > 0){
                        cand.push_back(k);
                    }
                }
                vector<double> cnt(n);
                for(int k = 0; k < n; k++){
                    for(auto x : cand){
                        cnt[d[k][x]] = max(cnt[d[k][x]], p[x]);
                    }
                    double ss = 0;
                    for(auto x : cand){
                        ss += cnt[d[k][x]] / pos[j].size();
                        cnt[d[k][x]] = 0;
                    }
                    mx = max(mx, ss);
                }
                sum += mx * pos[j].size() / n;
            }
        }
        ans = max(ans, sum);
    }

    cout << fixed << setprecision(20) << ans << '\n';

}