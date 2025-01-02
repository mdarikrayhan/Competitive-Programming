#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl "\n"
#define mod 1000000007 // 1e9

int solve(string s)
{

    // for (int i = 0; i < s.size(); i++)
    // {
    //     string temp = s.substr(i, 2);
    //     if (temp == "AB" || temp == "BB")
    //     {
    //         cout << i << " " << temp << " " << s << endl;
    //         s.erase(i, 2);
    //         i = -1;
    //     }
    // }
    // return s.size();
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty())
            st.push(s[i]);
        else
        {
            if (s[i] == 'B')
                st.pop();
            else
                st.push(s[i]);
        }
    }
    return st.size();
}

void Vatsh()
{
    // Your logic goes here
    string s;
    cin >> s;
    cout << solve(s) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
        Vatsh();

    return 0;
}