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
	map <ll, ll> mp_x, mp_y;
	for(int i = 0; i < m; i ++){
		ll x, y;
		cin >> x >> y;
		mp_x[x] ++, mp_y[y] ++;
		ll kol = mp_y.size() * n + mp_x.size() * n - mp_x.size() * mp_y.size();
		cout << n * n - kol << ' ';
	}
}
int main(){ 	
    ICC
    ll test = 1;
    ///cin >> test;
    while(test --){
        proga();
    }
} 