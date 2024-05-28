#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	vector<int> roots;
	vector<vector<int>> groups(N);
	for (int i = 0; i < N; i++) {
		roots.push_back(i);
		groups[i].push_back(i);
	}	

	vector ans(N, vector<int>(N));
	int t = 1;
	while (roots.size() > 1) {
		auto roots0 = roots;
		roots.clear();

		auto groups0 = groups;
		for (int i = 0; i < N; i++) {
			groups[i].clear();
		}

		vector<pair<int, int>> edges;
		for (int i = 0; i < roots0.size(); i += K) {
			for (int j = 0; j < K and i + j < roots0.size(); j++) {
				for (int k = j + 1; k < K and i + k < roots0.size(); k++) {
					edges.push_back({roots0[i + j], roots0[i + k]});
				}
			}

			roots.push_back(roots0[i]);
			for (int j = 0; j < K and i + j < roots0.size(); j++) {
				for (auto jk : groups0[roots0[i + j]]) {
					groups[roots0[i]].push_back(jk);
				}
			}
		}

		for (auto [a, b] : edges) {
			for (auto ai : groups0[a]) {
				for (auto bi : groups0[b]) {
					ans[ai][bi] = t;
				}
			}
		}
		t++;
	}

	cout << t - 1 << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			cout << ans[i][j] << ' ';
		}
	}
}
/*
1. Think big picture!

2. Don't waste time coding before thinking it through!

3. Think fast! Don't be afraid to churn through ideas!

4. Try modelling the problem with as few moving parts as possible!
	- What does the problem look like?
	- What might the solution look like?

5. Try solving an easier version of the problem!
	- What if the problem didn't have this constraint?
	- How would I solve a more general version of the problem?

6. Ask questions!
	- What has similar behavior?
	- I've assumed this, what now?

Guessing :')
*/
