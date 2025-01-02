/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> A;
    for (int i = 0; i < 4; i++) {
        A.push_back(a);
    }
    for (int i = 0; i < 2; i++) {
        A.push_back(b);
    }
    
    sort(A.begin(), A.end());
    int ans = inf;
    do {
        int cur = 1;
        int len = 0;
        for (int i = 0; i < A.size(); i++) {
            if (len + A[i] <= n) {
                len += A[i];
            } else {
                len = A[i];
                cur++;
            }
        }
        ans = min(ans, cur);
    } while (next_permutation(A.begin(), A.end()));
    
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}