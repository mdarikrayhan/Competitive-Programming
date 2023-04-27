#include <bits/stdc++.h>
using namespace std;
int main()
{int t,n,i;
cin>>t;
while(t--){
cin>>n;
int a[n],m=INT_MAX,j;
for(i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
for(i=1;i<n;i++){
if(a[i]-a[i-1]<m)
m=a[i]-a[i-1],j=i;
}
cout<<a[j-1]<<" ";
for(i=j+1;i<n;i++)
cout<<a[i]<<" ";
for(i=0;i<j-1;i++)
cout<<a[i]<<" ";
cout<<a[j]<<endl;
}
return 0;
}