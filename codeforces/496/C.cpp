#include <bits/stdtr1c++.h>

using namespace std;

typedef pair<int, int> pii;
int n, m;
char a[1005][1005];
bool good[1005];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	int ans = 0;
	for (int j = 0; j < m; j++) {
		bool remove = false;
		set<char> s;
		for (int i = 0; i < n; i++) {
			if (i+1 < n && a[i][j] > a[i+1][j] && !good[i]) remove = true;
			s.insert(a[i][j]);
		}
		ans += remove;
		if (!remove) {
			for (int i = 0; i < n; i++) {
				if (i+1 < n && a[i][j] < a[i+1][j]) good[i] = true;
			}
		}
	}
	cout << ans << endl;
	return 0;
}