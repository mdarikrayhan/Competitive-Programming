#include<bits/stdc++.h> 
using namespace std;

#define int long long int
#define ll long long 
#define lli long long int
#define ull unsigned long long
#define endl '\n'

#define debug(x) cout << #x << " : " << x << endl

const int MOD = 1e9 + 7;
const int INF = 1e18; 

// Code   
void Solve(){
	int n;
	cin>>n;

	if(n < 6) n = 6;
	if(n & 1) ++n;

	n /= 2;
	n *= 5;

	cout << n << endl;
	return;
}

int32_t main(){
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);

	#ifndef ONLINE_JUDGE
  		freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif

	int t = 1;
	cin>>t; 

	while(t--){
		Solve();
	}
	
	return 0;
}