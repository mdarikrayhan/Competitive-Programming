#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e5 + 10 ; 
int l[N] , r[N] ,  cl[N] , cr[N] , n , a , b , k , q , tree[N];
signed main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k >> b >> a >> q ;
	for(int i = 1 ; i <= q ; i ++){
		int opt , x , y ;
		cin >> opt >> x ;
		if(opt == 1){
			cin >> y ; 
			int now = min(a , cl[x] + y) , delta = now - cl[x];
			cl[x] = now;            
			for (int i = x ; i <= n ; i += i & -i) l[i] += delta;            
			now = min(b , cr[x] + y) , delta = now - cr[x] , cr[x] = now;
			for (int i = x ; i > 0 ; i -= i & -i) r[i] += delta;
		}else{
			int res = 0;
			for (int i = x - 1 ; i > 0 ; i -= i & -i)res += l[i];
			for (int i = x + k ; i <= n ; i += i & -i)res += r[i];
			cout << res << '\n' ; 
		}
	}
	return 0;
}
	   	 	 			 		 			 			 	 	  	 	