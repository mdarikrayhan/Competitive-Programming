#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define oo ((ll)1e18)
#define endl '\n'
#define all(v) v.begin(),v.end()

#ifdef LOCAL

#include "assets/debug.h"

#else
#define dd(x...)
#define ExeTime
#endif

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int N = 1e6 + 10, M = 21, mod = 1e9 + 7, K = 22;
const double EPS = 1e-12, PI = acos(-1);

void testCase();

void init() {}

int main() {
    init();
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
//    cin >> T;
    for (int i = 0; i < T; i++) {
        testCase();
    }
    ExeTime;
}

int n, m, cnt[M][M], dp[(1 << M)], pre[(1 << M)];

void testCase() {
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 1; i < n; i++) {
        cnt[s[i - 1] - 'a'][s[i] - 'a']++;
        cnt[s[i] - 'a'][s[i - 1] - 'a']++;
    }

    for (int i = 0; i < (1 << m); i++) {
        dp[i] = 1e9;
    }

    dp[0] = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) continue;
            int cur = 0, len = 1;
            for (int j = 0; j < m; j++) {
                if (i == j) continue;
                if (mask & (1 << j)) cur += cnt[j][i], len++;
                else cur -= cnt[j][i];
            }
            dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + cur * len);
        }
    }

    cout << dp[(1 << m) - 1] << endl;
}