#include<bits/stdc++.h>
using namespace std;

#define int long long

int f(int x, int m){
    int ret = 0;
    while(x < m)
        ret += m - x, x *= 2;
    return ret;
}

signed main(){
    int n, m, cnt, a, res = 0;
    cin >> n >> m >> cnt, n--, cnt--;
    while(n--)
        cin >> a, cnt = __gcd(cnt, a - 1);
    while(!(cnt & 1))
        cnt /= 2;
    for(int i = 1; i * i <= cnt; i++){
        if(cnt % i == 0)
            res += f(i, m) + f(cnt / i, m);
        if(i * i == cnt)
            res -= f(i, m);
    }
    cout << res << endl;
    return 0;
}
 		  	  	 	 		 	       	   				