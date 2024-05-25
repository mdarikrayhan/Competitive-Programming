#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int

void update(int k, int v, vector<int> &bit, int n){
    while(k <= n){
        bit[k] += v;
        k += (k&(-k));
    }
}

int query(int k, vector<int> &bit, int n){
    int res = 0;
    while(k > 0){
        res += bit[k];
        k -= (k&(-k));
    }
    return res;
}

int32_t main(){
    FIO;
    int TC = 1;
    // cin>>TC;
    while(TC-->0){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<vector<int>> dp(n, vector<int>(k+2, 0));
        vector<vector<int>> bit(k+2, vector<int>(n+1, 0));

        for(int i=0;i<n;i++){
            for(int j=1;j<=k+1;j++){
                if(j == 1){
                    dp[i][j] = 1;
                    update(a[i], 1, bit[j], n);
                }
                else{
                    dp[i][j] = query(a[i]-1, bit[j-1], n);
                    update(a[i], dp[i][j], bit[j], n);
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans += dp[i][k+1];
        }
        cout<<ans<<'\n';        
    }
    return 0;
}