#include<bits/stdc++.h>
#define fi first
#define int long long
#define fr freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define se second
using namespace std;
const int N = 2e3;
const int inf = 1e9 + 1;
const int md = 998244353;
void solve(){
	int n;
	cin >> n;
	int a[n + 5] , b[n + 5];
	int ans = 0;
	for(int i = 1;i <= n; ++ i){
		cin >> a[i];
	}
	for(int i = 1;i <= n; ++ i){
		cin >> b[i];
	}
	bool ok[n + 5] = {true};
	for(int i = 1;i <= n; ++ i){
		for(int j = 1;j <= n; ++ j){
			if(i != j and a[i] == a[j]){
				ok[i] = true;
			}
		}
	}
	for(int i = 1;i <= n; ++ i){
		if(ok[i] == true){
			ans += b[i];
			continue;
		}
		for(int j = 1;j <= n; ++ j){
	        if(ok[j] and (a[i] & a[j]) == a[i]){
	        	ans += b[i];
	        	break;
	        }
		}
	}
	cout << ans;
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
    }
}
//test
/*
*/
