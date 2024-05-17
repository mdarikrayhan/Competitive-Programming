// LUOGU_RID: 159220712
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define quickio ios::sync_with_stdio(false);
#define quickin cin.tie(nullptr);
#define quickout cout.tie(nullptr);

using namespace std;
string s; int m, l, r, k;
signed main() {
	quickio
	quickin
	quickout
	cin >> s >> m;
	while(m--) {
		cin >> l >> r >> k;
		k %= (r - l + 1), l--, r--;
		string str = s;
		for(int i = l; i <= r; i++)
			str[(i - l + k) % (r - l + 1) + l] = s[i];
		s = str;
	}
	cout << s << endl;
	return 0;
}