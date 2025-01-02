#include <bits/stdc++.h>
using namespace std;
#define SIDE1 cc[3][0]
#define SIDE2 cc[0][3]
const int N = 1005;
int h, w;
char sl[N];
bool allow[N][N];
int cc_cnt, cc[N][N]; // which connected component
set<pair<int,int>> edges; // pairs of almost connected CC's

// find & union
namespace FU {
	int group[N*N];
	vector<int> inv[N*N];
	set<int> affected;
	void init(int i) {
		if(affected.count(i)) return;
		affected.insert(i);
		group[i] = i;
		inv[i].push_back(i);
	}
	void uni(int a, int b) {
		init(a), init(b);
		a = group[a], b = group[b];
		if(a == b) return;
		for(int x : inv[a]) {
			group[x] = b;
			inv[b].push_back(x);
		}
		inv[a].clear();
	}
	bool areConnected(int a, int b) {
		init(a), init(b);
		return group[a] == group[b];
	}
	void clear() {
		for(int i : affected) {
			group[i] = 0;
			inv[i].clear();
		}
		affected.clear();
	}
	bool almostConnectedPair() {
		init(SIDE1), init(SIDE2);
		for(int x : affected) if(areConnected(SIDE1, x))
			for(int y : affected) if(areConnected(SIDE2, y))
				if(edges.count({x, y}))
					return true;
		return false;
	}
}

bool inRange(int row, int col) {
	return 0 <= row && row <= h + 1 && 0 <= col && col <= w + 1;
}
bool duality(vector<pair<int,int>> snow) {
	FU :: clear();
	for(pair<int,int> p : snow) {
		int row = p.first, col = p.second;
		cc[row][col] = ++cc_cnt;
		for(int r2 = row - 1; r2 <= row + 1; ++r2)
			for(int c2 = col - 1; c2 <= col + 1; ++c2)
				if(cc[r2][c2])
					FU :: uni(cc[r2][c2], cc[row][col]);
	}
	if(FU :: almostConnectedPair())
		return true;
	for(pair<int,int> p : snow) {
		int row = p.first, col = p.second;
		for(int r2 = row - 2; r2 <= row + 2; ++r2)
			for(int c2 = col - 2; c2 <= col + 2; ++c2)
				if(inRange(r2, c2) && cc[r2][c2]) {
					if(FU :: areConnected(cc[row][col], SIDE1)
							&& FU :: areConnected(cc[r2][c2], SIDE2))
						return true;
					if(FU :: areConnected(cc[row][col], SIDE2)
							&& FU :: areConnected(cc[r2][c2], SIDE1))
						return true;
				}
	}
	
	return false;
}
void dfs(int row, int col) {
	for(int r2 = row - 1; r2 <= row + 1; ++r2)
		for(int c2 = col - 1; c2 <= col + 1; ++c2)
			if(inRange(r2, c2) && allow[r2][c2] && !cc[r2][c2]) {
				cc[r2][c2] = cc[row][col];
				dfs(r2, c2);
			}
}
int main() {
	int q;
	scanf("%d%d%d", &h, &w, &q);
	for(int row = 0; row < h; ++row) {
		scanf("%s", sl);
		for(int col = 0; col < w; ++col)
			allow[row+1][col+1] = (sl[col] == '#');
	}
	for(int row = 3; row <= h + 1; ++row)
		allow[row][0] = true;
	for(int col = 1; col <= w - 2; ++col)
		allow[h+1][col] = true;
	
	for(int col = 3; col <= w + 1; ++col)
		allow[0][col] = true;
	for(int row = 1; row <= h - 2; ++row)
		allow[row][w+1] = true;
	
	for(int row = 0; row <= h + 1; ++row)	
		for(int col = 0; col <= w + 1; ++col)
			if(allow[row][col] && !cc[row][col]) {
				cc[row][col] = ++cc_cnt;
				dfs(row, col);
			}
	
	for(int row = 0; row <= h + 1; ++row)
		for(int col = 0; col <= w + 1; ++col)
			if(cc[row][col])
				for(int r2 = row - 2; r2 <= row + 2; ++r2)
					for(int c2 = col - 2; c2 <= col + 2; ++c2)
						if(inRange(r2, c2) && cc[r2][c2]
								&& cc[row][col] != cc[r2][c2])
							edges.insert({cc[row][col], cc[r2][c2]});
	
	assert(SIDE1 != SIDE2);
	
	assert(!duality(vector<pair<int,int>>{}));
	
	while(q--) {
		int k;
		scanf("%d", &k);
		vector<pair<int,int>> snow(k);
		for(pair<int,int> & p : snow)
			scanf("%d%d", &p.first, &p.second);
		puts(duality(snow) ? "NO" : "YES");
		fflush(stdout);
		// clear
		for(pair<int,int> p : snow)
			cc[p.first][p.second] = 0;
		cc_cnt -= snow.size();
	}
}