#include <bits/stdc++.h>

#define int __int128
#define ld long double
#define F first
#define S second
using namespace std;
const int inf = LLONG_MAX;
const int N = 22;
vector<int> fac(N);

vector<int> getkth(int n, int k) {
    vector<int> glav(n + 1);
    vector<vector<int>> mno(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        glav[i] = i;
        mno[i].push_back(i);
    }
    vector<bool> used(n + 1);
    vector<int> ans(n);
    ans[0] = n;
    for (int i = 2; i <= n - 1; ++i) {
        int o = (k - 1) / fac[n - 2 - i + 1];
        k -= fac[n - 2 - i + 1] * o;
        vector<int> poss;
        for (int j = 1; j < n; ++j) {
            if (!used[j] && glav[j] != glav[i]) {
                poss.push_back(j);
            }
        }
        ans[i - 1] = poss[o];
        for (int j : mno[poss[o]]) {
            glav[j] = glav[i];
            mno[glav[i]].push_back(j);
        }
        mno[poss[o]].clear();
        used[poss[o]] = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (!used[i]) {
            ans.back() = i;
        }
    }
    return ans;
}

signed main() {
    //freopen("connect.in", "r", stdin);
    //freopen("connect.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i;
    }
    vector<int> dp(51, inf);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < 23; ++i) {
        dp[i] = 0;
        dp[i] += dp[i - 1];
        dp[i] += fac[i - 2];
        for (int j = 2; j < i; ++j) {
            dp[i] += dp[i - j] * fac[j - 2];
        }
    }
    long long _;
    cin >> _;
    while (_--) {
        long long n, k;
        cin >> n >> k;
        if (k > dp[n]) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans;
        while (ans.size() != n) {
            int id = ans.size();
            for (int i = 1; i <= n - id; ++i) {
                if (dp[n - id - i] * fac[max((int) 0, i - 2)] < k) {
                    k -= dp[n - id - i] * fac[max((int) 0, i - 2)];
                } else {
                    int o = (k - 1) / dp[n - id - i];
                    k -= o * dp[n - id - i];
                    vector<int> p = getkth(i, o + 1);
                    for (int j = 0; j < i; ++j) {
                        ans.push_back(p[j] + id);
                    }
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << (long long) ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
//3) чокнутый профессор
//4) минимизируй, прибавляй!
//5) посулшать лекцию по линейной алгебре.
//7) не курить!


//1
//-1
//1 2
//2 1
//-1
//1 2 3
//1 3 2
//2 1 3
//3 1 2
//-1
//1 2 3 4
//1 2 4 3
//1 3 2 4
//1 4 2 3
//2 1 3 4
//2 1 4 3
//3 1 2 4
//4 1 2 3
//4 3 1 2
//-1
//1 2 3 4 5
//1 2 3 5 4
//1 2 4 3 5
//1 2 5 3 4
//1 3 2 4 5
//1 3 2 5 4
//1 4 2 3 5
//1 5 2 3 4
//1 5 4 2 3
//2 1 3 4 5
//2 1 3 5 4
//2 1 4 3 5
//2 1 5 3 4
//3 1 2 4 5
//3 1 2 5 4
//4 1 2 3 5
//4 3 1 2 5
//5 1 2 3 4
//5 1 4 2 3
//5 3 1 2 4
//5 3 2 1 4
//5 4 1 3 2
//5 4 2 1 3