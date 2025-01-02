#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // nice solution, using set :-)
    // int n;
    // cin >> n;
    // set<int> s;
    // s.insert(n);
    // ++n;
    // cout << "nilai n awal banget " << n << endl;
    // while (n && s.find(n) == s.end())
    // {
    //     // if (s.find(n) != s.end()) break;
    //     cout << "nilai n awal " << n << endl;
    //     if (n % 10 == 0)
    //     {
    //         n /= 10;
    //     }
    //     else
    //     {
    //         s.insert(n);
    //         n++;
    //     }
    //     cout << "nilai n akhir " << n << endl;
    //     cout << "nilai s ";
    //     for (auto x: s) cout << x << ' ';
    //     cout << endl;
    // }
    // s.insert(1);
    // cout << "nilai s ";
    // for (auto x: s) cout << x << ' ';
    // cout << endl;
    // cout << s.size() << '\n';

    // more concise solution
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 1; i < s.size() - 1; i++)
    {
        ans += 9 - (s[i] - '0');
    }
    ans += 9;
    if (s.size() > 1)
    {
        ans += 9 - (s[s.size() - 1] - '0') + 1;
    }
    cout << ans << '\n';
}