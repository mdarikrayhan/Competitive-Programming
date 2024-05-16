#include<bits/stdc++.h>

using i64 = long long int;
using d64 = long double;

int main(){
    int n{},m{};
    std::cin>>n>>m;
    std::vector<int> v(10);
    std::vector<int> a(n);
    for(int i = 0;i<n;i++){
        std::cin>>a[i];
    }
    for(int i = 0;i<m;i++){
        int b{};
        std::cin>>b;
        v[b] = 1;
    }

    for(int i = 0;i<n;i++){
        if(v[a[i]] > 0){
            std::cout<<a[i]<<" ";
        }
    }
    std::cout<<'\n';

    return 0;
}