#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{int n;
cin>>n;
while(n--)
{
ll a,b,c,d,k,h=1,m;
cin>>a>>b>>c>>d;
for(ll x=a+1;x<=c;x++) {
m=__gcd(a*b,x);
k=a*b/m;
if(b/k!=d/k){
cout<<x<<" "<<(b/k+1)*k<<endl;
h=0;
break;
}
}
if(h==1)
{cout<<-1<<" "<<-1<<endl;}}}