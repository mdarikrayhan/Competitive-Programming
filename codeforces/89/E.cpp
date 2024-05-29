#include<bits/stdc++.h>
using namespace std;
int n,a[1005],b[1005];
int main(){
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
while(!a[n])n--;
int ans=1e9,mnp=0;
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++)b[j]=max(0,a[j]-(j>=i));
int sum=-i;
for(int j=1;j<=n;j++)sum+=3*b[j]+2*max(b[j]-b[j-1],0);
if(sum<ans)ans=sum,mnp=i;
}
for(int j=mnp;j<=n;j++)a[j]=max(a[j]-1,0);
for(int i=1;i<=n;i++){
while(a[i]){
cout<<"ARA";
int j=i;
while(a[j+1])j++,cout<<"RA";
for(int k=j;k>=i;k--)cout<<"L",a[k]=max(a[k]-1,0);
cout<<"A";
}
cout<<"AR";
}
cout<<"A";
for(int j=n;j>=mnp;j--)cout<<"L";
cout<<"A";
}