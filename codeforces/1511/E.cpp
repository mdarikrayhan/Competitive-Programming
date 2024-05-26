#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 10, mod = 998244353;

int ksm (int a, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}

string s[N];

int n, m, cnt, f[N], ans;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i ) cin >> s[i], s[i] = " " + s[i];
    for (int i = 1; i <= n; ++ i )
        for (int j = 1; j <= m; ++ j )
            cnt += s[i][j] == 'o';
    
    f[2] = f[3] = 1;
    for (int i = 4; i <= cnt; ++ i ) f[i] = (f[i - 2] + ksm (2, i - 3)) % mod;
    for (int i = 2; i <= cnt; ++ i ) f[i] = f[i] * ksm (2, cnt - i) % mod;
    int at;
    for (int i = 1; i <= n; ++ i ) {
    	at = 0;
    	for (int j = 1; j <= m; ++ j ) {
    		at = at * (s[i][j] == 'o') + (s[i][j] == 'o');
    		ans = (ans + f[at]) % mod;
		}
	}
    for (int j = 1; j <= m; ++ j ) {
    	at = 0;
    	for (int i = 1; i <= n; ++ i ) {
    		at = at * (s[i][j] == 'o') + (s[i][j] == 'o');
    		ans = (ans + f[at]) % mod;
		}
	}   
	cout << ans << endl;
	return 0;
}

 			 	 	 	  	  	 				 	 			  		