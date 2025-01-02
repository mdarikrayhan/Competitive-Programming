#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for(int i = 0; i < (n); ++i)
#define rFor(i, n) for(int i = (n - 1); i >= 0; i--)
#define FoR(i, st, ed) for(int i = (st); i < (ed); ++i)
#define rFoR(i, st, ed) for(int i = (ed) - 1; i >= (st); --i)
#define FOR(i, st, ed) for(int i = (st); i <= (ed); ++i)
#define rFOR(i, st, ed) for(int i = (ed); i >= (st); --i)
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(a) a.begin(),a.end()
using i64 = long long;
const int INF  = 1e9+7;
const int MAX = 1e5;
const int mod  = 1e9+7;
const double eps = 0.001;
//--------------------------------------------
vector<vector<int> > chose = {{0},{0,1},{0,1,2},{0,3},{0,3,7},{0,4},{0,4,9},{0,4,9,14},{0,4,9,14,18},{1},{1,2},{1,4},{1,4,8},{1,4,8,12},{1,5},{1,5,10},{1,5,10,15},{2},{2,5},{2,5,9},{2,5,9,13},{2,5,9,13,16},{2,6},{2,6,11},{3},{3,4},{3,4,5},{3,4,5,6},{3,7},{3,8},{3,8,13},{3,8,13,17},{4},{4,5},{4,5,6},{4,8},{4,8,12},{4,9},{4,9,14},{4,9,14,18},{5},{5,6},{5,9},{5,9,13},{5,9,13,16},{5,10},{5,10,15},{6},{6,10},{6,10,14},{6,10,14,17},{6,11},{7},{7,8},{7,8,9},{7,8,9,10},{7,8,9,10,11},{7,12},{7,12,16},{8},{8,9},{8,9,10},{8,9,10,11},{8,12},{8,13},{8,13,17},{9},{9,10},{9,10,11},{9,13},{9,13,16},{9,14},{9,14,18},{10},{10,11},{10,14},{10,14,17},{10,15},{11},{11,15},{11,15,18},{12},{12,13},{12,13,14},{12,13,14,15},{12,16},{13},{13,14},{13,14,15},{13,16},{13,17},{14},{14,15},{14,17},{14,18},{15},{15,18},{16},{16,17},{16,17,18},{17},{17,18},{18}};
void solve() {
	vector<string> s(5);
	For(i, 5) getline(cin,s[i]);
	int ed = 0;
	int cnt = 0;
	For(i, 5){
		for(char j : s[i]){
			if(j == '.') cnt ++;
			else if(j == 'O') ed += 1 << cnt, cnt++;
		}
	}	
	// cerr << ed << "\n";
	vector<bool> dp(1 << 19);
	dp[0] = 0;
	For(u, 1 << 19){
		if(dp[u] == 0){
			For(i, chose.size()){
				bool f = 1;
				int v = u;
				for(int j : chose[i]){
					if(u & (1 << j)) f = 0;
					v |= 1 << j;
				}
				if(f) dp[v] = 1;
			}
		}
	}
	cout << (dp[ed] ? "Karlsson\n" : "Lillebror\n");
}

int main() {
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);

	int t = 1;
	//cin >> t;
	while (t--)solve();
	return 0;
}
/*
*/