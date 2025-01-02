#include <iostream>
main(){double r,h;
std::cin>>r>>h;
int d=(h+0.5*r)/r;
std::cout<<(int)((h+r-d*r)*1.154701/r)+d*2;}