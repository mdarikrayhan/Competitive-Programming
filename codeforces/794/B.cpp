  ///    freopen("input.txt", "r", stdin);   ///
///    freopen("output.txt", "w", stdout);      ///
#include<bits/stdc++.h>
/* order set */
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
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
	ld n, h;
	cin >> n >> h;
	ld S = h / 2.0, S1 = S / n;
	ld used = 0.0;	
	for(int i = 0; i < n - 1; i ++){
		ld l = 0.0, r = h; 
		for(int j = 0; j < 400; j ++){
			ld mid = (l + r) / 2.0;
			ld S2 = mid * mid / h * 0.5; 
			if(S2 - used >= S1){
				r = mid;
			}
			else{
				l = mid;
			}
		}
		used += S1;
		cout << fixed << setprecision(12);
		cout << l << ' ';
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