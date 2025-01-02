 #include <bits/stdc++.h>
using namespace std;
#define lli long long int  

const int maxn = 7e1 + 5;
const int mod = 998244353;

int n, dp[maxn][maxn][maxn];

string s[maxn];

queue <tuple <int, int, int>> q;

pair <int, int> par[maxn][maxn][maxn];

void pp(int a, int b, int c){
   if (par[a][b][c].first != -1){
      if (par[a][b][c].first == 0){
         cout << a + 1 << ' ' << par[a][b][c].second + 1 << '\n';
         pp(par[a][b][c].second, b, c);
      }
      if (par[a][b][c].first == 1){
         cout << b + 1 << ' ' << par[a][b][c].second + 1 << '\n';
         pp(a, par[a][b][c].second, c);
      }
      if (par[a][b][c].first == 2){
         cout << c + 1 << ' ' << par[a][b][c].second + 1 << '\n';
         pp(a, b, par[a][b][c].second);
      }
   }
}

int main (){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	a--;
	b--;
	c--;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				dp[i][j][k] = 1e9;
				par[i][j][k] = {-1, -1};
			}
		}
	}
	q.push({0, 1, 2});
	q.push({0, 2, 1});
	q.push({1, 0, 2});
	q.push({1, 2, 0});
	q.push({2, 1, 0});
	q.push({2, 0, 1});
	dp[0][1][2] = 0;
	dp[0][2][1] = 0;
	dp[1][0][2] = 0;
	dp[1][2][0] = 0;
	dp[2][0][1] = 0;
	dp[2][1][0] = 0;
	while (q.size()){
		auto [x, y, z] = q.front();
		q.pop();
		for (int i = 0; i < n; i++){
			if ((i != y) && (i != x) && (i != z) && (s[i][x] == s[y][z]) && (dp[i][y][z] == 1e9)){
				dp[i][y][z] = dp[x][y][z] + 1;
				q.push({i, y, z});
				par[i][y][z] = {0, x};
			}
		}
		for (int i = 0; i < n; i++){
			if ((i != y) && (i != x) && (i != z) && (s[i][y] == s[x][z]) && (dp[x][i][z] == 1e9)){
				dp[x][i][z] = dp[x][y][z] + 1;
				q.push({x, i, z});
				par[x][i][z] = {1, y};
			}
		}
		for (int i = 0; i < n; i++){
			if ((i != y) && (i != x) && (i != z) && (s[i][z] == s[y][x]) && (dp[x][y][i] == 1e9)){
				dp[x][y][i] = dp[x][y][z] + 1;
				q.push({x, y, i});
				par[x][y][i] = {2, z};
			}
		}
	}
	int mn = 1e9;
	mn = min(mn, dp[a][b][c]);
	mn = min(mn, dp[a][c][b]);
	mn = min(mn, dp[b][a][c]);
	mn = min(mn, dp[b][c][a]);
	mn = min(mn, dp[c][b][a]);
	mn = min(mn, dp[c][a][b]);
	if (mn == 1e9)cout << -1;
	else {
	   cout << mn << '\n';
	   if (mn == dp[a][b][c])pp(a, b, c);
	   else if (mn == dp[a][c][b])pp(a, c, b);
	   else if (mn == dp[b][a][c])pp(b, a, c);
	   else if (mn == dp[b][c][a])pp(b, c, a);
	   else if (mn == dp[c][c][b])pp(c, a, b);
	   else if (mn == dp[c][b][a])pp(c, b, a);
	}
}