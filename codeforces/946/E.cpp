// LUOGU_RID: 159914707
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    string s;
    cin >> s;
    if (s.size() & 1)
    {
        for (int i=0;i+1<s.size();++i) cout << '9';
        cout << '\n';
        return;
    }
    int msk = 0;
    for (char i : s) msk ^= 1 << i - '0';
    for (int i=s.size()-1;i>=0;--i)
    {
        msk ^= 1 << s[i] - '0';
        for (int j=s[i]-'0'-1;j>=0;--j)
        {
            msk ^= 1 << j;
            int x = __builtin_popcount(msk);
            if (i + x + 1 <= s.size())
            {
                string t;
                for (int j=0;j<i;++j) t.push_back(s[j]);
                t.push_back(j + '0');
                for (int j=0;j<s.size()-i-x-1;++j) t.push_back('9');
                for (int j=9;j>=0;--j) if (msk >> j & 1) t.push_back('0' + j);
                while (t.front() == '0') t.pop_back(), t.erase(t.begin());
                cout << t << '\n';
                return;
            }
            msk ^= 1 << j;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}