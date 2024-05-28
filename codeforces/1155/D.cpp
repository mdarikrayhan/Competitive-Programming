#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const ma = 3e5;
ll dp[ma][3][3], v[ma], n, x; 

ll calc(ll ind, ll m, ll p){
	if(ind < 0) 			return 0;
	if(dp[ind][m][p] != -1) return dp[ind][m][p];
	ll re = 0, at = (m == 1) ? x * v[ind] : v[ind];
	if(p % 2){
		re = at;	// peguei só esse (kadane)
		for(ll i = 0; i <= m; i++) // peguei o item anterior e esse
			re = max(re, at + calc(ind - 1, i, 1));
	}else{
		for(ll i = 0; i <= m; i++) // se já acabou posso pegar o maximo do anterior
			re = max(re, calc(ind - 1, i, 1));
		for(ll i = 0; i <= m; i++) // com ou sem o anterior
			re = max(re, calc(ind - 1, i, 2));
	}
	return dp[ind][m][p] = re; 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> x;
	for(ll i = 0; i < n; i++){
		cin >> v[i];
		for(ll k = 0; k < 3; k++)
			for(ll j = 0; j < 3; j++)
				dp[i][k][j] = -1;
	}
	ll re = 0;
	for(ll i = 0; i < n; i++)
		for(ll j = 0; j < 3; j++)
			for(ll k = 1; k < 3; k++)
				re = max(re, calc(i, j, k));
	cout << re << "\n";
}