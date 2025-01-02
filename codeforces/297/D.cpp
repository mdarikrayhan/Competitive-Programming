#include<iostream>
#include<cstring>
#include<vector>
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

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g1, g2;
    int tot = 0, cnt = 0;
    for(int i = 0; i < 2 * n - 1; i++){
        string s;
        cin >> s;
        tot += s.size();
        cnt += count(s.begin(), s.end(), 'E');
        if (i % 2 == 0){
            g1.push_back(s);
        }
        else{
            g2.push_back(s);
        }
    }
    if (k == 1){
        if (cnt * 4 >= 3 * tot){
            cout << "YES" << '\n';
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << 1 << ' ';
                }
                cout << '\n';
            }
        }
        else{
            cout << "NO" << '\n';
        }
        return 0;
    }
    bool rev = false;
    if (n > m){
        rev = true;
        vector<string> ng1(m), ng2(m - 1);
        for(int i = 0; i < m; i++){
            ng1[i].resize(n - 1);
            for(int j = 0; j < n - 1; j++){
                ng1[i][j] = g2[j][i];
            }
        }
        for(int i = 0; i < m - 1; i++){
            ng2[i].resize(n);
            for(int j = 0; j < n; j++){
                ng2[i][j] = g1[j][i];
            }
        }
        g1.swap(ng1);
        g2.swap(ng2);
        swap(n, m);
    }
    vector<vector<int> > ans(n, vector<int>(m));
    ans[0][0] = 1;
    for(int i = 1; i < m; i++){
        if (g1[0][i - 1] == 'E'){
            ans[0][i] = ans[0][i - 1];
        }
        else{
            ans[0][i] = 3 - ans[0][i - 1];
        }
    }
    for(int i = 1; i < n; i++){
        ans[i][0] = 1;
        for(int j = 1; j < m; j++){
            if (g1[i][j - 1] == 'E'){
                ans[i][j] = ans[i][j - 1];
            }
            else{
                ans[i][j] = 3 - ans[i][j - 1];
            }
        }
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if (g2[i - 1][j] == 'E'){
                cnt += (ans[i][j] == ans[i - 1][j]);
            }
            else{
                cnt += (ans[i][j] != ans[i - 1][j]);
            }
        }
        if (cnt * 2 < m){
            for(int j = 0; j < m; j++){
                ans[i][j] = 3 - ans[i][j];
            }
        }
    }
    cout << "YES" << '\n';
    if (rev){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << ans[j][i] << ' ';
            }
            cout << '\n';
        }
    }
    else{
        for(auto &v : ans){
            for(auto x : v){
                cout << x << ' ';
            }
            cout << '\n';
        }
    }


}