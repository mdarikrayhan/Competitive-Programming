// LUOGU_RID: 159226711
#include <bits/stdc++.h> 
using namespace std; 
const int N = 2e5 + 5;
int z[N], o[N]; 
int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int l = s.size();
		for (int i = 0; i < l; i++)
			z[i + 1] = z[i] + (s[i] == '0'),
			o[i + 1] = o[i] + (s[i] == '1');
		int cnt0 = z[l], ans = 1e9;
		for (int i = 0; i <= cnt0; i++){
			int tmp = l - (cnt0 - i);
			int maxn = o[i] + o[l] - o[tmp];
			ans = min(ans, maxn);
		}
		if (ans == 1e9) cout << "0\n";
		else cout << ans << '\n';
	}
}