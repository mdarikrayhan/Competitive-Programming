#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::vector<int> prefix_function(std::span<T> s) {
	int n = int(s.size());
	std::vector<int> pi(n);
	for (int i = 1; i < n; ++i) {
		auto j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

void solve() {
	int n, w;
	cin >> n >> w;

	vector<int> s_t(w + n + 1);
	for (int i = 0; i < n; ++i) cin >> s_t[w + 1 + i];
	s_t[w] = 1e9 + 10;
	for (int i = 0; i < w; ++i) cin >> s_t[i];

	for (int i = 0; i < n + w; ++i)
		s_t[i] = s_t[i + 1] - s_t[i];
	s_t.pop_back();

	auto pi = prefix_function(span{s_t});
	int count = 0;

	for (int i = w; i < n + w; ++i) {
		count += pi[i] == w - 1;
	}

	cout << count << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t = 1;
	// std::cin >> t;
	while (t--) solve();
	return 0;
}
