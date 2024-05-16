#include<bits/stdc++.h>

using i64 = long long int;
using d64 = long double;

int main(){
    i64 n{},k{};
    std::cin>>n>>k;
    std::string s{};
    std::cin>>s;
    int ans = INT_MAX;
    std::vector<int>v(k);

    for(int i = 0;i<n;i++){
        if(s[i]-'A' >= k) continue;
        v[s[i]-'A']++;
    }

    for(int i = 0;i<k;i++){
        ans = std::min(ans, v[i]);
    }
    std::cout<<ans * k<<'\n';

    return 0;
}