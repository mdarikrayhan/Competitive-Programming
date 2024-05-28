#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int L, N;
	cin >> L >> N;

	vector<int> A(N);
	for (auto &Ai : A) cin >> Ai;

	auto Check1 = [&](int lb) -> bool {
		int j = 0;
		for (int i = 0; i < N; i++) {
			if (j > A[i]) return false;
			j = max(A[i], j + lb);
		}
		return j <= L;
	};

	int l = 0, r = L;
	while (l < r) {
		int m = l + (r - l + 1) / 2;
		Check1(m) ? l = m : r = m - 1;
	}
	int lb = l;

	auto Check2 = [&](int ub) -> bool {
		int j = 0, leeway = 0;
		for (int i = 0; i < N; i++) {
			if (j > A[i]) {
				if (j - leeway > A[i]) return false;
				leeway -= j - A[i];
				j = A[i];
			}
			j += ub;
			if (j < A[i]) return false;
			leeway = min(leeway + ub - lb, j - A[i]);
		}
		return j - leeway <= L and j >= L;
	};

	l = 0, r = L;
	while (l < r) {
		int m = l + (r - l) / 2;
		Check2(m) ? r = m : l = m + 1;
	}
	int ub = l;

	vector<pair<int, int>> stack;
	vector<int> ans(N);
	int j = 0;
	auto Squeeze = [&](int j0) -> void {
		while (j > j0) {
			auto &[size, i] = stack.back();

			int d = min(size, j - j0);
			size -= d, j -= d, ans[i] -= d;

			if (size == 0) {
				stack.pop_back();
			}
		}
	};

	int leeway = 0;
	for (int i = 0; i < N; i++) {
		if (j > A[i]) {
			Squeeze(A[i]);
			leeway -= j - A[i];
			j = A[i];
		}

		j += ub;
		leeway = min(leeway + ub - lb, j - A[i]);

		ans[i] = ub;
		stack.push_back({ub - lb, i});
	}
	Squeeze(L);

	int i = 0;
	for (auto size : ans) {
		cout << i << ' ' << i + size << '\n';
		i += size;
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

Guessing?
*/
