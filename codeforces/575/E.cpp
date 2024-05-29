// LUOGU_RID: 159333206
// Code by Heratino & Nelofus
// Narcissus & どうか安寧な記憶を

#include <bits/stdc++.h>
using i64 = long long;
using f64 = double;

//{{{うるさいんだよ　ほっといてくれよ
template<typename Ta, typename Tb>
inline void chkmax(Ta &a, const Tb &b) {if (a < b)	a = b;}
template<typename Ta, typename Tb>
inline void chkmin(Ta &a, const Tb &b) {if (a > b)	a = b;}
//}}}

constexpr int N = 1e5 + 10;
constexpr int V = 1e5;

int n;

struct Point {
	i64 x, y;
	Point() {}
	Point(i64 _x, i64 _y) : x(_x), y(_y) {}
	bool operator == (const Point &P) const {
		return x == P.x && y == P.y;
	}
};
using Vector = Point;
Vector operator + (const Vector &A, const Vector &B) {
	return Vector(A.x + B.x, A.y + B.y);
}
Vector operator - (const Vector &A, const Vector &B) {
	return Vector(A.x - B.x, A.y - B.y);
}
Vector trans(const Vector &A, const Vector &B) {
	return B - A;
}
inline i64 Dot(const Vector &A, const Vector &B) {
	return A.x * B.x + A.y * B.y;
}
inline f64 Length(const Vector &A) {
	return sqrt((f64)Dot(A, A));
}
inline i64 Cross(const Vector &A, const Vector &B) {
	return A.x * B.y - A.y * B.x;
}

int cur;
Point all[N * 6];
Point stk[N * 6];
int main() {
#ifdef HeratinoNelofus
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, d;
		std::cin >> x >> y >> d;

		if (x - d >= 0)
			all[++cur] = Point(x - d, y);
		else
			all[++cur] = Point(0, std::max(y - (d - x), 0)), all[++cur] = Point(0, std::min(y + (d - x), V));

		if (y - d >= 0)
			all[++cur] = Point(x, y - d);
		else
			all[++cur] = Point(std::max(x - (d - y), 0), 0), all[++cur] = Point(std::min(x + (d - y), V), 0);

		if (x + d <= V)
			all[++cur] = Point(x + d, y);
		else
			all[++cur] = Point(V, std::max(y - (x + d - V), 0)), all[++cur] = Point(V, std::min(y + (x + d - V), V));

		if (y + d <= V)
			all[++cur] = Point(x, y + d);
		else
			all[++cur] = Point(std::max(x - (y + d - V), 0), V), all[++cur] = Point(std::min(x + (y + d - V), V), V);
	}
	std::sort(all + 1, all + 1 + cur, [&](auto x, auto y) -> bool {
			return x.x == y.x ? x.y < y.y : x.x < y.x;
			});

	int tt = 0;
	for (int i = 1; i <= cur; i++) {
		while (tt > 1 && Cross(trans(stk[tt - 1], stk[tt]), trans(stk[tt - 1], all[i])) <= 0)
			tt--;
		stk[++tt] = all[i];
	}
	int curstk = tt;
	for (int i = cur - 1; i >= 1; i--) {
		while (tt > curstk && Cross(trans(stk[tt - 1], stk[tt]), trans(stk[tt - 1], all[i])) <= 0)
			tt--;
		stk[++tt] = all[i];
	}

	stk[0] = stk[tt - 1];
//	for (int i = 0; i <= tt; i++)
//		std::cerr << stk[i].x << ' ' << stk[i].y << '\n';

	int ansp = 0;
	f64 ansr = 0;
	for (int i = 1; i < tt; i++) {
		Vector v1 = trans(stk[i], stk[i - 1]), v2 = trans(stk[i], stk[i + 1]);
		Vector v3 = trans(stk[i - 1], stk[i + 1]);
		f64 r = Length(v1) * Length(v2) * Length(v3) / (Cross(v2, v1) * 2);
		if (r > ansr)
			ansr = r, ansp = i;
	}
	std::cout << stk[ansp - 1].x << ' ' << stk[ansp - 1].y << '\n';
	std::cout << stk[ansp - 0].x << ' ' << stk[ansp - 0].y << '\n';
	std::cout << stk[ansp + 1].x << ' ' << stk[ansp + 1].y << '\n';
	return 0;
}
