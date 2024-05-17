#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
const int mx = 4e6 ;
#define pb push_back
const int mod = 1e9+7;

 
int32_t main(){
		int t=1; cin >> t;
		while(t--){
			int n, m; cin >> n >> m;
			string s;	cin >> s;
			int left=0, up=0;
			int mn_l = 0, mx_l = 0, mn_u = 0, mx_u = 0;
			
			int ans_x =1, ans_y = 1;
			for(int i=0; i<s.length(); i++){
				if(s[i]=='L'){
					left--;
				} else if(s[i] == 'R'){
					left++;
				} else if(s[i] == 'U'){
					up++;
				} else if(s[i]=='D'){
					up--;
				}
				mn_l = min(left, mn_l);
				mx_l = max(left, mx_l);
				mx_u = max(up, mx_u);
				mn_u = min(up, mn_u);
				
				if(mx_l - mn_l + 1 > m or mx_u - mn_u + 1 > n) break;
				else{
					ans_x = abs(mn_l) + 1;
					ans_y = abs(mx_u) + 1;
				}
			}
			cout << ans_y << " " << ans_x << "\n";
			
		
		}
		
}