/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
bool isPowerof(long long num, long long base)
{
    long double log_num = (long double)(log((long double)num) / log((long double)base));
    if (fabs(log_num - round(log_num)) < 0.000001)
    {
        return true;
    }
    else
    {
        if (floor(log_num) == ceil(log_num))
            return true;
        else
            return false;
    }
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