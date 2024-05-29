// LUOGU_RID: 160487811
//key conclusion: 答案必为 A*B+C 的形式，其中A,B,C=x^y (y==0/1 时省略y)，暴力预处理x^y后在 map 中查询即可
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
#define mems(x, v) memset(x, v, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

unordered_map <ll, string> mp;
inline __int128 pw(ll x, int y) {__int128 ans = 1; while (y--) ans *= x; return ans;}
int main() {
	ll n; cin >> n;
	for (int up = 2; up <= (int)log2(n); up++)
		for (ll x = 2, val; (val = pw(x, up)) <= n; x++) {
			string qwq = to_string(x) + '^' + to_string(up);

			if (!mp.count(val)) mp[val] = to_string(val);
			if (qwq.length() < mp[val].length()) mp[val] = qwq;
		}
	string ans = to_string(n);
	for (auto [A, str] : mp) {
		ll B = n / A, C = n % A;
		if (B > 1) str += '*' + (mp.count(B) ? mp[B] : to_string(B));
		if (C) str += '+' + (mp.count(C) ? mp[C] : to_string(C));
		ans = (ans.length() < str.length() ? ans : str);
	} cout << ans;
	return 0;
}
