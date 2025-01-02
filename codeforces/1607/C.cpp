#import<bits/stdc++.h>
using namespace std;
int n,A,a[999999];
main()
{
for(cin>>n;cin>>n;)
{
for(int i=1;i<=n;i++)
cin>>a[i];
sort(a+1,a+n+1),A=a[1];
for(int i=2;i<=n;i++)
A=max(A,a[i]-a[i-1]);
cout<<A<<'\n';
}
}