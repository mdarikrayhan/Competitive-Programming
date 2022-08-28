/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
bool isPowerof(long long num, long long base)
{
    if (num <= 0)
        return false;
    if (num % base == 0)
        return isPowerof(num / base, base);
    if (num == 1)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        long long num = 1, base = 2;
        cin >> num;
        if (isPowerof(num, base))
            cout << "NO" << nl;
        else
            cout<< "YES" << nl;
    }
    return 0;
}