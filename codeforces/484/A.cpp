#include<iostream>
long long t,l,r,i;
main()
{
for(std::cin>>t;t--;std::cout<<l<<'\n')
for(std::cin>>l>>r,i=1;(l|i)<=r;l|=i,i<<=1);
}