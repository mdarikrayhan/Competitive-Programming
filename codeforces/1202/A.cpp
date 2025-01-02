
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define F first
#define S second
#define ld long double
using state = pair<int,int>;
int ans[(int)1e7];

void solve(){
	string s,t;
	cin >> s>>t;
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	int fs = -1,ft=-1;
	for(int i = 0; i < t.size(); i++){
		if(t[i]=='1'){ft = i;break;}
	}
	for(int i = 0; i < s.size(); i++){
		if(s[i]=='1' && i>=ft){fs = i;break;}
	}
	cout<<fs-ft<<'\n';
	
}	

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
