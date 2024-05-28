// LUOGU_RID: 160062949
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#define int long long
using namespace std;
typedef pair<int, int> PII;
const int N = 5e5 + 10;

int n, a[N], l[N], r[N], ans;
priority_queue<PII, vector<PII>, greater<PII> > heap;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i], l[i] = i - 1, r[i] = i + 1;
    r[n] = 0;
    for(int i = 1; i <= n; i ++) heap.push({a[i], i});
    while(heap.size() > 2) {
        auto t = heap.top().second;
        heap.pop();
        if(l[t] && r[t]) ans += min(a[l[t]], a[r[t]]);
        else ans += a[t];
        r[l[t]] = r[t], l[r[t]] = l[t];
    }
    cout << ans << '\n';

    return 0;
}
// 3+5+3