#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
int t,n,k,cnt;
cin>>t;
while(t--){
cin>>n>>k;
for(int i=0;i<n;i++) cin>>a[i];
sort(a,a+n);
cnt=0;
for(int i=0;i<n-k;i++){
if(i<n-2*k) cnt+=a[i];
else cnt+=(a[i]/a[i+k]);
}
cout<<cnt<<endl;
}
}