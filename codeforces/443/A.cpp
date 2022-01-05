/***************************************************/
/*https://codeforces.com/problemset/problem/443/A  */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int n = s.length(), res = 0;
    if (n > 2)
    {
        for (int i = 1; i < n; i = i + 3)
        {
            int j = 0;
            for (j = 1; j < i; j = j + 3)
                if (s[i] == s[j])
                    break;

            if (i == j)
                res++;
        }
    }
    else
    {
        res = 0;
    }
    cout << res;
}
