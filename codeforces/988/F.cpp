// Problem: F. Rain and Umbrellas
// Contest: Codeforces - Codeforces Round 486 (Div. 3)
// Created: 2024-05-21 23:12:15
// 
// Powered by CP Editor

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int a, n, m;
	const ll INF = 1e18;
	cin >> a >> n >> m;
	vector<array<int,2>> v(2*n);
	for(int i=0; i<n; i++){
	    int l, r;
	    cin >> l >> r;
	    v[2*i] = {l, 0};
	    v[2*i+1] = {r, 1};
	}
	sort(v.begin(), v.end());
	vector<array<int,2>> umb(m+1);
	for(int i=0; i<m; i++){
	    cin >> umb[i][0] >> umb[i][1];
	}
	umb[m][0] = a;
	sort(umb.begin(), umb.end());
	vector<ll> dp(m+1, INF);
	for(int i=0; i<=m; i++){
	    if(umb[i][0] <= v[0][0]){
	        dp[i] = 0;
	        continue;
	    }
	    auto it = prev(lower_bound(v.begin(), v.end(), array{umb[i][0], -1}));
	    for(int j=0; j<i; j++){
	        if((*it)[1] == 0){
	            assert((*next(it))[1] == 1);
	            dp[i] = min(dp[i], dp[j] + 1ll * (umb[i][0] - umb[j][0]) * umb[j][1]);
	        }
	        else if((*it)[0] <= umb[j][0]){
	            dp[i] = min(dp[i], dp[j]);
	        }
	        else{
	            dp[i] = min(dp[i], dp[j] + 1ll * ((*it)[0] - umb[j][0]) * umb[j][1]);
	        }
	    }
	}
	if(dp[m] == INF){
	    cout << -1;
	}
	else{
	    cout << dp[m];
	}
}