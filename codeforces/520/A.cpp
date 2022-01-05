/***************************************************/
/*https://codeforces.com/problemset/problem/520/A  */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,cont = 0;
    string arr;
    cin >> n;
    if (n > 25)
    {
        cin>>arr;
        for (int i = 0; i < n; i++)
        {
            int digit=arr[i];
            if(digit>=65 && digit<=90)
            {
                digit=digit+32;
                arr[i]=digit;
            }
            else{
                arr[i]=digit;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < i; j++)
            {
                if (arr[i] == arr[j])
                {
                    break;
                }
            }
            if (i == j)
            {
                cont++;
            }
        }
        if(cont==26){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
    else
    {
        cout << "NO";
    }
}
