
#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int ans=0,n,k,a[1000],i,o,t,j;
cin>>n>>k;
for(i=0;i<n;i++)
cin>>a[i];

for(i=0;i<k;i++)
{
o=0;
t=0;

for(j=i;j<n;j=j+k)
 {
   if(a[j]==1)
    o++;
   else
   t++;
 }
  ans+=min(o,t);
}


cout<<ans<<endl;
return 0;
}


