#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define TIME (1.0 * clock () / CLOCKS_PER_SEC)
using namespace std;
typedef long long ll;

ll C(ll k, ll n) { 
    ll r = 1; for (ll i = 1; i <= k; i++,n--) r=r*n/i; 
    return r; 
} 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n; cin >> n;
    ll a[n];
    ll cnt = 0;
    for(ll i = 0 ; i < n ; i++){
    	cin >> a[i];
    	if(a[i] == 0) cnt++;
    }

    sort(a,a+n);
	ll l = 0, r = n-1;
	ll res = 0;
	while(a[l] != 0 && a[r] != 0 && l < r){
		if(a[l] + a[r] == 0){
			ll cnt_l = 1,cnt_r = 1;
				while(a[l] != 0 && l < r-1 && a[l] == a[l+1]){
					cnt_l++; l++;
				}
				while(a[r] != 0 && l < r-1 && a[r] == a[r-1]){
					cnt_r++; r--;
				}
				res += cnt_l*cnt_r;
				l++; r--;
			}
		else if(a[l] + a[r] > 0) r--;
		else l++;
	}
	if(cnt >= 2) cout << res + C(2,cnt);
	else cout << res;
    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
