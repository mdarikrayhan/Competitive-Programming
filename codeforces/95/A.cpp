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
bool func(string a, string b)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (((char)(a[i] | 32)) != ((char)(b[i] | 32)))
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> forbidden;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        forbidden.push_back(s);
    }
    string w;
    cin >> w;
    int l = w.size();
    vector<int> mark(l + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int t = forbidden[i].size();
        for (int j = 0; j < l; j++)
        {
            string curr = "";
            if (j + t <= l)
            {
                curr = w.substr(j, t);
                if (func(curr, forbidden[i]))
                {
                    for (int k = j; k < j + t; k++)
                    {
                        mark[k] = 1;
                    }
                }
            }
        }
    }
    char c;
    cin >> c;
    for (int i = 0; i < l; i++)
    {
        if (mark[i])
        {
            bool upper = (((int)(w[i])) <= 93);
            w[i] = (char)(w[i] | 32);
            if (w[i] == c)
            {
                if (c == 'a')
                    w[i] = 'b';
                else
                    w[i] = 'a';
            }
            else
            {
                w[i] = c;
            }
            if (upper)
                w[i] = (char)((int)w[i] - 32);
        }
    }
    cout << w;
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
