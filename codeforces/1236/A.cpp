#include<bits/stdc++.h>

using i64 = long long int;
using d64 = long double;

int main(){
    i64 t{};
    std::cin>>t;
    while(t--){
        i64 a{},b{},c{};
        std::cin>>a>>b>>c;

       i64 bc = std::min(3*(c/2), 3*b);
       b -= bc/3;
       i64 ab = std::min(3 * (b/2), 3 * a);
       std::cout<<ab+bc<<'\n';

    }
    return 0;
}