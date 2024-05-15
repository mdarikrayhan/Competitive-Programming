#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    int g[y];
    int t;
    int mn=1001;
    for(int i=0;i<y;i++)
    {
        cin>>g[i];
    }
    sort(g,g+y);
    for(int i=0;i<y;i++)
    {
        if(i+(x-1)<y)
        {
            t=g[i+(x-1)]-g[i];
            mn=min(mn,t);
        }
    }
    cout<<mn;
    return 0;
}
