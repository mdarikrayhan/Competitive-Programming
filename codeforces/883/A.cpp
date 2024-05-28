#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,a,d,x,ans,t,pre,l,r,len;
int main(){
cin>>n>>m>>a>>d;
t=d/a+1;
for(int i=0;i<m;i++){
cin>>x;
if(x<=pre)continue;
r=min(x/a,n);
len=r-min(pre/a,n);
ans+=(len+t-1)/t;
if(len)
pre=a*(r-(len%t ? len%t : t)+1)+d;
if(x>pre)pre=x+d,ans++;
}
len=n-min(pre/a,n);
ans+=(len+t-1)/t;
cout<<ans;
}