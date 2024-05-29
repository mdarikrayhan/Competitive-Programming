#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	vector S(N, vector<int>(M));
	for (auto &Si : S) {
		for (auto &Sij : Si) {
			cin >> Sij;
		}
	}

	auto Brute = [&](auto Down, vector<int> H, int depth=0) -> void {
		vector<int> hans;
		auto Try = [&]() -> void {
			for (auto &Si : S) {
				int count = 0;
				for (int j = 0; j < M; j++) {
					if (Si[j] != hans[j]) {
						count++;
					}
				}
				if (count > 2) return;
			}
			
			cout << "Yes\n";
			for (auto ansi : hans) {
				cout << ansi << ' ';
			}
			exit(0);
		};
		
		hans = H;
		Try();

		if (depth < 2) {
			for (auto &Si : S) {
				vector<int> diff;
				for (int j = 0; j < M; j++) {
					if (Si[j] != H[j]) {
						diff.push_back(j);
					}
				}

				if (diff.size() > 4) {
					return;
				}

				if (diff.size() > 2) {
					for (int j = 0; j < diff.size(); j++) {
						auto Hj = H;
						Hj[diff[j]] = Si[diff[j]];
						Down(Down, Hj, depth + 1);
					}
					return;
				}
			}
		}
	};
	Brute(Brute, S[0]);

	cout << "No";
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

First copy has no incorrect elements
-> try and see

First copy has incorrect elements
-> all copies with "incorrect" elements must have some elements in
	common, in which they all have the same values
-> brute force
*/
