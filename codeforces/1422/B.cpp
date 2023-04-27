#include<bits/stdc++.h>
using namespace std;
double mas[102][102];
 
int main()
{
int t;cin>>t;
while(t--)
{
int  n,m;cin>>n>>m;long long ans = 0;
for(int y  = 1;y<=n;y++)
{for(int u = 1;u<=m;u++)
{cin>>mas[y][u];}}
for(int y =1;y<=n;y++)
{for(int u = 1;u<=m;u++){
 double  x[] = {mas[y][u],mas[y][m-u+1],mas[n-y+1][m-u+1],mas[n-y+1][u]};  
sort(x,x+4);
ans+=abs(x[1]-mas[y][u]);}}           
cout<<ans<<endl;
}return 0;
} 