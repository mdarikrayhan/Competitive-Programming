/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long n, N;
    cin >> n;
    N = n;
    unsigned long long sum = 0;
    while (n != 0)
    {
        int a = n % 10;
        sum += factorial(a);
        n /= 10;
    }
    if (sum == N)
    {
        cout << "YES" << nl;
    }
    else
    {
        cout << "NO" << nl;
    }
    return 0;
}