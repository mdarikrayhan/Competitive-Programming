#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main() {
	IOS; int T;
	for (cin >> T; T--;) {
		int n, m; cin >> n >> m;
		string s, t; cin >> s >> t;
		cout << ((s.find("11") != string::npos && (t.find("00") != string::npos || t.find("11") != string::npos || t[0] != '0' || t[m - 1] != '0') || (s.find("00") != string::npos && (t.find("00") != string::npos || t.find("11") != string::npos || t[0] != '1' || t[m - 1] != '1'))) ? "NO\n" : "YES\n");
	}
}