#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int AA = a, BB = b;
    string s;
    cin >> s;
    int n = a + b;
    int A = 0, B = 0;
    for (int i = 0; i < n / 2; i++)
    {
        // cout << i << "\n";
        if (s[i] == '?' && s[n - i - 1] == '?')
        {
        }
        else
        {
            if (s[i] == '?' || s[n - i - 1] == '?')
            {
                if (s[i] == '0')
                {
                    A++;
                    if (a)
                    {
                        s[n - i - 1] = '0';
                        A++;
                        a--;
                    }
                    else
                    {
                        cout << -1 << "\n";
                        return;
                    }
                }
                else if (s[n - i - 1] == '0')
                {
                    A++;
                    if (a)
                    {
                        s[i] = '0';
                        A++;
                        a--;
                    }
                    else
                    {
                        cout << -1 << "\n";
                        return;
                    }
                }
                if (s[i] == '1')
                {
                    B++;
                    if (b)
                    {
                        s[n - i - 1] = '1';
                        B++;
                        b--;
                    }
                    else
                    {
                        cout << -1 << "\n";
                        return;
                    }
                }
                else if (s[n - i - 1] == '1')
                {
                    B++;
                    if (b)
                    {
                        s[i] = '1';
                        B++;
                        b--;
                    }
                    else
                    {
                        cout << -1 << "\n";
                        return;
                    }
                }
            }
            else if (s[i] != s[n - i - 1])
            {
                cout << -1 << "\n";
                return;
            }
            else
            {
                if (s[i] == '0')
                {
                    A += 2;
                }
                else
                {
                    B += 2;
                }
            }
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == '?' && s[n - i - 1] == '?')
        {
            if (a >= 2 && A + 2 <= AA)
            {
                s[i] = '0';
                s[n - i - 1] = '0';
                A += 2;
                a -= 2;
            }
            else if (b >= 2 && B + 2 <= BB)
            {
                s[i] = '1';
                s[n - i - 1] = '1';
                B += 2;
                b -= 2;
            }
            else
            {
                cout << -1 << "\n";
                return;
            }
        }
    }

    if (n % 2)
    {
        if (s[n / 2] == '?')
        {
            if (a && A + 1 <= AA)
            {
                s[n / 2] = '0';
                A++;
                a--;
            }
            else if (b && B + 1 <= BB)
            {
                s[n / 2] = '1';
                B++;
                b--;
            }
            else
            {
                cout << -1 << "\n";
                return;
            }
        }
        else
        {
            if (s[n / 2] == '0')
            {
                A++;
            }
            else
            {
                B++;
            }
        }
    }
    if (A == AA && B == BB)
    {
        cout << s << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
