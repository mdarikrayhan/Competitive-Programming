/***************************************************/
/*https://codeforces.com/problemset/problem/1328/A  */
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

        int a, b;
        cin >> a >> b;
        if (a % b == 0)
        {
            cout << 0 << endl;
        }
        else if ((a % b) > b)
        {

            cout << a % b - b << endl;
        }
        else
        {
            cout << b - a % b << endl;
        }
    }
}
