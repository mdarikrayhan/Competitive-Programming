    #include <bits/stdc++.h>
 
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
 
    using namespace std;
    using namespace __gnu_pbds;
 
    #define int long long
    #define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
    // typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
 
    #define ld long double
    #define lcm(a, b) (a*b)/__gcd(a,b)
    #define endl "\n"
 
    mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
    const int N=(1e5+5), mod=1e9+7;
 
    int spf[N];
    bool seive[N];
    vector<int> primes;
    void pre(){for(int i = 2; i < N; ++i){seive[i] = true;}for(int i = 2; i < N; ++i){if (seive[i]) {primes.push_back(i);for(int j = i *i; j < N; j += i){seive[j] = false;}}}}
    void siev(){for(int i=2; i< N; i++){spf[i] = i;}for (int i=4; i< N; i+=2) spf[i] = 2;for (int i=3; i*i< N; i++){if (spf[i] != i) continue;for (int j = i*i; j < N; j += i){if (spf[j] == j) spf[j] = i;}}}
    vector<int> getFactorization(int x){vector<int> ret; while (x != 1) {ret.push_back(spf[x]);x = x / spf[x];}return ret;}
 
    /*/-----------------------------Code begins----------------------------------/*/

    void error(){
        int r, g; cin>>r>>g;
        vector<vector<int>> dp(2, vector<int>(r+1));

        dp[0][0] = 1; 
        int h = 1;

        for(int i=1000; i>=0; i--){
            if(i*(i+1)/2 <= (r + g)){
                h = i;
                break;
            }
        }
        for(int i=1; i<=h; i++){
            for(int j=0; j<=r; j++){
                int green = (i * (i+1) / 2) - j;
                if(green > g){
                    dp[i % 2][j] = 0;
                    continue;
                }
                if(j < i) dp[i % 2][j] = dp[1 - (i % 2)][j];
                else dp[i % 2][j] = dp[1 - (i % 2)][j] + dp[1 - (i % 2)][j - i] % mod;
            }
        }
        int ans = 0;
        for(int i=0; i<=r; i++){
            int green = (h * (h+1) / 2) - i;
            if(green <= g) ans = (ans + dp[h % 2][i]) % mod;
        }
        cout << ans << endl;
    }
 
    signed main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){error();}
    return 0;
    }