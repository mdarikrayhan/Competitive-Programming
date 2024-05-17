#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 2e18;
const int mod = 998244353;
const int N = 2e5;


signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        map <int, int> m;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            m[a[i]]++;
        }
        int max_cnt = 0, num = 0;
        for (auto & [x, y]: m){
            if (y > max_cnt){
                max_cnt = y;
                num = x;
            }
        }
        int last_ind = 0;
        for (int i = 0; i < n; i++){
            if (a[i] == num){
                last_ind = i;
            }
        }
        vector <vector <int>> ans;
        for (int i = last_ind + 1; i < n; i++){
            int c = 1;
            if (a[i] > num){
                c = 2;
            }
            ans.push_back({c, i + 1, i});
        }
        for (int i = last_ind - 1; i >= 0; i--){
            if (a[i] == num){
                continue;
            }
            int c = 1;
            if (a[i] > num){
                c = 2;
            }
            ans.push_back({c, i + 1, i + 2});
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
        }
    }
    return 0;
}