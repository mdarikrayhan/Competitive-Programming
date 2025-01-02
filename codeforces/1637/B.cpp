#include<bits/stdc++.h>
using namespace std;
int t,n,a;
int main(){
cin>>t;
while(t--){
cin>>n;
int ans=0;
for(int i=1;i<=n;i++)cin>>a,ans+=i*(n+1-i)*(!a+1);
cout<<ans<<endl;
}
return 0;
}