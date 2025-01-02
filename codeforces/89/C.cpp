#include <cstdio>
#include <cstring>
using namespace std;

int m, n, mn, ans, cnt, p[5005][4];
char c[5005];

int v[5005], vw;

int f(char c) {
switch (c) {
case 'L': return 0;
case 'R': return 1;
case 'U': return 2;
case 'D': return 3;
}
}

int solve(int x) {
for (int i=0; i<mn; ++i) {
p[i][0] = i%n==0? -1: i-1;
p[i][1] = i%n==n-1? -1: i+1;
p[i][2] = i-n;
p[i][3] = i+n;
}
vw = x;
int ret = 0;
while (1) {
ret++;
v[x] = vw;
int z = f(c[x]);
int X = x;
while (c[X] == '.' || v[X] == vw) {
X = p[X][z];
if (! (0<=X && X<mn)) return ret;
}
p[x][z] = X;
x = X;
}
}

int main() {
scanf("%d%d", &m, &n);
mn = m*n;
for (int i=0; i<m; ++i) scanf("%s", c+i*n);
memset(v, -1, sizeof(v));
ans = cnt = 0;
for (int i=0; i<mn; ++i) {
if (c[i] != '.') {
int tmp = solve(i);
if (tmp > ans) {
ans = tmp;
cnt = 1;
}
else if (tmp == ans) cnt++;
}
}
printf("%d %d\n", ans, cnt);
return 0;
}
