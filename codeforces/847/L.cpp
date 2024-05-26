#include <bits/stdc++.h>
using namespace std;

int parse_int(string :: iterator &it, string :: iterator &e) {
	int x = 0;

	while (it != e && isdigit(*it)) {
		x = x * 10 + *it - '0';
		++it;
	}
	if (it != e) ++it;

	return x;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector <string> s(n + 1); 
	for (int i = 1; i <= n ; ++i)
		cin >> s[i];

	int nr = 0;
	vector <int> mx(n * n + 1), cnt(n + 1), who(n * n + 1);
	vector <vector <int>> l(n + 1, vector <int> ());

	for (int i = 1; i <= n ; ++i) {
		auto it = s[i].begin();
		auto e = s[i].end();

		while (it != e) {
			++cnt[i];
			int le = parse_int(it, e);	

			++nr;
			mx[nr] = le;
			who[nr] = i;

			for (int j = 0; j < le ; ++j) {
				int x = parse_int(it, e);
				l[x].push_back(nr);
			}
		}
	}

	queue <int> q;
	for (int i = 1; i <= n ; ++i) {
		if (cnt[i] == 1)
			q.push(i);
	}

	vector <pair <int, int>> ans;
	vector <bool> viz(n + 1, 0);
	while (!q.empty()) {
		int nod = q.front();
		viz[nod] = 1;
		q.pop();

		bool found = false;
		int ad = 0;
		vector <int> aux;
		for (auto it : l[nod]) {
			int vec = who[it];
			if (viz[vec]) continue;

			aux.push_back(it);	
			--mx[it];
			if (mx[it] == 0) {
				found = true;
				ans.push_back({vec, nod});
				ad = vec;
				--cnt[vec];
				if (cnt[vec] == 1)
					q.push(vec);
			}
		}

		if (!found && ans.size() != n - 1) {
			cout << -1 << endl;
			return 0;
		}

		for (auto it : aux) {
			int vec = who[it];
			if (viz[vec]) continue;
			if (vec == ad) continue;
			
			if (find(l[ad].begin(), l[ad].end(), it) == l[ad].end()) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	if (ans.size() != n - 1) {
		cout << -1 << endl;
		return 0;
	}

	cout << ans.size() << endl;
	for (auto it : ans)
		cout << it.first << " " << it.second << endl;

	return 0;
}

