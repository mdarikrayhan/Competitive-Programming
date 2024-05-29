// LUOGU_RID: 160559741
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5, inf = 2e9;
int n, l[N], r[N], Ans[N], tmp[N], tag[N], pos[N], cnt[N];
inline bool check(int val) {
	for(int i = 1; i <= n; ++ i) tag[i] = 0, pos[i] = n;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) cnt[j] = 0;
		for(int j = 1; j <= n; ++ j) if(!tag[j]) cnt[pos[j]] ++;
		for(int j = 1; j <= n; ++ j) cnt[j] += cnt[j - 1];
		for(int j = i; j <= n; ++ j) if(cnt[j] > j - i + 1) return 0;
		int mx = 0, ps = n + 1; for(int j = i; j <= n; ++ j) if(cnt[j] == (j - i + 1)) {mx = j; break;}
		for(int j = 1; j <= n; ++ j) if(!tag[j] && pos[j] <= mx && r[j] < r[ps]) ps = j;
		tag[ps] = 1, tmp[i] = ps; for(int j = 1; j <= n; ++ j) if(l[j] <= r[ps] && l[ps] <= r[j]) pos[j] = min(pos[j], i + val);
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); cin >> n; r[n + 1] = inf;
	for(int i = 1; i <= n; ++ i) cin >> l[i] >> r[i];
	int vL = 1, vR = n - 1;
	while(vL <= vR) {
		int mid = (vL + vR) >> 1;
		if(check(mid)) vR = mid - 1, memcpy(Ans, tmp, sizeof(Ans));
		else vL = mid + 1;
	}
	for(int i = 1; i <= n; ++ i) cout << Ans[i] << ' ';
	return 0;
}