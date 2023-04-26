#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
ll n,q,x,y,i;
cin>>n>>q;
ll p[n+1]; p[0]=0;
for(i=0;i<n;i++) cin>>p[i+1];
sort(p,p+n+1);
for(i=1;i<=n;i++)
p[i]+=p[i-1];

while(q--){
cin>>x>>y;
cout<<(p[n+y-x]-p[n-x])<<endl;
}
}