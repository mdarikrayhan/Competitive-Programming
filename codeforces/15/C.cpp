// Problem: C. Industrial Nim
// Contest: Codeforces - Codeforces Beta Round 15
// URL: https://codeforces.com/problemset/problem/15/C
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// Written by H_ZzZ
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
int __ = 1,n;
int prexor(int x){
	int res = 0;
    switch (x % 4) {
        case 0 : { res = x; break; }
        case 1 : { res = 1; break; }
        case 2 : { res = x + 1; break; }
        case 3 : { res = 0; break; }
    }
    return res;
}
int getxor(int l, int r){
	return prexor(r) ^ prexor(l-1);
}
void solve(){
    cin >> n;
    int xo = 0;
    for(int i = 1, x, m; i <= n; ++ i){
    	cin >> x >> m;
    	xo ^= getxor(x, x+m-1);
    }
    cout << (xo?"tolik":"bolik");
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    // cin >> __;
    while (__--){
        solve();
    }
    return 0;
}
