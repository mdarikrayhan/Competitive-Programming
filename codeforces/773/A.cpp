#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#endif

#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define int long long
const int mod = 1e9 + 7, INF = 1e15 + 5, N = 1e9;

bool check(int x, int y, int p, int q, int t){
     return p*t >= x && t*(q - p) >= y - x;
}


void solve(int cs){
    int x, y, p, q;
    cin >> x >> y >> p >> q;

    int low = 0, high = N;

    if(!check(x, y, p, q, high)){
        cout<<-1<<'\n';
        return;
    }

    int ans = N;
    while(low <= high){
        int mid = (low + high)/2;
        if(check(x, y, p, q, mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    debug(ans);
    cout<<ans * q - y <<'\n';

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int TEST = 1;
    cin >> TEST;

    for (int i = 1; i <= TEST; i++) {
       // cout << "Case " << i << ":"<<'\n';
        solve(i);
    }
    #ifndef ONLINE_JUDGE
    //   cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}
  								  		  	   	 	  					