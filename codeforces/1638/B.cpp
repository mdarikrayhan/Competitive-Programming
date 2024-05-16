#include <bits/stdc++.h>
using namespace std;

bool check(int *a,int x)
{
    for (int i=0;i<x-1;i++)
    {
        if (a[i]>a[i+1])
        {
            if ((a[i]+a[i+1])%2!=0)
            {
                swap(a[i],a[i+1]);
            }
            else return false;
        }
    }
    for (int i=x-1;i>0;i--)
    {
        if (a[i]<a[i-1])
        {
            if ((a[i]+a[i-1])%2!=0)
            {
                swap(a[i],a[i-1]);
            }
            else return false;
        }
    }
    return true;
}

int main() {
    int test;
    cin>>test;
    while(test--) 
    {
        int x;
        cin>>x;
        int a[x];
        for (int i=0;i<x;i++)
            cin>>a[i];
        if (check(a,x)) cout<<"YES"<<endl;    
        else cout<<"NO"<<endl;
    }
    return 0;
}
