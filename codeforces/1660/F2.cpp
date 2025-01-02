#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	auto solve = [&](){
		int n;
		cin >> n;
		string s;
		cin >> s;
		s = " " + s;
		vector <int >a(n + 1);
		vector <array<int,3>> t(n*5 + 1);
		for(int i=1;i<=n;i++){
			a[i]=a[i-1]+(s[i]=='+'?1:-1);
		}
		auto lowbit = [&](int x){
			return x&(-x);
		};
		auto query = [&](int x,int sb){
			int res = 0;
			while(x){
				res += t[x][sb];
				x-=lowbit(x);
			}
			return res;
		};
		auto add= [&](int x,int sb,int k){
			while(x<=n*5){
				t[x][sb] +=k;
				x += lowbit(x);
			}
		};
		int base = n + 1;
		int ans = 0;
		for(int i=n;i>=0;i--){
			ans += query(a[i] + base,((a[i]%3) + 3)%3);
			add(a[i] + base,((a[i]%3) + 3)%3,1);
		}
		cout << ans << "\n";
	};
	int t;
	cin >> t;
	for(int k=1;k<=t;k++){
		solve();
	}
	return 0;
}