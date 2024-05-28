#include "bits/stdc++.h"
using namespace std;

#ifdef N_N_C
#include "debug.h"
#else
#define cebug(...) "Arya"
#endif

#define int long long

const int N=1e5+5;
const int mod=1e9+7;

int n,ans;
int grundy(int x){
	if(x<4) return 0;
	if(x<16) return 1;
	if(x<82) return 2;
	if(x<82*82) return 0;
	if(x<15*15*15*15+1) return 3;
	if(x<1ll*(15*15*15*15+1)*(15*15*15*15+1)) return 1;
	return 2;
}
void sol(){
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		ans^=grundy(x);
	}
	if(ans) cout<<"Furlo";
	else cout<<"Rublo";
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int tt=1;
    //cin>>tt; 
    while(tt--){
    	sol();
    }
    cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
    return 0;
}