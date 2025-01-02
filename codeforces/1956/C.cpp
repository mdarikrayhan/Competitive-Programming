#include <bits/stdc++.h>
using namespace std;
#define fs first
#define endl '\n'
#define sc second
#define pb push_back
#define int long long
#define bit(x) (1ll << (x))
#define sz(x) (int)(x).size()
#define al(x) (x).begin(),(x).end()
#define all(x) (x).begin() + 1,(x).end()
using LL = long long;
using VL = vector<LL>;
using VI = vector<int>;
using VS = vector<string>;
using PII = pair<int, int>;
using I64 = unsigned long long;
using VVI = vector<vector<int> >;
template<LL N> using AL = array<LL, N>;
template<int N> using AI = array<int, N>;

void solve() {
    int n; cin >> n;
    int ans = 0;
    for(int i = 1;i <= n;i++) ans += (2 * i - 1) * i;
    cout << ans << ' ' << 2 * n - 1 << endl;
    cout << 1 << ' ' << 1 << ' ';
    for(int i = n;i >= 1;i--) cout << i << " \n"[i == 1];
    for(int i = 2;i <= 2 * n - 1;i++) {
        if(i % 2 == 0) {
            cout << 2 << ' ';
        }
        else {
            cout << 1 << ' ';
        }
        cout << i / 2 + 1 << ' ';
        for(int j = n;j >= 1;j--) cout << j << " \n"[j == 1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}