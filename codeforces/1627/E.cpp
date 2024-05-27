	#include <bits/stdc++.h>
	using namespace std;

	#define N 100005
	#define int long long

	int n, m, k, x[N];
	set<int> st[N];
	map<int, int> dp[N];

	struct ii
	{
		int b, c, d, h;
	};

	vector<ii> ud[N];

	void solve(){
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {cin >> x[i]; st[i].clear(); dp[i].clear(); ud[i].clear();}
		for (int i = 1; i <= k; i++){
			int a, b, c, d, h;
			cin >> a >> b >> c >> d >> h;
			st[a].insert(b);
			st[c].insert(d);
			ud[a].push_back({b, c, d, h});
		}
		st[1].insert(1);
		st[n].insert(m);
		dp[1][1] = 0;
		for (int i = 1; i <= n; i++){
			vector<int> pos(st[i].begin(), st[i].end());
			for (int j = 1; j < (int) pos.size(); j++){
				int lst = pos[j - 1], cur = pos[j];
				if (dp[i].find(lst) == dp[i].end()) continue;
				int cst = dp[i][lst] + x[i] * abs(cur - lst);
				if (dp[i].find(cur) == dp[i].end() || dp[i][cur] > cst)
					dp[i][cur] = cst;
			}
			for (int j = (int) pos.size() - 2; j >= 0; j--){
				int nex = pos[j + 1];
				int cur = pos[j];
				if (dp[i].find(nex) == dp[i].end()) continue;
				int cst = dp[i][nex] + x[i] * (nex - cur);
				if (dp[i].find(cur) == dp[i].end() || dp[i][cur] > cst)
					dp[i][cur] = cst;
			}
			for (ii x : ud[i]){
				int b = x.b, c = x.c, d = x.d, h = x.h;
				if (dp[i].find(b) == dp[i].end()) continue;
				int cst = dp[i][b] - h;
				if (dp[c].find(d) == dp[c].end() || dp[c][d] > cst) dp[c][d] = cst;
			}
		}
		if (dp[n].find(m) == dp[n].end()) cout << "NO ESCAPE\n";
		else cout << dp[n][m] << "\n";
	}

	signed main(){
	    ios_base::sync_with_stdio(0);
	    cin.tie(NULL);
		
		int t;        
	    cin >> t;
	    while (t--){
	        solve();
	    }

	    return 0;
	}     