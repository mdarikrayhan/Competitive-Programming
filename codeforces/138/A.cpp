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
int n, k;
int res[4];
string suffix_func(string &s)
{
    int t = s.size();
    string suff = "";
    int cnt = 0;
    for (int i = t - 1; i >= 0; i--)
    {
        suff.push_back(s[i]);
        if ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u'))
        {
            cnt++;
        }
        if (cnt == k)
            break;
    }
    if (cnt == k)
    {
        return suff;
    }
    else
    {
        return "@";
    }
}
void process()
{
    string ip[4];
    string suffix_see[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> ip[i];
        suffix_see[i] = suffix_func(ip[i]);
        // cout << suffix_see[i] << endl;
    }
    for (int i = 0; i < 4; i++)
    {
        if (suffix_see[i] == "@")
        {
            for (int j = 0; j < 4; j++)
            {
                res[i]--;
                return;
            }
        }
    }
    if ((suffix_see[0] == suffix_see[1]) && (suffix_see[2] == suffix_see[1]) && (suffix_see[2] == suffix_see[3]))
    {
        for (int j = 0; j < 4; j++)
        {
            res[j]++;
        }
    }
    else if ((suffix_see[0] == suffix_see[1]) && (suffix_see[2] == suffix_see[3]))
    {
        res[1]++;
    }
    else if ((suffix_see[0] == suffix_see[2]) && (suffix_see[1] == suffix_see[3]))
    {
        res[2]++;
    }
    else if ((suffix_see[0] == suffix_see[3]) && (suffix_see[1] == suffix_see[2]))
    {
        res[3]++;
    }
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        process();
    }
    if (res[0] == n)
    {
        cout << "aaaa";
    }
    else if (res[1] == n)
    {
        cout << "aabb";
    }
    else if (res[2] == n)
    {
        cout << "abab";
    }
    else if (res[3] == n)
    {
        cout << "abba";
    }
    else
    {
        cout << "NO";
    }
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
