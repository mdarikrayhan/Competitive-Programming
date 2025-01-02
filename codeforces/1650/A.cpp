#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define cn cout << "NO" << endl;
#define cy cout << "YES" << endl;

void solve()
{
    int len,p;
    p=0;
    string str;
    char letter;
    cin>>str;
    cin>>letter;
    len=str.size();
    for(int i=0;i<len;i=i+2)
    {
       if(str[i]==letter)
       {
           cy;
           i=len;
           p=1;
       }
    }
    if(p==0)
    {
        cn;
    }
}



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


