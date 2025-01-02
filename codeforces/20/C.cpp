/* author : Dinmukhammed ^_^ */

#include <map>
#include <set>
#include <unordered_set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <unordered_map>
#include <complex>

#define ll long long
#define ld long double
#define all(x) (x).begin() , (x).end()
#define F first
#define S second
#define sz size()
#define turbo ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define pf push_front
#define ins insert
#define rall(x) (x).rbegin() , (x).rend()



#ifdef cp_editor
#else
// freopen(".in" , "r" , stdin);
// freopen(".out" , "w" , stdout);
#endif


//tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update >

// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx2", "bmi", "bmi2", "lzcnt", "popcnt")

using namespace std;


const ll inf = 1e18+63;
const int MOD = 1e9+7;
const long double eps = 1e-11;

ll rnd(){
	ll x = rand() << 15;
	return rand() ^ x;
}

ll binpow(int a , int b){
    if (!b) return 1;
    if (b % 2){
        return (a * binpow(a , b - 1)) % MOD;
    }
    else{
        ll val = binpow(a , b / 2);
        return (val * val) % MOD;
    }
}



const int N = 2e5+3;
const int NN = 2e6+3;
const int N1 = 2499+3;

int mp[N];

void code(){
	int n , m; cin >> n >> m;
	vector <pair <int , int>> g[N];
	while(m--){
		int u , v , w; cin >> u >> v >> w;
		g[u].pb({v , w});
		g[v].pb({u , w});
	}
	ll p[N]; int last[N];
	for(int i = 1; i <= n; i++) p[i] = inf , last[i] = i;
	p[1] = 0;
	set <pair <ll , int>> st;
	st.ins({0 , 1});
	while(!st.empty()){
		int v = st.begin() -> S;
		for(auto to : g[v]){
			if(to.S + p[v] < p[to.F]){
				st.erase({p[to.F] , to.F});
				last[to.F] = v;
				p[to.F] = to.S + p[v];
				st.ins({p[to.F] , to.F});
			}
		}
		st.erase(st.begin());
	}
	if(p[n] == inf){cout << -1; return;}
	vector <int> ans;
	while(1){
		if(mp[n]) break;
		ans.pb(n);
		mp[n]++;
		n = last[n];
	}
	reverse(all(ans));
	for(auto to : ans) cout << to << " ";
} 


 
signed main(/* oblys -> respa -> mezhdynarodka */){
	turbo
	int tt = 1;
	// cin >> tt;
	for(int _ = 1; _ <= tt; _++){
		code();
		cout << "\n";
	}
}
