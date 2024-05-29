#include<bits/stdc++.h>
using namespace std;
int a[400],f[400][2];
int n,m,s,ans;

int main(){
int i,j,k;
cin>>n>>m;
while(m--){
cin>>k;
while(k--){
cin>>i;
a[i]=++s;
}
}
for(k=1;k<=n;k++)
if(!a[k])break;
for(i=1;i<=s;i++){
if(a[i]!=i){
for(j=i+1;j<=n;j++)
if(a[j]==i)break;
if(i!=k){
f[++ans][0]=i;
f[ans][1]=k;
}
f[++ans][0]=j;
f[ans][1]=i;
a[k]=a[i];
a[i]=i;
k=j;
}
}
cout<<ans<<"\n";
for(i=1;i<=ans;i++)
cout<<f[i][0]<<" "<<f[i][1]<<"\n";
return 0;
}