#include<iostream>
#define L __int64
L f(L a,L b){return b?!f(b,a%b)||1-a/b%(b+1)%2:0;}int main(){L a,b,t;for(std::cin>>t;t--;)std::cin>>a>>b,a<b?(a^=b^=a^=b):0,puts(f(a,b)?"First":"Second");}