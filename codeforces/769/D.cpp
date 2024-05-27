#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
#define se second
#define fi first
using namespace std;
const int md = 998244353;
const int N = 2e4;
int C(int x){
	int cnt = 0;
	while(x){
		cnt += x % 2;
		x /= 2;
	}
	return cnt;
}
void solve(){
	int n , k;
	cin >> n >> k;
	int a[n + 5] , us[2 * N + 5] = {0};
	for(int i = 1;i <= n; ++ i){
		cin >> a[i];
		us[a[i]] ++;
	}
	int ans = 0;
	vector<int> v;
	for(int i = 0;i <= N; ++ i){
		if(C(i) == k)	v.push_back(i);
	}
	for(int i = 0;i <= N; ++ i){
		for(auto to : v){
			int x = (i ^ to);
			ans += us[i] * us[x];
		}
	}
	if(k == 0){
		ans = 0;
		for(int i = 1;i <= n; ++ i){
			ans += (us[a[i]] * (us[a[i]] - 1));
			us[a[i]] = 0;
		}
	}
	cout << ans / 2;
}
main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T --)
    {
        solve();
        cout << '\n';
    }
}
//test
/*
// ٩ (◕‿◕｡) ۶
*/