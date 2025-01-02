#include <iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
using namespace std;
double x_1, y_1, x_2, y_2;
double mnt = -1, mxt = 1e9;
void bnds(int rx,int ry, int vx, int vy) {
	double d1 = x_1 - rx;
	double d2 = x_2 - rx;
	double d3 = y_1 - ry;
	double d4 = y_2 - ry;
	d1 /=vx, d2 /= vx,
		d3 /= vy, d4/=vy;
	if (d1 > d2)
		swap(d1, d2);
	if (d3 > d4)
		swap(d3, d4);
	if (max(d1, d3) > min(d2, d4))
		mnt = 1e9, mxt = -1e9;
	mnt = max(mnt,max(d1,d3));
	mxt = mxt = min(mxt, min(d2,d4));
}

void slv() {
	int n; cin >> n;
	cin >> x_1 >> y_1 >> x_2 >> y_2;
	x_1 += 1 / 1e9;
	x_2 -= 1 / 1e9;
	y_1 += 1 / 1e9;
	y_2 -= 1 / 1e9;
	if (x_1 >= x_2 || y_1 >= y_2) {
		cout << -1 << '\n';
		return;
	}
	for(int i = 0; i < n; i ++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		bnds(a, b, c, d);
	}
	mnt = max(mnt, 0.0);
	if (mnt < mxt )
		cout << setprecision(10)<<mnt << '\n';
	else cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; t = 1;
	while (t--)
		slv();
	return 0;
}