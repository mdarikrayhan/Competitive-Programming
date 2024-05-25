// Code by Heratino & Nelofus
// Narcissus & どうか安寧な記憶を

#include <bits/stdc++.h>
using i64 = long long;

//{{{うるさいんだよ　ほっといてくれよ
template<typename Ta, typename Tb>
inline void chkmax(Ta &a, const Tb &b) {if (a < b)	a = b;}
template<typename Ta, typename Tb>
inline void chkmin(Ta &a, const Tb &b) {if (a > b)	a = b;}
//}}}

int n;
int mxdep;
int ask(std::vector<int> a, std::vector<int> b) {
	std::cout << a.size() << ' ' << b.size() << ' ';
	for (const int &x : a)
		std::cout << x << ' ';
	for (const int &x : b)
		std::cout << x << ' ';
	std::cout << std::endl;
	int ans;
	std::cin >> ans;
	return ans;
}

int solve(int l, int r) {
	if (l == r)
		return l;
	std::vector<int> a, b;
	a.push_back(1);
	int mid = l + r >> 1;
	for (int i = l; i <= mid; i++)
		b.push_back(i);
	if (ask(a, b) == mxdep)
		return solve(l, mid);
	else
		return solve(mid + 1, r);
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		std::vector<int> a, b;
		a.push_back(1);
		for (int i = 2; i <= n; i++)
			b.push_back(i);
		mxdep = ask(a, b);
		int p = solve(2, n);
		a.clear(), b.clear();
		a.push_back(p);
		for (int i = 1; i <= n; i++)
			if (p != i)
				b.push_back(i);
		int t = ask(a, b);
		std::cout << -1 << ' ' << t << std::endl;
	}
	return 0;
}
