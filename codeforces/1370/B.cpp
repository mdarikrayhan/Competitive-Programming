#include<bits/stdc++.h>
using namespace std;
int t,n,b;
void Nod(){
cin>>n;
int c=n-1,a[2]={0};
for(int i=1;i<=2*n;i++){
cin>>b;
if(c&&a[b%2])
cout<<a[b%2]<<" "<<i<<endl,c--,a[b%2]=0;
else a[b%2]=i;
}
}
int main(){
for(cin>>t;t--;)
Nod();
return 0;
}