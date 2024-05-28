// LUOGU_RID: 158304026
// They say that life is always easier
// After you let yourself come undone
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, a, b;
char s[N];
void Solve() {
	cin >> a >> b >> s;
	n = strlen(s);
	int s2 = 0, s3 = 0, s4 = 0, len = 0;
	for(int i = 0, now = 0; i <= n; ++i) 
		if(s[i] == '.') ++now;
		else {
			if(now >= b && now < a) ++s2;
			else if(now >= a && now < b * 2) ++s3;
			else if(now >= b * 2) ++s4, len = now;
			now = 0;
		}
	if(s2 || s4 >= 2) return printf("NO\n"), void();
	if(!s4) return printf((s3 & 1) ? "YES\n" : "NO\n"), void();
	for(int i = 0; i <= len - a; ++i) {
		int l = i, r = len - a - i;
		if(l >= b && l < a) continue;
		if(r >= b && r < a) continue;
		if(l >= b * 2 || r >= b * 2) continue;
		if((s3 + (l >= a) + (r >= a)) % 2 == 0) 
			return printf("YES\n"), void();
	}
	printf("NO\n");
}
int main() {
	//freopen("data.in", "r", stdin);
	//freopen("code.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) Solve();
	return 0;
}