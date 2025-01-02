// ⠀⠀⠀⠀⠀⠀⠀⠀⠀ ＿＿
// 　　　　　／＞　　フ
// 　　　　　| 　_　 _ |
// 　 　　　／` ミ＿xノ
// 　　 　 /　　　 　 |
// 　　　 /　 ヽ　　 ﾉ
// 　 　 │　　|　|　|
// 　／￣|　　 |　|　|
// 　| (￣ヽ＿_ヽ_)__)
// 　＼二つ
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
// LOGIC BEFORE CODE
// CHECK FOR YOUR OWN TESTCASES
int grid[1 << 10][1 << 10];
vector<pair<int, pair<int, int>>> acts;
void swap1(int i, int n)
{
    for (int j = 1; j <= n; j++)
    {
        swap(grid[j][i], grid[j][n]);
    }
}
void swap2(int i, int n)
{
    for (int j = 1; j <= n; j++)
    {
        swap(grid[i][j], grid[n][j]);
    }
}
void func(int n)
{
    if (n == 1)
        return;
    for (int i = 1; i < n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (grid[j][i])
                cnt++;
        }
        if (!cnt)
        {
            swap1(i, n);
            acts.push_back({2, {i, n}});
            break;
        }
    }
    int lastrows = 0;
    for (int j = 1; j < n; j++)
    {
        lastrows += grid[n][j];
    }
    if (lastrows == 0)
    {
        for (int i = 1; i < n; i++)
        {
            int cnt = 0;
            for (int j = 1; j < n; j++)
            {
                if (grid[i][j])
                    cnt++;
            }
            if (cnt > 0)
            {
                swap2(i, n);
                acts.push_back({1, {i, n}});
                break;
            }
        }
    }
    func(n - 1);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }
    func(n);
    cout << acts.size() << endl;
    for (auto x : acts)
        cout << x.first << " " << x.second.first << " " << x.second.second << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
// LOGIC BEFORE CODE
// CHECK FOR YOUR OWN TESTCASES
