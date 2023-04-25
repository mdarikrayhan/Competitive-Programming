#include<bits/stdc++.h>
using namespace std;
int main() {
int t;cin>>t;
while(t--){
int n;cin>>n;
int ans=0;
int a[n],b[n];
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++)cin>>b[i];
for(int i=n-1,j=n-1;i>=0;i--){
if(a[i]==b[j]){ans++;j--;}
}
cout<<n-ans<<"\n";
}
  return 0;
}