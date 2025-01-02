#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define inf ((int)2e9 + 10)
#define nl '\n'
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define PI acos(-1)
#define ordered_set tree<ll ,  null_type ,  less_equal<> ,  rb_tree_tag ,  tree_order_statistics_node_update>

vector <int> dx {0, 0, 1, -1, 1, 1, -1, -1}, dy {1, -1, 0, 0, 1, -1, 1, -1};
//vector<int> dx{1, 1, -1, -1, 2, 2, -2, -2}, dy{2, -2, 2, -2, 1, -1, 1, -1};

void file_fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 101;
int n, arr[10], dp[2][N], c[N][N];

void some_code(){
    cin >> n;

    for(auto& i : arr)
        cin >> i;

    dp[0][0] = c[0][0] = 1;
    
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++)
            c[i][j] = ((j ? c[i - 1][j - 1] : 0) + c[i - 1][j]) % MOD;

    for(int d = 9; d >= 0; d--){
        bool zero = !d;
        for(int i = n; i >= 0; i--) if(dp[0][i])
            for(int cnt = arr[d]; i + cnt <= n; cnt++)
                dp[1][i + cnt] = (dp[1][i + cnt] + 1ll * dp[0][i] * c[i + cnt - zero][cnt]) % MOD;
        
        for(int i = 0; i <= n; i++){
            dp[0][i] = dp[1][i];
            dp[1][i] = 0;
        }  
    }    

    int ans = 0;
    for(int i = 0; i <= n; i++)
        ans = (ans + dp[0][i]) % MOD;

    cout << ans;
}

int main(){
    file_fastIO();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int TC = 1;

    // cin >> TC;

    for(int i = 1; i <= TC; i++){
//        cout << "Case " << i << ": ";
        some_code();
        cout << nl;
    }

    return 0;
}
	 	  		 		 	   			  		    		 		