#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    auto all_eq_k = [&] () {
        for(auto x : a) if(x != k) return false;
        return true;
    };

    if(all_eq_k()) return cout << 0, void();

    int sum = accumulate(a.begin(), a.end(), 0);
    if(sum % n == 0 && sum / n == k) return cout << 1, void();
    if(count(a.begin(), a.end(), k)) return cout << 1, void();

    return cout << 2, void();
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int _TC = 0; cin >> _TC;
  for(int _ct = 1; _ct <= _TC; ++_ct) {
      solve(); cout << endl;
  }
}


		 	 		 		  		 		 		  					 			