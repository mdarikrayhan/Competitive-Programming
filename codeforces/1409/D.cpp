#include<bits/stdc++.h>
#define int long long
#define nl endl
using namespace std;

int sum(long long n) {
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

inline void solve(){
        int n;
		int s;
		cin >> n >> s;
		long long ans = 0;
		if(sum(n) <= s) {
			cout << 0 << nl;
			return;
		}
		long long pw = 1;
		for (int i = 0; i < 18; ++i) {
			int digit = (n / pw) % 10;
			long long add = pw * ((10 - digit) % 10);
			n += add;
			ans += add;
			if (sum(n) <= s) {
				break;
			}
			pw *= 10;
		}
		cout << ans << nl;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}