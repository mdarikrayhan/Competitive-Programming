// LUOGU_RID: 160124770
#include <bits/stdc++.h>
using namespace std;
int t;
int n, a, b;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, int> mp;
		for (int i = 1; i <= n; i++) {
			cin >> a;
			while (a % 2 == 0)
				a = a / 2;
			mp[a]++;
		}
		int f = 0;
		for (int i = 1; i <= n; i++) {
			cin >> b;
			while (b % 2 == 0)
				b = b / 2;
			while (b != 1 && mp[b] == 0)
				b = b / 2;
			if (mp[b] > 0)
				mp[b]--;
			else
				f = 1;
		}
		if (f == 0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
