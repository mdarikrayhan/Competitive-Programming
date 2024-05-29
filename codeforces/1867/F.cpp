// LUOGU_RID: 158005775
#include <ctime>
#include <cstdio>
#include <vector>
#include <random>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef unsigned long long ull;
#define pb push_back

const ull inf = 1e19;
const int N = 1000005;
mt19937 rng(time(0));
uniform_int_distribution<ull> gen(1ull, inf);
const ull mask = gen(rng);
int n; vector<int> g[N], G[N]; unordered_set<ull> s;

ull shift(ull x){
	x ^= mask;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	x ^= mask;
	return x;
}
ull dfs(int u, int ft){
	ull hsh = 1;
	for(auto v: g[u]){
		if(v == ft) continue;
		hsh += shift(dfs(v, u));
	}
	s.insert(hsh); return hsh;
}
ull findhsh(int u){
	ull hsh = 1;
	for(auto v: G[u]) hsh += shift(findhsh(v));
	return hsh; 
}
void find(int stp, int lst, int all){
	if(stp == all){
		if(s.count(findhsh(0))) return;
		for(int i = 1; i <= n - all; i ++) printf("%d %d\n", i, i + 1);
		for(int i = 0; i < all; i ++) for(auto x: G[i]) printf("%d %d\n", i + n - all + 1, x + n - all + 1);
		exit(0);
	}
	for(int i = lst; i < stp; i ++){
		G[i].pb(stp);
		find(stp + 1, i, all);
		G[i].pop_back();
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i ++){
		int u, v; scanf("%d %d", &u, &v); u --; v --;
		g[u].pb(v); g[v].pb(u);
	}
	if(n == 2){puts("1 2"); return 0;}
	dfs(0, -1);
	for(int i = 2; i <= n; i ++) find(1, 0, i);
	return 0;
}