#include <bits/stdc++.h>

#define debug(...) fprintf(stderr ,__VA_ARGS__)
#define __FILE(x)\
	freopen(#x".in" ,"r" ,stdin);\
	freopen(#x".out" ,"w" ,stdout)
#define LL long long

const int MX = 1e5 + 23;
const LL MOD = 998244353;

int read(){
	char k = getchar(); int x = 0;
	while(k < '0' || k > '9') k = getchar();
	while(k >= '0' && k <= '9') x = x * 10 + k - '0' ,k = getchar();
	return x;
}

int a[MX];
void solve(){
	int n = read() ,l = read() ,r = read();
	int ok = 1;
	for(int i = 1 ; i <= n ; ++i){
		a[i] = ((l - 1) / i + 1) * i;
		ok = ok && a[i] <= r;
	}
	if(ok){
		puts("YES");
		for(int i = 1 ; i <= n ; ++i)
			printf("%d%c" ,a[i] ," \n"[i == n]);
	}
	else puts("NO");
}

int main(){
	int T = read();
	for(int i = 1 ; i <= T ; ++i){
		solve();
	}
	return 0;
}