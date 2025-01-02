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
void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	For(i, n) cin >> a[i];

	vector<vector<vector<int> > > dp(n, vector<vector<int> > (26, vector<int>(26, INF)));
	vector<vector<vector<pii> > > rec(n, vector<vector<pii> > (26, vector<pii>(26)));
	int lstx, lsty, lstdp;
	For(i, n){
		For(x, 26){
			For(y, 26){
				if(x == y) dp[i][x][y] = INF;
				else if(!i) dp[i][x][y] = m;
				else if(lstx != x && lsty != y) dp[i][x][y] = lstdp + m, rec[i][x][y] = {lstx, lsty};
				else{//其实可以进一步优化26
					For(lx, 26){
						For(ly, 26){
							if(lx != x && ly != y)
								if(dp[i - 1][lx][ly] + m < dp[i][x][y])
									dp[i][x][y] = dp[i - 1][lx][ly] + m, rec[i][x][y] = {lx, ly};
						}
					}
				}	
			}
		}
		For(j, m){
			if(!(j % 2))
				For(y, 26) -- dp[i][a[i][j] - 'a'][y];
			else
				For(x, 26) -- dp[i][x][a[i][j] - 'a'];
		}
		lstdp = INF;
		For(x, 26){
			For(y, 26)
				if(lstdp > dp[i][x][y])
					lstx = x, lsty = y, lstdp = dp[i][x][y];
		}
	}
	// For(i, n){
	// 	For(x, 26){
	// 		For(y, 26){
	// 			cerr << dp[i][x][y] << " \n"[y == 25];
	// 		}
	// 	}
	// 	cerr << "\n";
	// }
	function<void(int, int, int)> print = [&](int i, int x, int y){
		if(i) print(i - 1, rec[i][x][y].first, rec[i][x][y].second);
		For(k, m) cout << (k % 2 == 0 ? char(x + 'a') : char(y + 'a'));
		cout << "\n";
	};

	cout << dp[n - 1][lstx][lsty] << "\n";
	print(n - 1, lstx, lsty);
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