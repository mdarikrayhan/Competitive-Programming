#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int N = 1e3+2;
int n;
int dp[N];
void solve(){
    cin>>n;
    string s;
    cin>>s;
    int l=0,r=s.size()-1;
    char c1=s[l++],c2=s[r--];
    while (s[l]==c1){
        l++;
    }
    while (s[r]==c2){
        r--;
    }
    if(c1==c2){
        cout<<(l+1)*(s.size()-r)%998244353;
    }
    else {
        cout << (l + s.size() - r)%998244353 ;
    }

}
signed main() {FAST
    int t =1;
//    cin>>t;
    while (t--){
       solve();
    }
    return 0;
}

	 	 	 				 	    		  		  				 		