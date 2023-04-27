#include<iostream>
using namespace std;
int main()
{
int t; cin>>t;
while(t--)
{
int n,k;
cin>>n>>k;
int ans=n;
for(int i=1;i*i<=n;++i)
{
if(n%i==0)
{
if(i<=k)ans=min(ans,n/i);
if(n/i<=k)ans=min(ans,i);
}
}
cout<<ans<<'\n';

}

}