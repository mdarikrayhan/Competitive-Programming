#include <bits/stdc++.h>
using namespace std;
const int a[] = {0b00001111, 0b00110011, 0b01010101};
const char ch[] = {'x', 'y', 'z'};
const char op[] = {'|', '&', '!'}; // 低 ~ 高，单值 和 括号 也算 2 级，高级 外面可以套 低级
const int R = 7;
const int n = 1 << 8;
string Min(string &a, string &b) { return a.size() ^ b.size() ? (a.size() < b.size() ? a : b) : (a < b ? a : b); }
void chkmn(string &a, string b)
{
    if (a.empty())
        a = b;
    else
        a = Min(a, b);
}
int StB(string &s)
{
    int ret = 0;
    for (char c : s)
        ret = ret << 1 | c ^ '0';
    return ret;
}
int inv(int x) { return 0b11111111 ^ x; }
string f[R + 1][n][3];
string ans[n];
int t;
void solve()
{
    string s;
    cin >> s;
    cout << ans[StB(s)] << '\n';
}
int main()
{
    for (int i = 0; i < 3; i++)
        f[0][a[i]][2] = ch[i];
    for (int r = 0; r < R; r++)
    {
        // 单值修改
        for (int i = 0; i < n; i++)
        {
            // 继承原始
            if (!f[r][i][0].empty())
                chkmn(f[r + 1][i][0], f[r][i][0]);
            if (!f[r][i][1].empty())
                chkmn(f[r + 1][i][1], f[r][i][1]);
            if (!f[r][i][2].empty())
                chkmn(f[r + 1][i][2], f[r][i][2]);
            // 取反
            if (!f[r][i][0].empty())
                chkmn(f[r + 1][inv(i)][2], "!(" + f[r][i][0] + ")");
            if (!f[r][i][1].empty())
                chkmn(f[r + 1][inv(i)][2], "!(" + f[r][i][1] + ")");
            if (!f[r][i][2].empty())
                chkmn(f[r + 1][inv(i)][2], "!" + f[r][i][2]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 0 | 0
                if (!f[r][i][0].empty() && !f[r][j][0].empty())
                    chkmn(f[r + 1][i | j][0], f[r][i][0] + "|" + f[r][j][0]);
                // 0 | 1
                if (!f[r][i][0].empty() && !f[r][j][1].empty())
                    chkmn(f[r + 1][i | j][0], f[r][i][0] + "|" + f[r][j][1]);
                // 0 | 2
                if (!f[r][i][0].empty() && !f[r][j][2].empty())
                    chkmn(f[r + 1][i | j][0], f[r][i][0] + "|" + f[r][j][2]);
                // 0 & 0
                if (!f[r][i][0].empty() && !f[r][j][0].empty())
                    chkmn(f[r + 1][i & j][1], "(" + f[r][i][0] + ")&(" + f[r][j][0] + ")");
                // 0 & 1
                if (!f[r][i][0].empty() && !f[r][j][1].empty())
                    chkmn(f[r + 1][i & j][1], "(" + f[r][i][0] + ")&" + f[r][j][1]);
                // 0 & 2
                if (!f[r][i][0].empty() && !f[r][j][2].empty())
                    chkmn(f[r + 1][i & j][1], "(" + f[r][i][0] + ")&" + f[r][j][2]);

                // 1 | 0
                if (!f[r][i][1].empty() && !f[r][j][0].empty())
                    chkmn(f[r + 1][i | j][0], f[r][i][1] + "|" + f[r][j][0]);
                // 1 | 1
                if (!f[r][i][1].empty() && !f[r][j][1].empty())
                    chkmn(f[r + 1][i | j][0], f[r][i][1] + "|" + f[r][j][1]);
                // 1 | 2
                if (!f[r][i][1].empty() && !f[r][j][2].empty())
                    chkmn(f[r + 1][i | j][0], f[r][i][1] + "|" + f[r][j][2]);
                // 1 & 0
                if (!f[r][i][1].empty() && !f[r][j][0].empty())
                    chkmn(f[r + 1][i & j][1], f[r][i][1] + "&(" + f[r][j][0] + ")");
                // 1 & 1
                if (!f[r][i][1].empty() && !f[r][j][1].empty())
                    chkmn(f[r + 1][i & j][1], f[r][i][1] + "&" + f[r][j][1]);
                // 1 & 2
                if (!f[r][i][1].empty() && !f[r][j][2].empty())
                    chkmn(f[r + 1][i & j][1], f[r][i][1] + "&" + f[r][j][2]);

                // 2 | 0
                if (!f[r][i][2].empty() && !f[r][j][0].empty())
                    chkmn(f[r + 1][i | j][0], f[r][i][2] + "|" + f[r][j][0]);
                // 2 | 1
                if (!f[r][i][2].empty() && !f[r][j][1].empty())
                    chkmn(f[r + 1][i | j][0], f[r][i][2] + "|" + f[r][j][1]);
                // 2 | 2
                if (!f[r][i][2].empty() && !f[r][j][2].empty())
                    chkmn(f[r + 1][i | j][0], f[r][i][2] + "|" + f[r][j][2]);
                // 2 & 0
                if (!f[r][i][2].empty() && !f[r][j][0].empty())
                    chkmn(f[r + 1][i & j][1], f[r][i][2] + "&(" + f[r][j][0] + ")");
                // 2 & 1
                if (!f[r][i][2].empty() && !f[r][j][1].empty())
                    chkmn(f[r + 1][i & j][1], f[r][i][2] + "&" + f[r][j][1]);
                // 2 & 2
                if (!f[r][i][2].empty() && !f[r][j][2].empty())
                    chkmn(f[r + 1][i & j][1], f[r][i][2] + "&" + f[r][j][2]);
            }
        }
        // cerr << r << endl;
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < 3; j++)
        //         cerr << f[r][i][j] << " \n"[j == 2];
        // cerr << endl;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            chkmn(ans[i], f[R][i][j]);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}