#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef LOCAL
#include<debug.h>
#include<writeout.h>
#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
#define debug(...) 28
#define write_output(...) 03
#define eprintf(...) 2003
#endif

template<typename T> void print_impl(const T& arg) { std::cout << arg; }
template<typename T, typename... Args> void print_impl(const T& arg, const Args&... rest) { std::cout << arg << ' '; print_impl(rest...); }
template<typename... Args> 
void print(const Args&... args) { 
	print_impl(args...); 	
#ifdef LOCAL
	std::cout << std::endl; 
#else
	std::cout << '\n';
#endif
}

const int mod = 1e9 + 7;

int add(int x, int y){
	x += y;
	if(x >= mod) x -= mod;
	return x;
}

int mul(int x, int y){
	ll res = 1ll * x * y;
	res %= mod;
	return res;
}

int dp[80][1 << 20];
int b[80];

void solve(){
	int n;
	cin >> n;

	string s;
	cin >> s;

	for(int i = 1; i <= n; ++i)
		b[i] = s[i - 1] == '1';

	dp[0][0] = 1;
	int res = 0;
	for(int i = 1; i <= n; ++i){
		int cur = b[i];
		dp[i][0] = 1;
		for(int j = i - 1; j >= 0; --j){
			for(int mask = 0; mask < (1 << 20); ++mask){
				if(cur)
					dp[i][mask | (1 << cur - 1)] = add(dp[i][mask | (1 << cur - 1)], dp[j][mask]);
			}
			if(b[j] && i - j > 7) break;
			if(j > 0 && b[j]){
				cur += 1 << i - j;
			}
			if(cur > 20) break;
		}
			
		int x = 0;
		for(int mask = 0; mask < 20; ++mask){
			x |= 1 << mask;
			res = add(res, dp[i][x]);	
		}
	}
	print(res);
}

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
#ifdef LOCAL
	freopen("out.txt", "w", stdout);
#endif

	int test = 1;
	//cin >> test;

	for(int itest = 1; itest <= test; ++itest){
		eprintf("------- Case %d -------\n", itest);
		solve();
		eprintf("----------------------\n");
	}
	write_output();	

	return 0;
}



