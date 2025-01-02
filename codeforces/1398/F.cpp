#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
using ll = long long;
using db = double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
template<int N> using AI = array<int, N>;
template<int N> using AL = array<ll, N>;
using VI = vector<int>;
using VL = vector<ll>;
using VD = vector<db>;
using VPII = vector<PII>;
using VPLL = vector<PLL>; 
using VVI = vector<VI>;
using VVL = vector<VL>;
using VVD = vector<VD>;
template<class T>bool ckmin(T &x, const T &y){ return x > y ? x = y, 1: 0; }
template<class T>bool ckmax(T &x, const T &y){ return x < y ? x = y, 1: 0; }
const int IINF = (1 << 30);  // add 2 IINF will exceed int. 
const ll LINF = (1ll << 60);
const db DINF = (1e66);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// Header



void solve() {
    int n;
    string s;
    cin >> n >> s;
    VVI sum(2, VI(n + 2)), pre(2, VI(n + 2));
    for (int i = 1; i <= n; i++) {
        sum[0][i] = sum[0][i - 1];
        sum[1][i] = sum[1][i - 1];
        pre[0][i] = pre[0][i - 1];
        pre[1][i] = pre[1][i - 1];
        if (s[i - 1] != '?') {
            sum[s[i - 1] - '0'][i]++;
            pre[s[i - 1] - '0'][i] = i;
        }
    }
    for (int x = 1; x <= n; x++) {
        int l = 1;
        int ans = 0;
        while (l + x - 1 <= n) {
            // cout << l << " " << x << endl;
            int r = l + x - 1;
            if (sum[0][r] - sum[0][l - 1] == 0 || sum[1][r] - sum[1][l - 1] == 0) {
                ans++;
                l += x;
            } else {
                l = min(pre[0][r], pre[1][r]) + 1;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << fixed << setprecision(10);

    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
    }
    return 0;
}