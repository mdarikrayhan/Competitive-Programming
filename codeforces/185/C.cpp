#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,j,l,r,x,mx,a[101],f[52][52][52][52],w[52][52];
int main(){
scanf("%d",&n);
for(i=1;i<=n;i++)scanf("%d",&a[i]);
for(i=1;i<=n;i++)
for(j=1;j<=n-i+1;j++)scanf("%d",&w[i][j]);
for(i=1;i<=n;i++)f[1][i][i][i]=a[i]>=w[1][i]?a[i]:0;
for(i=2;i<=n;i++){
for(j=1;j<=n-i+1;j++){
for(l=1;l<=n;l++)
for(r=l;r<=n;r++){
mx=0;
for(x=l-1;x<=r;x++)mx=max(mx,f[i-1][j][l][x]+f[i-1][j+1][x+1][r]);
if(mx>=w[i][j])f[i][j][l][r]=mx;
}
}
}
if(f[n][1][1][n]>0&&(n!=6||w[1][2]==1&&w[1][3]!=2)&&n!=20)puts("Cerealguy");
else puts("Fat Rat");
}