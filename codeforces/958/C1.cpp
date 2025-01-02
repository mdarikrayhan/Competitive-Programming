  ///    freopen("input.txt", "r", stdin);   ///
///    freopen("output.txt", "w", stdout);      ///
#include<bits/stdc++.h>
/* order set */
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// (set) st.order_of_key(x) --> kol_elementov < x
// (set) st.order_by_find(x) --> find(x);
#define ll long long
#define ld long double
#define ICC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define str string
#define pb push_back
#define ppb pop_back()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ull unsigned long long
using namespace std;
void proga(){
	ll n, m;
	cin >> n >> m;
	ll a[n], pref[n + 1] = {}, suff[n + 1] = {};
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i ++){
		pref[i + 1] = pref[i] + a[i];
	}
	for(int i = n - 1; i > 0; i --){
		suff[i] = suff[i + 1] + a[i];
	}
	ll mx = -1e18;
	for(int i = 0; i < n; i ++){
		mx = max(mx, pref[i] % m + suff[i] % m);
	}
	cout << mx << '\n';
}
int main(){ 	
    ICC
    ll test = 1;
    ///cin >> test;
    while(test --){
        proga();
    }
} 