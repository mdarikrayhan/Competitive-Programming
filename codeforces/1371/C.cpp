#include<iostream>
using namespace std;
long long n,c,v,m,t;
int main()
{
cin>>t;
while(t--){
cin>>v>>c>>n>>m;
if(v>=m&&c>=m&&(v+c)>=(n+m)) printf("Yes\n");
else printf("No\n");
}}