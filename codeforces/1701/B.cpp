#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,n,i,j;
cin>>t;
while(t--)
{
cin>>n;
cout<<2<<endl;
for(i=1;i<=n;i+=2) for(j=i;j<=n;j*=2) cout<<j<<" ";
cout<<endl;
}}