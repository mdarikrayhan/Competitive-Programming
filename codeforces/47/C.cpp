#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for(int i = 0; i < (n); ++i)
#define rFor(i, n) for(int i = (n - 1); i >= 0; i--)
#define FoR(i, st, ed) for(int i = (st); i < (ed); ++i)
#define rFoR(i, st, ed) for(int i = (ed) - 1; i >= (st); --i)
#define FOR(i, st, ed) for(int i = (st); i <= (ed); ++i)
#define rFOR(i, st, ed) for(int i = (ed); i >= (st); --i)
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(a) a.begin(),a.end()
using i64 = long long;
const int INF  = 1e9+7;
const int MAX = 1e5;
const int mod  = 1e9+7;
const double eps = 0.001;
//--------------------------------------------
void solve() {
	vector<string> a(6);
	For(i, 6) cin >> a[i];
	sort(all(a));
	set<string> res;
	do{
		if(a[0].size() + a[5].size() == a[3].size() + 1 && a[1].size() + a[4].size() == a[2].size() + 1 && a[0][0] == a[1][0] && a[0].back() == a[2][0] && a[1].back() == a[3][0] && a[3][a[0].size() - 1] == a[2][a[1].size() - 1] && a[3].back() == a[4][0] && a[2].back() == a[5][0] && a[4].back() == a[5].back() && a[1].size() > 2 && a[4].size() > 2 && a[0].size() > 2 && a[5].size() > 2){
			int n = a[2].size(), m = a[3].size();
			vector<string> ans(n, string(m, '.'));
			For(i, a[0].size()) ans[0][i] = a[0][i];
			For(i, a[1].size()) ans[i][0] = a[1][i];
			For(i, a[2].size()) ans[i][a[0].size() - 1] = a[2][i];
			For(i, a[3].size()) ans[a[1].size() - 1][i] = a[3][i];
			For(i, a[4].size()) ans[a[1].size()-1 + i][m - 1] = a[4][i];
			For(i, a[5].size()) ans[n - 1][a[0].size()-1 + i] = a[5][i];
			string now = "";
			For(i, n) now += ans[i] + "\n";
			res.insert(now);
		}
	}while(next_permutation(all(a)));
	if(!res.empty()) cout << *res.begin();
	else cout << "Impossible\n";
}

int main() {
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);

	int t = 1;
	//cin >> t;
	while (t--)solve();
	return 0;
}
/*
*/