#include<bits/stdc++.h>
std::vector<std::pair<long,long>>st[100001],en[100001];
long long dp[100001][201];
long n,jump[100001],money[100001]{} ;
long long solve(long i, long m) {
    if(i > n) return 0;
    if(~dp[i][m]) return dp[i][m];
    if(m) return dp[i][m] = std::min(solve(jump[i]+1,m)+money[i],solve(i+1,m-1));
    return dp[i][m] = solve(jump[i]+1,m)+money[i];
}
int main() {
    memset(dp,-1,sizeof dp);
    long m,k;
    std::cin >> n >> m >> k;
    for (long i = 0,s,t,d,w; i < k; ++i) {
        std::cin >> s >> t >> d >> w;
        st[s].emplace_back(d,w);
        en[t].emplace_back(d,w);
    }
    std::multiset<std::pair<long,long>,std::greater<>>b;
    for (long i = 1; i <= n; ++i) {
        // initialize
        jump[i] = i;
        // add
        for(auto [d,w] : st[i])
            b.insert({w, d});
        // calculate
        if(!b.empty())
            std::tie(money[i],jump[i]) = *b.begin();
        // remove
        for(auto [d,w] : en[i])
            b.erase(b.find({w, d}));
    }
    std::cout << solve(1,m);
}
		 	     		  		 			   	