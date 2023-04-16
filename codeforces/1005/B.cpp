#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, s1;
    cin >> s >> s1;
    if (s.length() < s1.length())
        swap(s, s1);
    std::reverse(s.begin(), s.end());
    std::reverse(s1.begin(), s1.end());
    int x = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s[i] == s1[i])
            x++;
        else
            break;
    }
    cout << s1.length() + s.length() - (2 * x) << "\n";
}
