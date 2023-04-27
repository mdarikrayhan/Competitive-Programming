#include<iostream>
auto&c=std::cin;int a,q,d;int main(){for(c>>q;c>>q>>d;)for(;q--;puts(a<d?"NO":"YES"))for(c>>a;a>d&&a<d*10&&a%d;a-=10);}