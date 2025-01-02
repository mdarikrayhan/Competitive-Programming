#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

bool bit (const int mask, const int i)
{
    return ((mask >> i) & 1);
}

void solve_test(istream &cin, ostream &cout)
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &row : grid)
        cin >> row;

    vector<vector<int>> pref(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        pref[i][j] = pref[i - 1][j] + pref[i][j - 1] -
                     pref[i - 1][j - 1] + (grid[i - 1][j - 1] == '*');

    auto square = [&] (const int x, const int y, const int len)
    {
        return pref[x + len][y + len] - pref[x + len][y]
                - pref[x][y + len] + pref[x][y];
    };

    int ans = 0;
    for (int mask = 0; mask < (1 << 4); mask++)
    {
        vector<vector<bool>> dp(n - 1, vector<bool>(m - 1));

        for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
        {
            bool ok = true;
            for (int di = 0; di < 2; di++)
            for (int dj = 0; dj < 2; dj++)
            if (grid[i + di][j + dj] != (bit(mask, di * 2 + dj) ? '*' : '.'))
                ok = false;

            dp[i][j] = ok;
        }

        int len = 2;
        while (len * 2 <= min(n, m))
        {
            vector<vector<bool>> next(n - 2 * len + 1, vector<bool>(m - 2 * len + 1));
            for (int i = 0; i <= n - 2 * len; i++)
            for (int j = 0; j <= m - 2 * len; j++)
            {
                bool ok = true;
                for (int di = 0; di < 2; di++)
                for (int dj = 0; dj < 2; dj++)
                {
                    if (bit(mask, di * 2 + dj))
                        ok = (ok && square(i + di * len, j + dj * len, len) == len * len);
                    else
                        ok = (ok && dp[i + di * len][j + dj * len]);
                }

                if (ok)
                    ans++;
                next[i][j] = ok;
            }

            dp = next;
            len *= 2;
        }
    }

    cout << ans << endl;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
    solve_test(cin, cout);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed;

#ifdef LOCAL
    auto st = clock();

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    do
    {
        solve(fin, fout);

        fout << "===" << endl;

        string str;
        while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
    }
    while (fin);

    cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
    solve();
#endif

    return 0;
}
