#include <iostream>
#include <vector>
#include <queue>
#define maxn 80
using namespace std;

int n;
string s;

int dp[maxn][maxn][maxn][2];
vector<int> V, K, X;

int count_remaining(const vector<int>& VX, int from, int where) {
	int cnt = 0;
	for (int i = from; i < VX.size() && VX[i] < where; i++) {
		cnt++;
	}
	return cnt;
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'V') {
			V.push_back(i);
		} else if (s[i] == 'K') {
			K.push_back(i);
		} else {
			X.push_back(i);
		}
	}

	for (int i = 0; i <= V.size(); i++) {
		for (int j = 0; j <= K.size(); j++) {
			for (int x = 0; x <= X.size(); x++) {
				for (int type = 0; type < 2; type++) {
					dp[i][j][x][type] = 1e9;
				}
			}
		}
	}

	dp[0][0][0][0] = 0;
	for (int v = 0; v <= V.size(); v++) {
		for (int k = 0; k <= K.size(); k++) {
			for (int x = 0; x <= X.size(); x++) {
				for (int type = 0; type < 2; type++) {
					auto moving_cost = [&](int where) {
						return count_remaining(V, v, where) + count_remaining(K, k, where) + count_remaining(X, x, where);
					};

					if (v < V.size()) {
						dp[v + 1][k][x][1] = min(dp[v + 1][k][x][1], dp[v][k][x][type] + moving_cost(V[v]));
					}

					if (k < K.size() && (type == 0)) {
						dp[v][k + 1][x][0] = min(dp[v][k + 1][x][0], dp[v][k][x][type] + moving_cost(K[k]));
					}

					if (x < X.size()) {
						dp[v][k][x + 1][0] = min(dp[v][k][x + 1][0], dp[v][k][x][type] + moving_cost(X[x]));
					}
				}
			}
		}
	}

	int ans = 1e9;
	for (int type = 0; type < 2; type++) {
		ans = min(ans, dp[V.size()][K.size()][X.size()][type]);
	}

	cout << ans << endl;
}