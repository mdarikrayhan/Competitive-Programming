#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
#define sp " "
#define el '\n'
#define FAST_IO cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pi pair<int,int>
#define ss second
#define ff first
#define all(v) v.begin(),v.end()
#define ld double
#define prntv(vec) for(auto i : vec) cout << i << " "
#define memo(m, v) memset(m, v, sizeof(m))
#define pb push_back
#define sz(v) (ll)v.size()
#define ceil_i(a, b) (((ll)(a)+(ll)(b-1))/(ll)(b))
#define floor_i(a, b) (a/b)
using namespace std;
const int MOD = 1e9 + 7;
const int oo = 1e18;
const long long OO = 0x3f3f3f3f;
string yes = "YES", no = "NO";
int dx_all[8] = {1, 0, -1, 0, 1, 1, -1, -1},
				dy_all[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int dx[4] = {0, 1, -1, 0},
				dy[4] = {1, 0, 0, -1};
const int N =  2e5 + 10;
const int M = 21;



/*
<--------------------CODE GOES FROM HERE --------------------->
*/

void S(int T = 0){
		int n , k; cin >> n >> k;
		vector <int> v(n + 1);
		for(int i = 1; i <= n; i++){
				cin >> v[i];
		}
		int ii = 0 , ans;
		for(int i = 1 ; i <= k ; i++){
				ii = 1;
				for(int j = 1 ; j <= n - 1 ; j++){
						if(v[j] >= v[j + 1]) ii = j + 1;
						else {
								v[j]++;
								break;
						}
				}
				ans = ii;
				if(ii == n) break;
		}
		if(ans == n) cout << -1 << el;
		else cout << ans << el;
}
signed main(){
		FAST_IO
		int TESTCASES = 1;
		cin >> TESTCASES;
		while(TESTCASES--){
				S(TESTCASES);
		}
}