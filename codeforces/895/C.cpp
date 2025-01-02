#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const ll inf = 1e16;
const int N = 1e6;
const int mod = 1e9+7;
int n, k;
int cnt[N], a[N], m, f[N], dp[2][N];
ll sum[N], ans, pw[N];
int count_cs( ll x){
    int cnt = 0;
    while(x > 0){
        x /= 10;
        ++cnt;
    }
    return cnt;
}
vector<int> vi;
int get(int mid){
    int res = 0;
    for(int i = 1; i < (int)vi.size(); i ++){
        // khoang ma chua i cs => [vi[i-1], vi[i]-1]
        // danh so tu 0
        if(mid < vi[i]){
            res += i * (mid-vi[i-1]+1);
            break;
        }
        else{
            res += i * (vi[i]-vi[i-1]); 
        }
    }
    return res;
}
void sol(){
    cin >> n;
    
    for(int i = 2; i < 70; i ++){
        if(!a[i]){
            vi.pb(i);
            for(int j = i*2; j < 70; j += i)a[j] = 1;
        }
    }
    pw[0] = 1;
    for(int i = 1; i <= n; i ++){
        int x;
        pw[i] = pw[i-1] * 2 % mod;
        cin >> x;
        int mask = 0;
        for(int j = 0; j < (int)vi.size(); j ++){
            
            if(x % vi[j] == 0){
                
                int cnt = 0;
                while(x % vi[j] == 0){
                    cnt ^= 1;
                    x /= vi[j];
                }
                if(cnt)mask ^= (1<<j);
            }
        }
        f[mask] ++;
    }
    m = vi.size();
    
    dp[0][0] = 1;
    int id = 0;
    for(int i = 0; i < (1<<m); i ++){
        if(f[i] == 0)continue;
        memset(dp[id^1], 0, sizeof(dp[id^1]));
        for(int mask = 0; mask < (1<<m); mask ++){
            dp[id^1][mask] = (dp[id^1][mask] + dp[id][mask] * pw[f[i]-1] % mod);
            dp[id^1][mask^i] = (dp[id^1][mask^i] + dp[id][mask] * pw[f[i]-1] % mod);

        }
        id ^= 1;    
    }
    cout << dp[id][0]-1;
}
int main()
{
    #define task "test"
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ntest = 1;
    // cin >> ntest;
    while(ntest -- > 0)sol();
    return 0;
}
// 2 10 3 2 5 1
// 2 12 15 17 22 23
// i = 2
// k = 3
// j = 6
// sum[j] -sum[k] <= sum[k]-sum[i-1] k tang
 	 		 		  		 	 			 					 					