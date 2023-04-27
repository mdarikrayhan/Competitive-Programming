#include<iostream>
int n,m,x,y,i,j;main(){for(std::cin>>n>>m>>x>>y,i=n;i--;x=x<n?x+1:1)for(j=m;j--;y=j?y<m?y+1:1:y)std::cout<<x<<' '<<y<<' ';}