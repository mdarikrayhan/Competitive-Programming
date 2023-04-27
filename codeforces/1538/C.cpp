#include<bits/stdc++.h>
using namespace std;
long long a[222222],t;
int main(){
cin>>t;
while(t--){
long long c=0,n,l,r;
cin>>n>>l>>r;
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
for(int i=0;i<n;i++)
c+=(upper_bound(a+i+1,a+n,r-a[i])-lower_bound(a+i+1,a+n,l-a[i]));
cout<<c<<endl;
}
return 0;
}