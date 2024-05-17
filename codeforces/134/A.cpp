#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define pp pop_back
#define int long long 
const int INF = 1e18-5;
const int MOD = 1e9+7;

// do something, stay focused
// look for stupid bugs
// guess, slow, stress
// don't overgeneralize
// don't rush
 
// don't waste time on standings
 
// SOLVE THE PROBLEM OR DIE TRYING
// THE SOLUTION IS ALWAYS SIMPLE
// THE CODE IS ALWAYS SHORT

void solve() {
     int n;
     cin >> n;
     vector <int> v(n);
     int sum = 0;
     for(int i=0;i<n;i++) {
          cin >> v[i];
          sum += v[i];
     }
     vector <int> find;
     int j = n-1;
     int sum1 = sum;
     for(int i=0;i<n;i++) {
     	if(n*v[i]==sum) {
     		find.pb(i+1);
		 }
     }
     cout << find.size() << "\n";
     for(int i=0;i<find.size();i++) {
          cout << find[i] << " ";
     }    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
    
    return 0;
}