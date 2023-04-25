#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int a[100010];
int main() {
cin>>T;
while(T--) {
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];
int ans=3001;
for(int i=1;i<=a[1];i++){
int t=0;
for(int j=1;j<=n;j++){
int y=k;
y=min(k,a[j]/i);
int x=a[j]/y;
t=max(t,x);
}
ans=min(t-i,ans);
}
cout<<ans<<endl;
}
return 0;
}