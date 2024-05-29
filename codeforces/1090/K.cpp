#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	map<pair<string,int>, vector<int>> vec;
	for (int i = 0; i < n; ++i) {
		string s, t; cin >> s >> t;
		int mask = 0;
		for (auto& c : t) mask |= 1 << (c - 'a');
		while (s.size() && (mask & (1 << (s.back() - 'a')))) s.pop_back();
		vec[{s, mask}].push_back(i);
	} 
	cout << vec.size() << '\n';
	for (auto it : vec) {
		cout << it.second.size() << ' ';
		for (auto id : it.second) {
			cout << id + 1 << ' ';
		}
		cout << '\n';
	}
}