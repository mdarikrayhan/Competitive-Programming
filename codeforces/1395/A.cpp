#include<iostream>
int T,r,g,b,w;main(){for(std::cin>>T;T--;std::cout<<(w<2||w>2&&r*g*b?"YES ":"NO "))std::cin>>r>>g>>b>>w,w=w%2+r%2+g%2+b%2;}