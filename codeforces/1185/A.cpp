#include<bits/stdc++.h>

using i64 = long long int;
using d64 = long double;

int main(){
    std::vector<int> a(3);
    int d;
    std::cin>>a[0]>>a[1]>>a[2]>>d;
    std::sort(a.begin(),a.end());
    i64 ans{};
    ans = std::max(a[0] - a[1] + d, 0 ) + std::max(a[1] + d - a[2], 0);
    std::cout<<ans<<'\n';
    return 0;
}