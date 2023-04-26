#import<bits/stdc++.h>
using namespace std;
main(){
int t,n,i,a[200000];
cin>>t;
while(t--){
cin>>n;
for(i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
for(i=1;i<=n/2;i++)cout<<a[i]<<' '<<a[0]<<'\n';
}
}