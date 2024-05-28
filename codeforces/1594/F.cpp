#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;

	while (T--) {
		i64 S, N, K;
		cin >> S >> N >> K;

		if (S == K) {
			cout << "YES\n";
			continue;
		}

		i64 count = 0;
		count += (S + 1) / (2 * K) * K;
		count += min((S + 1) % (2 * K), K);

		cout << (count >= N + 1 ? "NO" : "YES") << '\n';
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


*/
