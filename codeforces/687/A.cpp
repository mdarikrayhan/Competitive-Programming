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
const int N =  1e5 + 10;
const int M = 21;



/*
<--------------------CODE GOES FROM HERE --------------------->
*/
vector<int> adj[N];
int color[N];
bool BFS_Bipartite(int u){
		queue<int> q;
		q.push(u);
		color[u] = 1;
		while (!q.empty()){
				int curr = q.front();
				q.pop();
				for(auto v : adj[curr]){
						if(color[v] == 0)
						{
								color[v] = 3 - color[curr];
								q.push(v);
						}
						if(color[v] == color[curr])
								return 0;
				}
		}
		return 1;
}
void S(int T = 0) {
		int n , m; cin >> n >> m;;
		for(int i = 0 ; i < m ; i++){
				int u , v; cin >> u >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
		}
		for(int j = 1 ; j <= n ; j++){
				if(!color[j]){
						if(!BFS_Bipartite(j)){
								cout << -1;
								return;
						}
				}
		}
		vector <int> a , b;
		for(int i = 1 ; i <= n ; i++){
				if(color[i] == 1) a.push_back(i);
				else if(color[i] == 2) b.push_back(i);
		}
		cout << a.size() << el;
		for(int i = 0 ; i < a.size() ; i++){
				cout << a[i] << " ";
		}
		cout << el;
		cout << b.size() << el;
		for(int i = 0 ; i < b.size() ; i++){
				cout << b[i] << " ";
		}
}
signed main(){
		FAST_IO
		int TESTCASES = 1;
	//	cin >> TESTCASES;
		while(TESTCASES--){
				S(TESTCASES);
		}
}