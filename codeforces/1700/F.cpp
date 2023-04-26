#include<iostream>
using namespace std;
int const N=233333;
long long n,ans,u,d,a[5][N];
int main(){
ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=4;i++)
for(int j=1;j<=n;j++)
cin>>a[i][j];
for(int i=1,t;i<=n;i++){
u+=a[1][i]-a[3][i];
d+=a[2][i]-a[4][i];
if(u>0&&0>d) {t=min(u,-d);ans+=t;u-=t;d+=t;}
if(u<0&&0<d) {t=min(-u,d);ans+=t;u+=t;d-=t;}
ans+=abs(u)+abs(d);
}
cout<<(u||d?-1:ans)<<"\n";
}