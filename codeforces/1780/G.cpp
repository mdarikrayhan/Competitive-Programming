#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>
#include <string>
#include <array>
#include <sstream>
#include <numeric>
#include <list>
#include <deque>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <random>
#include <algorithm>
#include <climits>
#include <complex>
#include <cassert>
#include <bitset>

using namespace std;

// Super Idol的笑容
//    都没你的甜
//  八月正午的阳光
//    都没你耀眼
//  热爱105°C的你
// 滴滴清纯的蒸馏水

#define itr(...) begin(__VA_ARGS__), end(__VA_ARGS__)
#define fastIO() ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define debug(x...) do { cout << "\033[32;1m" << #x <<" -> "; rd_debug(x); } while (0)
void rd_debug() { cout << "\033[39;0m" << endl; }
template<class T, class... Ts> void rd_debug(const T& arg,const Ts&... args) { cout << arg << " "; rd_debug(args...); }
#define pb push_back
#define PF(x) ((x) * (x))
#define LF(x) ((x) * PF(x))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const double eps = 1e-6;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3fll;
mt19937_64 mrand(random_device{}());
ll rnd(ll x) { return mrand() % x;}
template<int N>
struct Suffix_Automation{
	int len[N], fa[N], minr[N], ch[N][26], rt[N], tot, last, cnt[N];
	void clear(){
		tot = last = 1;
		memset(ch[1], 0, sizeof ch[1]);
	}
	Suffix_Automation(){
		clear();
	}
	void ins(const int& c, const int& pos = 0){
		int p = last, np = last = ++tot;
		minr[np] = len[np] = len[p] + 1;
		cnt[np]++;
		memset(ch[np], 0, sizeof ch[np]);
		for(; p && !ch[p][c]; p = fa[p]){
			ch[p][c] = np;
		}
		if(!p){
			return void(fa[np] = 1);
		}
		int q = ch[p][c];
		if(len[p] + 1 == len[q]){
			return void(fa[np] = q);
		}
		int nq = ++tot;
		len[nq] = len[p] + 1;
		minr[nq] = minr[q];
		fa[nq] = fa[q];
		memcpy(ch[nq], ch[q], sizeof ch[q]);
		fa[np] = fa[q] = nq;
		for(; p && ch[p][c] == q; p = fa[p]){
			ch[p][c] = nq; 
		}
	}
};
Suffix_Automation<2000005> sam;
int c[2000005], rk[2000005];
char S[1000005];
int n;
void solve(){
	cin >> n;
	cin >> (S + 1);
//	Shai();
	sam.clear();
	for(int i = 1; i <= n; i++){
		sam.ins(S[i]-'a');
	}
	for(int i = 1; i <= sam.tot; i++) ++c[sam.len[i]];
	for(int i = 1; i <= n; i++) c[i] += c[i-1];
	for(int i = 1; i <= sam.tot; i++) rk[--c[sam.len[i]]] = i;
	for(int i = sam.tot; --i; ){
		sam.cnt[sam.fa[rk[i]]] += sam.cnt[rk[i]];
	}
	ll ans = 0;
	for(int i = 2; i <= sam.tot; i++){
		for(int j = sam.len[sam.fa[i]] + 1; j <= sam.len[i] && j <= sam.cnt[i]; j++){
			if(sam.cnt[i] % j == 0){
				ans += sam.cnt[i];
			}
		}
	}
	cout << ans << "\n";
}
int main() {
  fastIO();
  solve();

  return 0;
}