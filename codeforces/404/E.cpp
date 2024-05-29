// LUOGU_RID: 160523558
#include<bits/stdc++.h>
using namespace std;
int n, npos, maxp, minp;
char ch[1000005];
int chk(int pos) {      //判断墙放在pos处是否可行，pos=0代表不放墙 
	npos = maxp = minp = 0;
	for(int i = 1; i <= n; i++) {
		maxp = max(maxp, npos);
		minp = min(minp, npos);
		npos += (ch[i] == 'R') ? 1 : -1;
		if(pos && npos == pos)  npos -= (ch[i] == 'R') ? 1 : -1;
	}
	return npos > maxp || npos < minp;
}
int main() {
	scanf("%s", ch + 1);
	n = strlen(ch + 1);
	if(chk(0)) {
		puts("1");
		return 0;
	}
	if(ch[n] == 'L') {
		int l = 1, r = 1E6, ans = 0;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(chk(mid))  ans = mid, l = mid + 1;
			else  r = mid - 1;
		}
		cout << ans << endl;
		return 0;
	}
	int l = -1E6, r = -1, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(chk(mid))  ans = mid, r = mid - 1;
		else  l = mid + 1;
	}
	cout << abs(ans) << endl;
}