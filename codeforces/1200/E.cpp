/*
 * author: kira..04
 * created: 2024-05-24 15:04:38
 */
//^ Happiness can be found, even in the darkest of times, if one only remembers to turn on the light
//! i can't forget you , i can't , i can't even one second
#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(M) M.begin(), M.end()
#define _FAST                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
int kmp(const string &s)
{
    vector<ll> pi;
    pi.push_back(0);
    for (ll i = 1; i < s.size(); i++)
    {
        ll j = pi[i - 1];
        while (j && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi.push_back(j);
    }
    return pi.back();
}
string s[(int)1e6 + 1];
char ans[(int)1e6 + 1];
void go()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int pos = 0;
    for (int i = 0; i < s[0].length(); i++)
        ans[pos++] = s[0][i];
    for (int i = 1; i < n; i++)
    {
        int len = s[i].length();
        string x = s[i] + '#';
        for (int j = max(0, pos - len); j < pos; j++)
            x += ans[j];
        int len1 = kmp(x);
        for (int j = len1; j < len; j++)
            ans[pos++] = s[i][j];
    }
    cout << ans << endl;
}
int main()
{
    _FAST
    int _tt = 1;
    // cin >> _tt;
    while (_tt--)
    {
        go();
    }
}