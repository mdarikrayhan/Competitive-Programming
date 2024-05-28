#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 2e9;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	auto solve = [&](){
		int n,q;
		cin >> n >> q;
		vector <int> a(n + 10);
		vector <int> e(n + 10);
		vector <int> r(n + 10);
		vector <int> l(n + 10);
		vector <int> be(n + 10);
		vector <int> f(n + 10);
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		int block = max(10ll,(int)sqrt(n));
		int tot = (n + block-1)/block;
		auto change = [&](int k){
			if(k==tot) return;
			e[k] = 0;
			for(int i=l[k];i<=r[k];i++) e[k] = sqrtl(e[k] + a[i]);
			f[k] = e[k] + 1;
			for(int i=r[k];i>=l[k] && f[k]!=inf;i--) {
				f[k] = min(inf,f[k]*f[k]- a[i]);
			}
		};
		for(int i=1;i<=tot;i++){
			l[i] =(i-1)*block + 1,r[i] = min(n,block*i);
			for(int j = l[i];j<=r[i];j ++ )be[j] = i;
			change(i);
		}
		while(q--){
			int k;int x;
			cin >> k >> x;
			a[k] = x;
			change(be[k]);
			int ans = 0;
			for(int i=1;i<=tot - 1;i++){
				ans = e[i] + (ans >=f[i]);
			}
			for(int i=l[tot];i<=n;i++) ans = sqrtl(a[i] + ans);
			cout << ans << "\n";
		}

	};
	int t=1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}