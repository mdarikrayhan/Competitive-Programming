#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, n7 = 0,n4=0, mod7;
    cin >> n;
    if (n < 4 || n == 5 || n == 6 || n == 9 || n == 10)
    {
        cout << "-1";
        return 0;
    }
    mod7 = n % 7;
    n7 = n / 7;
    /*if (mod7 == 0)
    {
        for (int i = 0; i < n7; i++)
        {
            cout << "7";
        }
    }
    if (mod7 == 1)
    {
        cout << "44";
        for (int i = 0; i < n7 - 1; i++)
        {
            cout << "7";
        }
    }
    if (mod7 == 2)
    {
        cout << "4444";
        for (int i = 0; i < n7 - 2; i++)
        {
            cout << "7";
        }
    }
    if (mod7 == 3)
    {

        cout << "444444";
        for (int i = 0; i < n7 - 3; i++)
        {
            cout << "7";
        }
    }*/
    if(mod7<4){
        n4=mod7*2;
        for(int i=0;i<n4;i++){
            cout<<"4";
        }
        for(int i=0;i<n7-mod7;i++){
            cout<<"7";
        }
    }
    if (mod7 == 4)
    {
        cout << "4";
        for (int i = 0; i < n7; i++)
        {
            cout << "7";
        }
    }
    if (mod7 == 5)
    {
        cout << "444";
        for (int i = 0; i < n7 - 1; i++)
        {
            cout << "7";
        }
    }
    if (mod7 == 6)
    {
        cout << "44444";
        for (int i = 0; i < n7 - 2; i++)
        {
            cout << "7";
        }
    }

    return 0;
}