#include <stdio.h>
#include <set>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <math.h> 
#include <cmath>
#include <queue>
#include <stdlib.h>
#include <iostream>
#include <numeric>
using i64 = long long;
#define IOS_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define endl "\n"
#define PII pair<int, int>
using namespace std;
constexpr i64 inf = 1E18;
const int mod = 998244353;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<string> s;
    for (int i = 0;i < n;++i){
        string ss;
        cin >> ss;
        s.push_back(ss);
    }
    int ans = 1e9;
    for (int i = 0;i < n;++i){
        for (int j = i + 1;j < n;++j){
            int t = 0;
            for (int m = 0;m < k;++m){
                t += abs(s[j][m] - s[i][m]);
            }
            ans = min(ans, t);
        }
    }
    cout << ans << "\n";
}
signed main(){
    IOS_IO
    int t;
    t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}