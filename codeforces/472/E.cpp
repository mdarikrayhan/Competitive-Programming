#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef pair<int, int> PII;

int n, m, a, b;
int tmp[33][33];
int source[33][33];
int target[33][33];
PII prv[33][33];
bool block[33][33];
vector<PII> R;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void save(){
	FWD(i,0,n) FWD(j,0,m) tmp[i][j] = source[i][j];
}

void load(){
	R.clear();
	FWD(i,0,n) FWD(j,0,m) source[i][j] = tmp[i][j];
}

void check(){
	FWD(i,0,n) FWD(j,0,m) if(source[i][j] != target[i][j]) return;
	printf("%d\n", (int)R.size()-1);
	for(PII r : R) printf("%d %d\n", r.x+1, r.y+1);
	exit(0);
}

void make(int x, int y){
	swap(source[R.back().x][R.back().y], source[x][y]);
	R.push_back(PII(x,y));
	a = x; b = y;
}

bool in(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m && !block[x][y];
}

void path(int x, int y){
	FWD(i,0,n) FWD(j,0,m) prv[i][j] = PII(-1,-1);
	queue<PII> Q;
	Q.push(PII(a,b));
	PII c = PII(x, y);
	while(!Q.empty()){
		x = Q.front().x;
		y = Q.front().y;
		Q.pop();
		FWD(d,0,8){
			int nx = x+dx[d]; int ny = y+dy[d];
			if(in(nx, ny) && prv[nx][ny] == PII(-1,-1)){
				prv[nx][ny] = PII(x,y);
				Q.push(PII(nx, ny));
			}
		}
	}
	stack<PII> S;
	while(c != PII(a,b)){
		S.push(c);
		c = prv[c.x][c.y];
	}
	while(!S.empty()){
		make(S.top().x, S.top().y);
		S.pop();
	}
}

void setp(int i, int j){
	path(i, j);
	PII s = PII(i,j);
	block[i][j] = 1;
	FWD(p,0,n) FWD(q,0,m) if(!block[p][q] && source[p][q] == target[i][j]) s = PII(p,q);
	block[i][j] = 0;
	if(s == PII(i,j)){
		printf("-1\n");
		exit(0);
	}
	for(;;){
		path(s.x, s.y);
		s = R[R.size()-2];
		if(PII(i,j) == s) break;
		block[s.x][s.y] = 1;
		path(i, j);
		block[s.x][s.y] = 0;
	}
	block[i][j] = 1;
}

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,n) FWD(j,0,m) scanf("%d", &source[i][j]);
	FWD(i,0,n) FWD(j,0,m) scanf("%d", &target[i][j]);
	save();
	if(n == 1 || m == 1){
		FWD(s,0,max(n,m)){
			for(int d=-1; d<=1; d+=2){
				load();
				R.push_back(PII(n==1?0:s,n==1?s:0));
				for(int i=s+d;-1<i&&i<max(n,m);i+=d){
					make(n==1?0:i,n==1?i:0);
					check();
				}
			}
		}
		printf("-1\n");
		return 0;
	}
	FWD(i,0,n) FWD(j,0,m) if(source[i][j] == target[n-1][m-1]) a = i, b = j;
	R.push_back(PII(a,b));
	FWD(i,0,n-2)
		FWD(j,0,m)
			setp(i, j);
	FWD(j,0,m-1){
		setp(n-2,j);
		setp(n-1,j);
	}
	check();
	if(a == n-1)
		make(a-1, b);
	else
		make(a+1, b);
	check();
	printf("-1\n");
	return 0;
}