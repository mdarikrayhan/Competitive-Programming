#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[j][i];
    for (int i = 1; i <= m; i++){
        sort(a[i].begin() + 1, a[i].end(), greater<int>{});
        for (int j = 1; j <= n; j++) a[i][j] += a[i][j - 1];
    }
    unordered_map<int, ll> mp[m + 1];
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= n; j++)
            for (int l = max(i - k, 0); l + j <= i; l++)
                mp[i][l + j] = max(mp[i][l + j], mp[i - 1][l] + a[i][j]);
    cout << mp[m][m - k + 1] << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while(t--)
    solve();
}