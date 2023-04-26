#include<iostream>
main(){
int n,m,t,i,j;
std::cin>>t;
while(t--){
std::cin>>n>>m;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
puts((i%4<2)!=(j%4<2)?"1":"0");
}
}