#include<bits/stdc++.h>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#define YES puts("YES")
#define Yes puts("Yes")
#define NO puts("NO")
#define No puts("No")
#define b_i __int128
#define ll long long
#define ull unsigned long long
#define x first
#define y second
#define pr pair
#define dl double
#define pll pr<ll, ll>
#define pii pr<int, int>
#define pdd pr<dl, dl>
#define ld long dl
#define vc vector
#define vci vc<int>
#define vcl vc<ll>
#define vcd vc<dl>
#define vcs vc<string>
#define vcp vc<pii >
#define ps push
#define pp pop
#define frt front
#define bck back
#define psf push_front
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define bgn begin
using namespace std;
const ll md = 998244353;
const ll mod = 1e9 + 7;
const dl esp = 1e-12;
const int inf = 2e9;
const ll INF = 2e18;
inline int read(){
	char c = getchar();
	int ans = 0, cnt = 1;
	while(c < '0' || c > '9'){
		if(c == '-') cnt = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		ans *= 10;
		ans += (c - '0');
		c = getchar();
	}
	return ans * cnt;
}
inline void write(int x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
ll ksm(ll a, ll b, ll md){
	ll ans = 1;
	while(b){
		if(b % 2) ans = ans * a % md;
		a = a * a % md;
		b /= 2;
	}
	return ans;
}
int rnd(int l, int r){
	return l + rand() % (r - l + 1);
}
int n, id1, id2;
vci vis[10000005], is;
ll ans = 2e18;
signed main(){
	//ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
	srand(time(0));
	cin >> n;
	for(int i = 1, a; i <= n; i++) a = read(), vis[a].psb(i);
	for(int i = 1; i <= 10000000; i++){
		is.clear();
		int k = 2;
//		cout << i << endl;
		for(int j = 1; j <= 10000000 / i && k > 0; j++)
			if(vis[i * j].size()){
				k -= vis[i * j].size();
				is.psb(j);
			}
		if(k > 0) continue;
//		if(n > 100) cout << k << endl;
//		cout << k << ' ' << ans << ' ' << is[0] * is[1] * i << ' ' << id1 << ' ' << id2 << endl;
		if(is.size() == 1){
			if((ll)is[0] * is[0] * i < ans) ans = (ll)is[0] * is[0] * i, id1 = vis[i * is[0]][0], id2 = vis[i * is[0]][1];
		}
		else{
			if((ll)is[0] * is[1] * i < ans) ans = (ll)is[0] * is[1] * i, id1 = vis[i * is[0]][0], id2 = vis[i * is[1]][0];
		}
	}
	cout << min(id1, id2) << ' ' << max(id1, id2);
	return 0;
}
 			 				 		   	      	 					