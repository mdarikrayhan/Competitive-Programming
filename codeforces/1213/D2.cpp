#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int n, k, a[MAXN];
vector<int> cnt[MAXN];
bool ok[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int res = 1e9;
    for(int i = 1; i <= n; ++i){
        cnt[a[i]].push_back(0);
        int dem = 0;
        while(1){
            if(a[i] == 0) break;
            dem++;
            a[i] /= 2;
            cnt[a[i]].push_back(dem);
        }
    }
    for(int i = 1; i <= 2e5; ++i){
        if(cnt[i].size() >= k){
            sort(cnt[i].begin(), cnt[i].end());
            int ans = 0;
            for(int j = 0; j < k; ++j) ans += cnt[i][j];
            res = min(res, ans);
        }
    }
    cout << res;
    return 0;
}
