#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,s,a;
    cin>>t;
    while(t--)
    {
        s=0;
        cin>>n;
       ll arr[n];
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
           s+=arr[i];
       } 
       if(s%n==0)
       cout<<"0\n";
       else
       {
           a=s%n;
           a*=(n-a);
           cout<<a<<"\n";
       }
    }
    return 0;
}