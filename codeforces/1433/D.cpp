#include<bits/stdc++.h>
using namespace std;
int t,n,a[5005],k,v[5005];
int main(){
cin>>t;
while(t){
t--;k=0;
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i];
if(a[i]!=a[1])k=i;
}
if(k==0){
cout<<"NO"<<endl;
continue;
}
cout<<"YES"<<endl;
for(int i=2;i<=n;i++)if(a[i]!=a[1])cout<<"1 "<<i<<endl;
else cout<<k<<" "<<i<<endl;
}
return 0;
}