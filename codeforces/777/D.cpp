#include <bits/stdc++.h>
#define thoughtcrime ios_base::sync_with_stdio(0); cin.tie(0);
#define ull unsigned long long
#define int long long
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
const int MOD = 1e9 + 7;

int dirx[4] = {0, -1, 0, 1};
int diry[4] = {-1, 0, 1, 0};
char dir[4] = {'L', 'U', 'R', 'D'};

signed main(){
	thoughtcrime
	int n; cin >> n;
	vector<string> strs(n); for (auto &s : strs) cin >> s;

	for (int i = n-2; i >= 0; i--){
		if (strs[i] <= strs[i+1]) continue;
		int len = min(strs[i].length(), strs[i+1].length());
		string s = "";
		for (int j = 0; j < len; j++){
			if (strs[i][j] > strs[i+1][j]) break;
			s += strs[i][j];
		}
		strs[i] = s;
	}

	for (auto &s : strs) cout << s << "\n";
}