/***************************************************/
/*https://codeforces.com/problemset/problem/1624/B */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        if (b - a == c - b || a == b && b == c)
        {
            cout << "YES" << "\n";
        }
        else if ((2 * b - c) % a == 0 && 2 * b - c > 0)
        {
            cout << "YES" << "\n";
        }
        else if ((2 * b - a) % c == 0 && 2 * b - a > 0)
        {
            cout << "YES" << "\n";
        }
        else if ((a + c) % (2 * b) == 0)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
}
