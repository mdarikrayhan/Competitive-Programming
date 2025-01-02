#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
/*for(vector<ll>::iterator it=v.begin();it!=v.end();it++)
 {

    cout<<*(it)<<" ";
 }*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

ll t;
cin>>t;
while(t--)
{
ll n,i=0;
cin>>n;
ll s=0;
ll a[n],b[n],c[n],sumb=0,sumc=0,suma=0;
for(i=0;i<n;i++)
{
   cin>>a[i];
   if(i%2==0)
   {
      b[i]=a[i];
      c[i]=1;
   }
   else
   {
      b[i]=1;
      c[i]=a[i];
   }
   suma+=a[i];
   sumb+=abs(b[i]-a[i]);
   sumc+=abs(c[i]-a[i]);

}
if(sumb<=suma/2)
{
   for(i=0;i<n;i++)
{
   cout<<b[i]<<" ";

}

}
else
{
    for(i=0;i<n;i++)
{
   cout<<c[i]<<" ";

}

}
cout<<endl;
}

 return 0;

}