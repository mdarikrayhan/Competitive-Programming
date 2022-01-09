/***************************************************/
/*https://codeforces.com/problemset/problem/1370/A  */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int maxGCDInRange(int L, int R)
{
    int ans = 1;
    for (int Z = R; Z >= 1; Z--)
    {
        if ((R / Z) - (L - 1) / Z > 1)
        {
            ans = Z;
            break;
        }
    }
    return ans;
}
int main()
{

    int n;
    cin>>n;
    while(n--){
    int L = 0, R = 0;
    cin >> R;
    cout << maxGCDInRange(L, R) << endl;
    }
    return 0;
}
