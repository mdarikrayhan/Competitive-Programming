#include<bits/stdc++.h>
#define jettdash ios_base::sync_with_stdio(0),cin.tie(0) ,cout.tie(0)
#define ll long long
#define yn(flag) cout<<((flag) ? "YES\n":"NO\n");
#define endl "\n"
#define clr(dp) memset(dp,-1,sizeof dp)
#define all(a) a.begin(),a.end()
#define getmax(v) *max_element(all(v))
#define getmin(v) *min_element(all(v))
#define sum(v) accumulate(all(v),0ll)
int MOD=1e9+7;
using namespace std;

int main() {
    jettdash;
    int n, k;
    cin >> n >> k;
    int sz = 2e5 + 5;
    vector<int> nums(sz);
    vector<vector<int>> cost(sz);
    nums[0] = n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int cnt = 0;
        while (x) {
            nums[x]++;
            cost[x].push_back(cnt++);
            x /= 2;
        }
        cost[0].push_back(cnt);
    }
    for (int i = 0; i < sz; i++) {
        std::sort(cost[i].begin(), cost[i].end());
    }
    int ans = 1e9;
    for (int i = 0; i < sz; i++) {
        if (cost[i].size() >= k) {
            int cnt = 0;
            for (int j = 0; j < k; j++)cnt += cost[i][j];
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
}