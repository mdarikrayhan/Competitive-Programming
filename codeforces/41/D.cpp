#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n, m, mod, oo = 1e8; cin >> n >> m >> mod; mod++;
	vector<vector<ll>> g(n, vector<ll>(m));
	for(auto &i : g)
		for(ll &j : i){
			char c; cin >> c;
			j = (c - '0');
		}
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(mod, -oo)));
	for(ll j = 0; j < m; j++)
		dp[0][j][g[0][j] % mod] = g[0][j];
	for(ll i = 0; i < n - 1; i++)
		for(ll j = 0; j < m; j++)
			for(ll k = 0; k < mod; k++)
				if(dp[i][j][k] != -oo){
					if(j)
						dp[i + 1][j - 1][(k + g[i + 1][j - 1]) % mod] = max(dp[i + 1][j - 1][(k + g[i + 1][j - 1]) % mod], dp[i][j][k] + g[i + 1][j - 1]);
					if(j < m - 1)
						dp[i + 1][j + 1][(k + g[i + 1][j + 1]) % mod] = max(dp[i + 1][j + 1][(k + g[i + 1][j + 1]) % mod], dp[i][j][k] + g[i + 1][j + 1]);
				}
	array<ll, 2> co = {-1, -1}, def = co;
	for(ll j = 0; j < m; j++) if(dp[n - 1][j][0] > -oo)
		co = max(co, {dp[n - 1][j][0], j});
	if(co == def && cout << "-1\n")
		return 0;
	cout << co[0] << "\n" << co[1] + 1 << "\n";
	string re;
	ll l = n - 1, c = co[1], r = 0;
	while(l > 0){
		ll r1 = -oo, r2 = -oo; // l, r 
		r = (mod + r - (g[l][c] % mod)) % mod;
		if(c)
			r1 = dp[l - 1][c - 1][r];
		if(c < m - 1)
			r2 = dp[l - 1][c + 1][r];
		if(r1 > r2){
			re += 'L';
			c--;
		}else{
			re += 'R';
			c++;
		}
		l--;
	}
	cout << re << "\n";
}