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
const int N =  3e5 + 10;
const int M = 21;



/*
<--------------------CODE GOES FROM HERE --------------------->
*/
void S(int T = 0) {
		int n , k; cin >> n >> k;
		vector<int>v(n);
		map <int,int>rank;
		map<int,int>mp;
		int cnt = 0;
		for(int i = 0 ; i < n ; i++){
				cin >> v[i];
				rank[v[i]]++;
		}
		while(rank[k] != n){
				for(int i = k - 1 ; i > 0 ; i--){
						if(rank[i]){
								rank[i]--;
								rank[i + 1]++;
						}
				}
				cnt++;
		}
		//
		cout << cnt << '\n';
}
signed main(){
		FAST_IO
		int TESTCASES = 1;
	//	cin >> TESTCASES;
		while(TESTCASES--){
				S(TESTCASES);
		}
}