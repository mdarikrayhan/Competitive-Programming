#include <bits/stdc++.h>
using namespace std;

struct point {
	int x , y , r;
	point() {}
	point(int a,int b):x(a) , y(b) , r(a*a + b*b){}
	bool operator == (point &cmp) const {
		return r == cmp.r;
	}
};
vector <point> vec;
vector <pair<int,int> > X , Y;

bool cmp1(const point &a,const point &b) {
	return a.r < b.r;
}
bool cmp2(const point &a,const point &b) {
	return atan2(a.y+0.0 , a.x+0.0) < atan2(b.y+0.0 , b.x+0.0) - 1e-8;
}
void init() {
	for (int i = 0 ; i < 200 ; i ++) {
		for (int j = i ; j < 200 ; j ++) {
			vec.push_back(point(i , j));
		}
	}
	sort(vec.begin() , vec.end() , cmp1);
	vec.erase(unique(vec.begin() , vec.end()) , vec.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	init();
	int n;
	cin >> n;
	int del = 0;
	for (int i = 4 , cnt = 2 , bit = 1; ; i ++) {
		int p = bit;
		int q = (vec[i].x + vec[i].y) & 1;
		if (p && q) {
			if (++cnt == n) del = 3;
			++cnt;
		} else if (p && !q) {
			if (++cnt == n) del = 6;
		} else if (!p && !q) ++ cnt;
		bit = (p + q) & 1;
		if (cnt >= n) {
			int sum = 0;
			for (int j = 1 ; j <= i ; j ++) {
				if (j == del) continue;
				X.push_back(make_pair(vec[j].x , X.size()));
				Y.push_back(make_pair(vec[j].y , Y.size()));
				sum = (sum + vec[j].x) & 1;
			}
			if (sum & 1) swap(X[0].first , Y[0].first);
			break;
		}
	}
	sort(X.begin() , X.end());
	sort(Y.begin() , Y.end());
	int sumX = 0 , sumY = 0;
	for (int i = X.size() - 1 ; i >= 0 ; i --) {
		if (abs(sumX - X[i].first) < abs(sumX + X[i].first)) {
			sumX -= X[i].first;
			X[i].first = -X[i].first;
		} else sumX += X[i].first;
		if (abs(sumY - Y[i].first) < abs(sumY + Y[i].first)) {
			sumY -= Y[i].first;
			Y[i].first = -Y[i].first;
		} else sumY += Y[i].first;
	}
	while (sumX || sumY);
	for (int i = 0; i < X.size() ; i ++) {
		vec[ X[i].second ].x = X[i].first;
		vec[ Y[i].second ].y = Y[i].first;
	}
	vec.erase(vec.begin() + X.size() , vec.end());
	sort(vec.begin() , vec.end() , cmp2);
	cout<<"YES"<<endl;
	int sumx = 0 , sumy = 0;
	for (int i = 0 ; i < vec.size() ; i ++) {
		sumx += vec[i].x;
		sumy += vec[i].y;
		cout << sumx << ' ' << sumy << endl;
	}
	return 0;
}