#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<stack>
#include<numeric>
#include<algorithm>
#include<cmath>
#include<map>
#include<cassert>
#define ll long long
#define pii pair<int, int>
#define all(a) a.begin(),a.end()
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define frep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
const int INF = 1e9;

void solve() {
    int n, a, b;
    cin >> b >> a >> n;
    if(n == 0) {
        cout << "Yes\n";
        string ans = string(a, '1') + string(b, '0');
        cout << ans << '\n' << ans << '\n';
        return;
    }
    int en = a + b;
    string ans1(en, 0);
    string ans2(en, 0);
    ans1[0] = ans2[0] = '1';
    a--;
    if(a + b - 1 < n || n != 0 && (a == 0 || b == 0)) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    if(n == 0) {
        for(int i = 1; i <= a; i++) ans1[i] = ans2[i] = '1';
        for(int i = a + 1; i < en; i++) ans1[i] = ans2[i] = '0';
    }
    else {
        ans1[1] = '1', ans2[1] = '0';
        int idx = 1 + n;
        // cerr << idx << endl;
        ans1[idx] = '0', ans2[idx] = '1';
        a--, b--;
        for(int i = 2; i < en; i++) {
            if(i == idx) continue;
            if(a > 0) {
                a--;
                ans1[i] = ans2[i] = '1';
            }
            else ans1[i] = ans2[i] = '0';
        }
    }
    cout << ans1 << '\n' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}