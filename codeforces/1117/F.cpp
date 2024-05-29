#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int md = 1e9 + 7;
const int N = (1 << 17) + 10;
int vis[N], id;
bool bad[N];
bool adj[20][20];
int n, p;

void rec(int msk, int a, int b) {
    if (vis[msk] == id)
        return;
    vis[msk] = id;
    if (msk)
        bad[msk] = 1;
    for (int i = 0; i < p; i++) {
        if (i == a or i == b or !(msk & (1 << i)))
            continue;
        rec(msk ^ (1 << i), a, b);
    }
}

void solve() {
    cin >> n >> p;
    string s;
    cin >> s;
    vector<int> frq(p);
    for (auto i: s)
        frq[i - 'a']++;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            cin >> adj[i][j];
        }
    }
    for (int i = 0; i < p; i++) {
        for (int j = i; j < p; j++) {
            if (adj[i][j])
                continue;
            id++;
            int msk = 0;
            for (auto ch: s) {
                int c = ch - 'a';
                if (c == i or c == j) {
                    if ((c == i and (msk & (1 << j))) or
                        (c == j and (msk & (1 << i)))) {
                        rec((((1 << p) - 1) ^ msk) | (1 << j) | (1 << i), i, j);
                    }
                    msk = 0;
                }
                msk |= 1 << c;
            }
        }
    }
//    for (int i = 0; i < (1 << p); i++) {
//        if (bad[i])
//            continue;
//        for (auto j: s)
//            if (!(i & (1 << (j - 'a'))))
//                cerr << j;
//        cerr << '\n';
//    }
    vector<bool> dp(1 << p);
    dp[(1 << p) - 1] = true;
    int ans = 1e9;
    for (int i = (1 << p) - 1; i >= 0; i--) {
        if (!dp[i])
            continue;
        int sum = 0;
        for (int j = 0; j < p; j++) {
            if (i & (1 << j)) {
                if (!bad[i ^ (1 << j)])
                    dp[i ^ (1 << j)] = 1;
                sum += frq[j];
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;
//    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
    }
}

   			     	 	  	  			   	 	  	