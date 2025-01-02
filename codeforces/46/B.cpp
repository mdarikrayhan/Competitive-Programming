#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <map>
#include <stack>
#include <set>

#define x first
#define y second
//#define int long long

using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

const LL INFF = 0x3f3f3f3f3f3f3f3f;

const int N = 110, INF = 0x3f3f3f3f, M = N << 1;

string str[5] = {"S", "M", "L", "XL", "XXL"};
int cnt[N];

void relay(int pos)
{
	for (int i = pos - 1, j = pos + 1; ; i --, j ++ )
	{
		if (j < 5 && cnt[j]) {
			cout << str[j] << "\n";
			cnt[j] --;
			break;
		}
		if (i >= 0 && cnt[i]) {
			cout << str[i] << "\n";
			cnt[i] --;
			break;
		}
	}
}

inline void solve()
{
	for (int i = 0; i < 5; i ++ ) cin >> cnt[i];
	int k;
	cin >> k;
	while (k -- )
	{
		string s;
		cin >> s;
		if (s == "S") {
			if (cnt[0]) cnt[0] --, cout << "S" << "\n";
			else relay(0);
		} else if (s == "M") {
			if (cnt[1]) cnt[1] --, cout << "M" << "\n";
			else relay(1);
		} else if (s == "L") {
			if (cnt[2]) cnt[2] --, cout << "L" << "\n";
			else relay(2);
		} else if (s == "XL") {
			if (cnt[3]) cnt[3] --, cout << "XL" << "\n";
			else relay(3);
		} else {
			if (cnt[4]) cnt[4] --, cout << "XXL" << "\n";
			else relay(4);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- )
	{
//		init();
		solve();
	}
	return 0;
}

