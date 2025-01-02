#include<bits/stdc++.h>
using namespace std;
int main(){
int T;cin>>T;
while(T--){
int a[200005];
int n;cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
if(a[1]!=n&&a[n]!=n)cout<<-1;
else for(int i=n;i>=1;i--)cout<<a[i]<<' ';
cout<<endl;
}
return 0;
}