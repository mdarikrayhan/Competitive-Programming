#include<bits/stdc++.h>
using namespace std;

const int N = 10 + 1;
int n, matrix[N][N];
pair <int, int> dp[N][N][3][N * N];
bool mark[N][N][3][N * N];
pair <int, int> ans[N][N][3];
void read();
void bfs();
void out();
void solve();
void night_q_push(int a, int b, int c, int d, int e);
void rool_q_push(int a, int b, int c, int d, int e);
void bishop_q_push(int a, int b, int c, int d, int e);
multiset <tuple <int, int, int, int, int, int> > q;
//                  dp.first, dp.sec, state, y, x
// 0 : rook
// 1 : night 
// 2 : bishop
int main() {
	read();
	solve();
}

void read() {
	cin >> n;
	for (int t = 0; t < n; t++) 
		for (int i = 0; i < n; i++)
			cin >> matrix[t][i];
	
}

bool is_valid(int y, int x, int state, int num) {
	if (mark[y][x][state][num])
		return 0;
	if (y < 0 || y > n - 1 || x < 0 || x > n - 1)
		return 0;
	return 1;
}


void bishop_q_push(int a, int b, int y, int x, int num) {
	if (is_valid(y, x, 2, num))
		q.insert(make_tuple(a, b, 2, y, x, num));
	int yy = y, xx = x;
	while (yy < n && xx < n) {
		if (is_valid(yy, xx, 2, num))
			q.insert(make_tuple(a + 1, b, 2, yy, xx, num));
		xx++;
		yy++;
	}
	yy = y, xx = x;
	while (yy > -1 && xx > -1) {
		if (is_valid(yy, xx, 2, num))
			q.insert(make_tuple(a + 1, b, 2, yy, xx, num));
		yy--;
		xx--;
	}
	yy = y, xx = x;
	while (yy > -1 && xx < n) {
		if (is_valid(yy, xx, 2, num))
			q.insert(make_tuple(a + 1, b, 2, yy, xx, num));
		yy--;
		xx++;
	}
	yy = y, xx = x;
	while (yy < n && xx > -1) {
		if (is_valid(yy, xx, 2, num))
			q.insert(make_tuple(a + 1, b, 2, yy, xx, num));
		yy++;
		xx--;
	}
}
void rook_q_push(int a, int b, int y, int x, int num) {
	if (a == 3 && b== 1 && y == 2 && x == 1)
//		cout << "YES\t" << num << ' ' << is_valid(y, 2, 0, num) << '\n';
	if (is_valid(y, x, 0, num))
		q.insert(make_tuple(a, b, 0, y, x, num));
	for (int t = 0; t < n; t++) 
		if (is_valid(y, t, 0, num))
			q.insert(make_tuple(a + 1, b, 0, y, t, num));
	for (int t = 0; t < n; t++) 
		if (is_valid(t, x, 0, num))
			q.insert(make_tuple(a + 1, b, 0, t, x, num));
}

void night_q_push(int a, int b, int y, int x, int num) {
	if (is_valid(y, x, 1, num))
		q.insert(make_tuple(a, b, 1, y, x, num));
	if (is_valid(y + 2, x + 1, 1, num)) 
		q.insert(make_tuple(a + 1, b, 1, y + 2, x + 1, num));
	if (is_valid(y + 2, x - 1, 1, num)) 
		q.insert(make_tuple(a + 1, b, 1, y + 2, x - 1, num));
	if (is_valid(y - 2, x + 1, 1, num)) 
		q.insert(make_tuple(a + 1, b, 1, y - 2, x + 1, num));
	if (is_valid(y - 2, x - 1, 1, num)) 
		q.insert(make_tuple(a + 1, b, 1, y - 2, x - 1, num));
	if (is_valid(y + 1, x + 2, 1, num)) 
		q.insert(make_tuple(a + 1, b, 1, y + 1, x + 2, num));
	if (is_valid(y - 1, x + 2, 1, num)) 
		q.insert(make_tuple(a + 1, b, 1, y - 1, x + 2, num));
	if (is_valid(y - 1, x - 2, 1, num)) 
		q.insert(make_tuple(a + 1, b, 1, y - 1, x - 2, num));
	if (is_valid(y + 1, x - 2, 1, num)) 
		q.insert(make_tuple(a + 1, b, 1, y + 1, x - 2, num));
}

void solve() {
	for (int t = 0; t < n; t++) {
		for (int i = 0; i < n; i++) {
			if (matrix[t][i] == 1) {
				q.insert(make_tuple(0, 0, 0, t, i, 2));
				q.insert(make_tuple(0, 0, 1, t, i, 2));
				q.insert(make_tuple(0, 0, 2, t, i, 2));
				dp[t][i][0][2] = {0, 0};
				dp[t][i][1][2] = {0, 0};
				dp[t][i][2][2] = {0, 0};
			}
		}
	}
	while (q.size()) {
		tuple <int, int, int, int, int, int> k = *q.begin();
		q.erase(q.begin(), ++q.begin());
		int a = get<0>(k), b = get<1>(k), state = get<2>(k), y = get<3>(k), x = get<4>(k), num = get<5>(k);
//			cout << "reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\t" << mark[y][x][0][5] << '\n';
		if (num == matrix[y][x] && !mark[y][x][state][num]) {
			mark[y][x][state][num] = 1;
			ans[y][x][state] = {a, b};
			q.insert(make_tuple(a, b, state, y, x, num + 1));			
			dp[y][x][state][num + 1] = {a, b}; 
//			cout << a << ' ' << b << ' ' << state << ' ' << y << ' ' << x << ' ' << num << ' ' << num + 1 << '\n';
		}
		else if (!mark[y][x][state][num] && num <= n * n) {	
//		cout << a << ' ' << b << ' ' << state << ' ' << y << ' ' << x << ' ' << num << '\n';
	
			dp[y][x][state][num] = {a, b};
			bool night = 1 - bool(state == 1), bishop = 1 - bool(state == 2), rook = 1 - bool(state == 0);
			night_q_push(a + night, b + night, y, x, num);
			bishop_q_push(a + bishop, b + bishop, y, x, num);
			rook_q_push(a + rook , b + rook, y, x, num);
		}
		mark[y][x][state][num] = 1;
//		cout << "here\n";
	}
	out();
}

void out() {
	for (int t = 0; t < n; t++) {
		for (int i = 0; i < n; i++) {
			if (matrix[t][i] == n * n) {
				vector <pair <int, int> > out_fuck;
				out_fuck.push_back(ans[t][i][0]);
				out_fuck.push_back(ans[t][i][1]);
				out_fuck.push_back(ans[t][i][2]);
//				cout << ans[t][i][0].first << ' ' << ans[t][i][0].second << '\n';
//				cout << ans[t][i][1].first << ' ' << ans[t][i][1].second << '\n';
//				cout << ans[t][i][2].first << ' ' << ans[t][i][2].second << '\n'; 
				sort(out_fuck.begin(), out_fuck.end());
				if (out_fuck[0].first != 0) {
					cout << out_fuck[0].first << ' ' << out_fuck[0].second;
				}
				else if (out_fuck[1].first != 0)
					cout << out_fuck[1].first << ' ' << out_fuck[1].second;
				else	
					cout << out_fuck[2].first << ' ' << out_fuck[2].second;
				
				return;
			}
		}
	}
}


















