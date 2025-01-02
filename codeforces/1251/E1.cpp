// LUOGU_RID: 159108518
#include<iostream>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<unordered_map>
#include<vector>
#include<array>
#include<math.h>
#include<map>
#include<stdio.h>
#include<queue>
#include<assert.h>
#include<string>
#include<limits.h>
#include<stack>
#include<set>
#include<list>  
#include<algorithm>
#include <chrono>
#include<random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL>PII;
typedef pair<double, double>PDD;
typedef pair<char, char>PCC;
LL n, m, k;

const LL inf = 1e18;
const LL N = 1e6 + 10;
const LL mod = 1e9 + 7;

const int p = 4e7 + 10;
void solve() {
    cin >> n;
    vector<pair<int, int>>a(n);
    for (int i = 0;i < n;i++) {
        int x, y;cin >> x >> y;
        a[i] = { x,y };
    }
    LL ans = 0;
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<>>q;
    for (int i = n - 1;i >= 0;i--) {
        q.push(a[i].second);
        if (a[i].first > n - q.size()) {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << "\n";
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    cin >> t;
 
    while (t--) {
        solve();
    }

    return 0;
}

