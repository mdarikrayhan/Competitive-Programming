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
	int n;
	cin >> n;
	vector<int> P(n * 3), plc(n * 3);
	For(i, n * 3){
		cin >> P[i];
		-- P[i];
		plc[P[i]] = i;
	}
	vector<array<int, 3> > teams(n);
	For(i, n){
		cin >> teams[i][0] >> teams[i][1] >> teams[i][2];
		--teams[i][0], --teams[i][1], --teams[i][2];
	}
	int k;
	cin >> k;
	--k;
	int t = 0;
	while(teams[t][0] != k && teams[t][1] != k && teams[t][2] != k) t ++;
	if(plc[k] > plc[teams[t][0]] || plc[k] > plc[teams[t][1]] || plc[k] > plc[teams[t][2]]){
		For(i, n * 3) if(i != k) cout << i + 1 << " ";
		cout << "\n";
	}
	else{
		vector<int> a, b;
		For(i, t){
			a.pb(teams[i][0]);
			a.pb(teams[i][1]);
			a.pb(teams[i][2]);
		}
		FoR(i, t, n){
			if(teams[i][0] != k) b.pb(teams[i][0]);
			if(teams[i][1] != k) b.pb(teams[i][1]);
			if(teams[i][2] != k) b.pb(teams[i][2]);			
		}
		sort(all(a));
		sort(b.begin(), b.begin() + 2);
		sort(b.begin() + 2, b.end());
		int i = 0, j = 0;
		while(i < a.size() || j < b.size()){
			if(!(j < b.size()) || (i < a.size()) && a[i] < b[j]){
				cout << a[i] + 1 << " ";
				++ i;
			}
			else{
				cout << b[j] + 1 << " ";
				++ j;
			}
		}
		cout << "\n";
	}
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