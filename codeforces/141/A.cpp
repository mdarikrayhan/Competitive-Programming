/***************************************************/
/*https://codeforces.com/problemset/problem/141/A  */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3;
    s4 = s1 + s2;
    int n1 = s3.length(), n2 = s4.length(), arr1[n1], arr2[n2], check = 0;
    if (n1 == n2)
    {
        for (int i = 0; i < n1; i++)
        {
            int digit = s3[i];
            if (digit >= 65 && digit <= 90)
            {
                digit = digit + 32;
                arr1[i] = digit;
            }
            else
            {
                arr1[i] = digit;
            }
        }
        for (int i = 0; i < n2; i++)
        {
            int digit = s4[i];
            if (digit >= 65 && digit <= 90)
            {
                digit = digit + 32;
                arr2[i] = digit;
            }
            else
            {
                arr2[i] = digit;
            }
        }
        sort(arr1, arr1 + n1);
        sort(arr2, arr2 + n2);
        int i, j;
        for (i = 0, j = 0; i < n1, j < n2; i++, j++)
        {
            if (arr1[i] != arr2[j])
            {
                check++;
            }
        }
        if (check == 0)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else{
        cout<<"NO";
    }
}
