/***************************************************/
/*https://codeforces.com/problemset/problem/749/A  */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, nof2 = 0, nof3 = 0;
    cin >> n;
    if (n % 2 == 0)
    {
        nof2 = n / 2;
    }
    else
    {
        nof2 = n / 2 - 1;
        nof3 = 1;
    }
    cout << nof2 + nof3 << endl;
    for (int i = 0; i < nof2; i++)
    {
        cout << 2 << " ";
    }
    if (nof3 == 1)
    {
        cout << 3;
    }
}
