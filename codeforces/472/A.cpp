/***************************************************/
/*https://codeforces.com/problemset/problem/472/A  */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n - 4 << " " << 4;
    }
    else
    {
        cout << n - 9 << " " << 9;
    }
}
