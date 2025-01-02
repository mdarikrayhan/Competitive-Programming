// LUOGU_RID: 159984368
#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, ta, b, tb, h, m;
	cin >> a >> ta >> b >> tb;
	scanf("%d:%d", &h, &m);
	int c = h * 60 + m, d;
	if (c - tb < 300) d = 1;
	else d = (c - tb - 300) / b + 2;
	int e = ceil(1.0 * (min(min(c + ta, 1440), 1439 + tb) - 300) / b);
	int ans = e - d + 1;
	cout << ans;
}