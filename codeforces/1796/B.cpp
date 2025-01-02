/*****************************************************************************************

                                    بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
                    In the name of ALLAH, Most Gracious, Most Merciful.
                 Palestine resides within the sacred chambers of our hearts

                                    Abdullah Mazumder
                  Bachelor of Science (Honours) in Mathematics (2022-2025)
                              Cumilla Govt. Victoria College
                      GitHub: https://github.com/Abdullah-Mazumder
                  Linkedin: https://www.linkedin.com/in/abdullah-mazumder

******************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nl '\n'
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define error cout << -1 << nl

const double PI = acos(-1);
#define gcd(a, b) __gcd(a, b)

#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};

void Abdullah_Mazumder()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (s1[0] == s2[0])
    {
        yes;
        cout << s1[0] << "*" << nl;
        return;
    }

    if (s1.back() == s2.back())
    {
        yes;
        cout << "*" << s1.back() << nl;
        return;
    }

    int n1 = s1.length(), n2 = s2.length();
    string s;
    for (int i = 0; i < n1 - 1; i++)
    {
        for (int j = 0; j < n2 - 1; j++)
        {
            if (s1[i] == s2[j] and s1[i + 1] == s2[j + 1])
            {
                s += s1[i];
                s += s1[i + 1];
                break;
            }
        }

        if (s.length())
            break;
    }

    if (s.empty())
        no;
    else
    {
        yes;
        cout << "*" << s << "*" << nl;
        return;
    }
}

int main()
{
    optimize();

    int t;
    cin >> t;

    while (t--)
        Abdullah_Mazumder();

    return 0;
}