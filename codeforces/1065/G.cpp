# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <vector>
# include <map>
# include <climits>
# include <unordered_map>
#define int long long
using namespace std;
const int INF = 1000000000000000000LL;
int n, k, m;
int tot;
string F[205];
string ans;
int cnt(string now) {
	int res = 0;
	for (int i = 0; i < now.length(); i++) {
		if (i + ans.length() - 1 >= now.length())
			break;
		res++;
		for (int j = 0; j < ans.length(); j++)
			if (now[i + j] != ans[j]) {
				res--;
				break;
			}
	}
	return res;
}

int f[205];
int ff[205][205];     
int pp[205], qq[205]; 
int cal() {
	int subLen = ans.length() - 1;
	string pp14 = F[14].substr(0, subLen);
	string pp15 = F[15].substr(0, subLen);
	string qq14 = F[14].substr(F[14].length() - subLen, subLen);
	string qq15 = F[15].substr(F[15].length() - subLen, subLen);
	ff[14][14] = cnt(qq14 + pp14);
	ff[14][15] = cnt(qq14 + pp15);
	ff[15][14] = cnt(qq15 + pp14);
	ff[15][15] = cnt(qq15 + pp15);
	f[14] = cnt(F[14]);
	f[15] = cnt(F[15]);
	for (int i = 16; i <= n; i++) {
		f[i] = f[i - 2] + f[i - 1] + ff[qq[i - 2]][pp[i - 1]];
		if (f[i] > INF)
			return f[i];
	}
	return f[n];
}

vector<string> allSuf;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	F[0] = "0";
	F[1] = "1";
	for (tot = 2; tot <= 15; tot++)
		F[tot] = F[tot - 2] + F[tot - 1];
	pp[14] = qq[14] = 14;
	pp[15] = qq[15] = 15;
	for (int i = 16; i <= 200; i++) {
		pp[i] = pp[i - 1];
		qq[i] = qq[i - 2];
	}
	
	cin >> n >> k >> m;
	if (n <= 15) {
		for (int i = 0; i < F[n].length(); i++)
			allSuf.push_back(F[n].substr(i));
		sort(allSuf.begin(), allSuf.end());
		cout << allSuf[k - 1].substr(0, m) << "\n";
		return 0;
	}
	ans = "";
	for (int i = 0; i < m; i++) {
		ans += '0';
		int pre = cal(); 
		if (pre < k) {
			k -= pre;
			ans[i] = '1';
		}
		if (k == 0) {
			cout << ans << "\n";
			return 0;
		}
	}
	cout << ans << "\n";
	return 0;
}