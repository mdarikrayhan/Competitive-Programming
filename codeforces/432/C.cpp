#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
vector<int> isprime, primes;
void sieve(int n) {
	isprime.assign(n + 1, 0);
	for(int i = 2; i <= n; i++) {
		if(!isprime[i]) {
			primes.emplace_back(i);
		}
		for(auto p : primes) {
			if(p * i > n) {
				break;
			}
			isprime[p * i] = 1;
			if(i % p == 0) {
				break;
			}
		}
	}
}
void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), p(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}
	auto swp = [&](int x, int y) {
		swap(a[x], a[y]);
		swap(p[a[x]], p[a[y]]);
	} ;
	vector<pii> ans;
	for(int i = 1; i <= n; i++) {
		while(i != p[i]) {
			int d = *(upper_bound(primes.begin(), primes.end(), p[i] - i + 1) - 1);
			ans.push_back({p[i] - d + 1, p[i]});
			swp(p[i], p[i] - d + 1);
		}
	}
	cout << ans.size() << '\n';
	for(auto i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sieve(1e5);
	solve();
	return 0;
}