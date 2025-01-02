// LUOGU_RID: 159763791

#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;

typedef double ll;
const int MOD = 1000000007;

ll OX = -1781723787;
ll OY = -700853865;

int n, m;

struct node;
ll cross(ll x1, ll y1, ll x2, ll y2) {
	return x1*y2 - x2*y1;
}

struct node {
	ll x, y;
	bool operator < (const node& o) const {
		return cross(1, 0, x-OX, y-OY)/sqrt((x-OX)*(x-OX) + (y-OY)*(y-OY)) <
		cross(1, 0, o.x-OX, o.y-OY)/sqrt((o.x-OX)*(o.x-OX)+(o.y-OY)*(o.y-OY));
	}
};


node R[505], B[505];

bool in_tri(ll x, ll y, ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll v1 = cross(x-x1, y-y1, x2-x1, y2-y1);
	ll v2 = cross(x-x2, y-y2, x3-x2, y3-y2);
	ll v3 = cross(x-x3, y-y3, x1-x3, y1-y3);

	return ((v1>0 && v2>0 && v3>0) || (v1<0 && v2<0 && v3<0));
}


int cnt(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	int ret = 0;
	for (int i = 0; i < m; i++) {
		if (in_tri(B[i].x, B[i].y, x1, y1,x2, y2, x3, y3)) ret++;
	}
	return ret;
}

// tot[i][j]表示三角形(O, i, j)中包含的点的个数
int tot[505][505];

// 判断三角形中是否没有蓝点
bool is_emp(int i, int j, int k) {
	return tot[i][j] + tot[j][k] - tot[i][k] == 0;
}


int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lf %lf", &R[i].x, &R[i].y);
	for (int i = 0; i < m; i++) scanf("%lf %lf", &B[i].x, &B[i].y);

	sort(R, R+n);
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			tot[i][j] = tot[j][i] = cnt(OX, OY, R[i].x, R[i].y, R[j].x, R[j].y);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				if (is_emp(i, j, k)) ans++;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}