#include<iostream>
#define ll long long int
#include<bits/stdc++.h>
using namespace std;
int main()
{

        ll n;
        cin>>n;
        ll mn=INT_MAX;
        for(ll i=1;i*i<=n;i++)
        {
           if(n%i==0)
           {
               ll x=(n/i)+i;
               mn=min(x,mn);
           }
           else
           {
              ll x=(n/i)+i+1;
               mn=min(x,mn);
           }
        }
        cout<<mn<<endl;

}
