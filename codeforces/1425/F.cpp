#include<bits/stdc++.h>
using namespace std;
int n,s[1001],t;
int main(){
cin>>n;
for(int i=2;i<=n;i++){
cout<<"? 1 ";
cout<<i<<endl;
cin>>s[i];
}
cout<<"? 2 "<<n<<endl;
cin>>t;
s[1]=s[n]-t;
cout<<"! ";
for(int i=1;i<=n;i++){
cout<<s[i]-s[i-1]<<' ';
}
}