#include <bits/stdc++.h>
using namespace std;
#define Go  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define ll long long
// =========================================================================================

void Burn_The_Problem_Alive() {
	int n; cin >> n; 
	int m; cin >> m; 

	vector<string> v(n + 1); 
	queue<pair<int, int>> q; 

	for (int i = 1; i <= n; i++) {
		cin >> v[i]; v[i] = '#' + v[i]; 
		for (int j = 1; j <= m; j++) {
			if (v[i][j] == '.') q.push({ i, j });
		}
	}

	function<void(int, int, int, int)>fun = [&](int x1, int y1, int x2, int y2) {
			if (x1<1 || y1 < 1 || x2 > n || y2 > m)return;
			vector<pair<int, int>> c;
			for (int i = x1; i <= x2; i++) {
				for (int j = y1; j <= y2; j++) {
					if (v[i][j] == '*')c.push_back({ i, j });
				}
			}
			if (c.size() == 1) {
				v[c[0].first][c[0].second] = '.'; 
				q.push({ c[0].first, c[0].second });
			}
		};
    
	while (!q.empty()) {
		auto u = q.front(); 
		q.pop(); 

		int x = u.first, y = u.second; 

		fun(x - 1, y, x, y + 1); 
		fun(x, y, x + 1, y + 1);

		fun(x, y - 1, x + 1, y);
		fun(x - 1, y - 1, x, y);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)cout << v[i][j];  
		cout << endl;
	}
}

// =========================================================================================

int32_t main() {
	Go;
	int TES = 1;        //       cin >> TES;
	while (TES--)Burn_The_Problem_Alive();

	return 0;
}