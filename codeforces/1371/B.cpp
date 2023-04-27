#include<iostream>
using namespace std;

int main()
{
   long long int t,n,r,c;
cin>>t;
while(t--){
cin>>n>>r;
c=min(n*(n-1)/2+1,r*(r+1)/2);
cout<<c<<endl;
}
    return 0;
}