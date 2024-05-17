#include<bits/stdc++.h>
#define int long long int
#define fr(i, n) for(int i = 0; i < n; i++)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define pii pair<int, int>
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define vint vector<int>
#define all(arr) arr.begin(), arr.end()
using namespace std;
 
void solve(){
    int n, h; cin>>n>>h; vint arr(n); fr(i, n) cin>>arr[i];
    sort(all(arr));
	int ans = 0;
	fr(k, 3){
		int ch = 0; int idx = 0;
		int cpy = h;		
		while(idx < n){
			if(cpy > arr[idx]){
				cpy += arr[idx++]/2;
			}
			else if(ch == 3) break;
			else{
				if(ch == k) cpy *= 3;
				else cpy *= 2;
				ch++;
			}
		}
		ans = max(ans,idx);
	}
	cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
return 0;
}