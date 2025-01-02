#include <bits/stdc++.h>
using namespace std;

const int N = 3000;
int n, m, k, start, finish;
char s[100][100];
string d[N], ans, str;
bool mark[200], is_in_que[N];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

void output() {
	if (ans == str) 
		cout << -1;
	else 
		for (int i = 1; i < ans.size() - 1; i++) 
			cout << ans[i];
	exit(0);
}

bool is_smaller(string &s1, string &s2) {
	if (s1.size() != s2.size()) 
		return (s1.size() < s2.size());
	return (s1 < s2);
}

bool is_valid(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && mark[s[x][y]];
}

void check_paths() {
	queue<int> q;
	for (int i = 0; i <= m * n; i++) 
		d[i] = str, is_in_que[i] = false;
	q.push(start), d[start] = "S";
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		int x = u / m, y = u % m;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (is_valid(xx, yy)) {
				string ss = d[u] + s[xx][yy];
				if (is_smaller(ss, d[(xx * m) + yy])) {
					d[(xx * m) + yy] = ss;
					if (!is_in_que[(xx * m) + yy])
						q.push((xx * m) + yy), is_in_que[(xx * m) + yy] = true;
				}
			}
		}
	}
	if (is_smaller(d[finish], ans)) 
		ans = d[finish];
}

void back_track(int i, int j) {
	if (i == k) {
		check_paths();
		return;
	}
	if ((double)clock() / CLOCKS_PER_SEC >= 2.2) 
	    output();
	for (char s1 = (char)j + 1; s1 <= 'z'; s1++) {
		mark[s1] = true;
		back_track(i + 1, s1);
		mark[s1] = false;
	}
}

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
			if (s[i][j] == 'S') 
				start = (m * i) + j;
			else if (s[i][j] == 'T')
				finish = (m * i) + j;
		}
}

void solve() {
    mark['S'] = mark['T'] = true;
	while (str.size() <= 100) 
		str += 'z';
	ans = str;
	if (k == 4) {
    	mark['x'] = mark['y'] = mark['z'] = mark['a'] = true;
    	check_paths();
    	mark['x'] = mark['y'] = mark['z'] = mark['a'] = false;
	}
	back_track(0, 'a' - 1);
	output();
}

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	input(), solve();
	return 0;
}