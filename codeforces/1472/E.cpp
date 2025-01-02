
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
void solve(int _) 
{
    int n;
    cin >> n;
    vector<array<int, 3>> v(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }

    sort(all(v));
    vector<int> mn_id(n+1), res_id(n+1);
    mn_id[1] = 1;
    res_id[1] = v[1][2];
    for (int i = 2; i <= n; i ++ ) {
        mn_id[i] = mn_id[i-1];
        res_id[i] = res_id[i-1];
        if (v[i][1] < v[mn_id[i]][1]) {
            mn_id[i] = i;
            res_id[i] = v[i][2];
        }
    }

    vector<int> ans(n+1);
    for (int i = 1; i <= n; i ++ ) {
        auto [a, b, c] = v[i];
        
        int l = 1, r = i;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (v[mid][0] < a) l = mid;
            else r = mid - 1;
        }

        if (v[r][0] < a && v[mn_id[r]][1] < b) {
            ans[c] = res_id[r];
            continue;
        }

        l = 1, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (v[mid][0] < b) l = mid;
            else r = mid - 1;
        }

        if (v[r][0] < b && v[mn_id[r]][1] < a) {
            ans[c] = res_id[r];
        } else {
            ans[c] = -1;
        }
    }

    for (int i = 1; i <= n; i ++ ) cout << ans[i] << ' ';
    cout << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}