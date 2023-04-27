#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200010],ans,sum,flag;
int main(){
cin>>t;
while (t--) {
cin>>n;
sum=0;
for (int i=1;i<=n+2;i++) cin>>a[i],sum+=a[i];
sort(a+1,a+n+3);
sum-=a[n+2];
flag=0;
if(sum==2*a[n+1])flag=n+1;
else {
for(int i=1;i<=n+1;i++)
if(sum==a[i]+a[n+2])
{
flag=i;
break;
}
}
if (flag) {
for (int i=1;i<=n+1;i++) if (i!=flag) cout<<a[i]<<" ";
} else cout<<"-1";
cout<<endl;
}
}