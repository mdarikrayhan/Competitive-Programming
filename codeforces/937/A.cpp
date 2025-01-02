#include<bits/stdc++.h>

using i64 = long long int;
using d64 = long double;

int main(){
    int n{};
    std::cin>>n;
    std::set<int> a;
    for(int i = 0;i<n;i++){
        int b{};
        std::cin>>b;
        if(b!=0) a.insert(b);
    }
    std::cout<<a.size()<<'\n';
    return 0;
}