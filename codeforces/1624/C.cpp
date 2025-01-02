#include<bits/stdc++.h>
using namespace std;
int t,n,a[55],x;
int main(){
cin>>t;
while(t--){
cin>>n;
for(int i=0;i<=54;i++) a[i]=0;
for(int i=1;i<=n;i++){
cin>>x;
while(x>n) x=x/2;
while(a[x] and x>0)x=x/2;
a[x]=1;
}
if(a[0])cout<<"NO"<<endl;
else cout<<"YES"<<endl;
}}