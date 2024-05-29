#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1'000'000;
const int T = 6;
const int M = 20;
const int B = 10;

ll k, f[T + 10];
ll dp[N + 10], ans[N + 10][T + 5];
vector<pair<ll, ll>> vec;

void readInput() {
    cin >> k;
    for (int i = 0; i < T; i++)
        cin >> f[i];
}

void add(ll cnt, ll w, ll v) {
    for (int j = 0; (1 << j) <= cnt; j++) {
        vec.push_back({(1ll << j) * w, (1ll << j) * v});
        cnt -= (1 << j);
    }
    if (cnt)
        vec.push_back({cnt * w, cnt * v});
}

void calcVec() {
    ll pw = 1;
    for (int i = 0; i < T; i++) {
        add(3 * (k - 1), 3ll * pw, f[i]);
        pw *= 10;
    }
}

void calcDP() {
    fill(dp, dp + N, -1);
    dp[0] = 0;
    for (auto [w, v]: vec)
        for (int i = N - 1; i >= w; i--)
            if (dp[i - w] >= 0)
                dp[i] = max(dp[i], dp[i - w] + v);
}

void calcAns() {
    for (int i = 0; i < N; i++) {
        ans[i][0] = -1;
        for (int x = 0; x < B; x++)
            if (i >= x && dp[i - x] >= 0)
                ans[i][0] = max(ans[i][0], dp[i - x] + (x % 3? 0: f[0] * (x / 3)));
    }
    ll pw = 1;
    for (int j = 1; j < T; j++) {
        pw *= 10;
        for (int i = 0; i < N; i++) {
            ans[i][j] = -1;
            for (int x = 0; x < B; x++) {
                ll val = pw * x;
                if (i >= val && ans[i - val][j - 1] >= 0)
                    ans[i][j] = max(ans[i][j], ans[i - val][j - 1] + (x % 3? 0: f[j] * (x / 3)));
            }
        }
    }
}

void query() {
    ll n;
    cin >> n;
    cout << ans[n][T - 1] << '\n';
}

void answerQuery() {
    int q;
    cin >> q;
    while (q--)
        query();
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    readInput();
    calcVec();
    calcDP();
    calcAns();
    answerQuery();
    return 0;
}