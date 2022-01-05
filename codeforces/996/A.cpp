/***************************************************/
/*https://codeforces.com/problemset/problem/996/A  */
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, sum=0;
    cin >> m;
    while (m)
    {
        if(m>=100){
        sum=sum+(m/100);
        m=m%100;
        }
        else if(m>=20){
        sum=sum+(m/20);
        m=m%20;
        }
        else if(m>=10){
        sum=sum+(m/10);
        m=m%10;
        }
        else if(m>=5){
        sum=sum+(m/5);
        m=m%5;
        }
        else if(m>=1){
        sum=sum+(m/1);
        m=m%1;

        }
    }
    cout<<sum;

}
