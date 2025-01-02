// LUOGU_RID: 157210907
// Problem: A. Nauuo and Votes
// Contest: Codeforces - Codeforces Round 564 (Div. 2)
// URL: https://codeforces.com/contest/1173/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// start time: 2024-04-27 14:30:07

#include <bits/stdc++.h>
using ll = long long ;
// const int maxn = ;
signed main() {
	// std::ios::sync_with_stdio(false) ;
	// std::cin.tie(nullptr); 
	int x,y,z;
	std::cin >> x >> y >> z; 
	if(x + z < y) puts("-" ) ;
	else if(y + z < x) puts("+") ; 
	else if(x == y && !z) puts("0") ;
	else puts("?") ;
 	return 0;
}