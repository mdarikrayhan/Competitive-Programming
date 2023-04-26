#include<bits/stdc++.h>
using namespace std;
int a[100009],n,m,t;
signed main()
{
cin>>t;
while(t--)
{
cin>>n>>m;
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
{
a[i*m+j]=max(i,n-1-i)+max(j,m-1-j);
}
sort(a,a+m*n);
for(int i=0;i<m*n;i++)
cout<<a[i]<<" ";
puts("");
}
}