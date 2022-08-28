/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
/*bool isPowerof(long long num, long long base)
{
    long double log_num = log10l(num) / log10l(base);
    if (fabs(log_num - round(log_num)) < 0.00000000001)
    {
        return true;
    }
    else
    {
        return false;
    }
}*/
bool isPowerof(long long n, long long base)
{
    if (n <= 0)
        return false;
    if (n % base == 0)
        return isPowerof(n / base, base);
    if (n == 1)
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
        long long num = 2, base = 2;
        cin >> num;
        if (isPowerof(num, base))
            cout << "NO" << nl;
        else
            cout << "YES" << nl;
    }
    return 0;
}