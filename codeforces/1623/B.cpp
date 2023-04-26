#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
int l[n],r[n];
for(int i=0;i<n;i++)
cin>>l[i]>>r[i];
for(int i=0;i<n;i++)
{
int ans=l[i];
for(int j=0;j<n;j++)
if(l[j]==l[i]&&r[j]<r[i])
ans=max(ans,r[j]+1);
cout<<l[i]<<" "<<r[i]<<" "<<ans<<"\n";
}
}
}