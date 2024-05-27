#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 5e1 + 6, MAXM = 5e3 + 10, MOD = 1e9 + 7, INF = 1e18, Lg = 32;
ll dp[MAXN * 3][MAXN][MAXN];
ll cnt[2];
ll ch[MAXN][MAXN];
int n, k;

ll sum(ll x, ll y){
    return (x + y + MOD) % MOD;
}
ll mul(ll x, ll y){
    return (x * y) % MOD;
}
ll power(ll a, ll b){
    vector<ll> vec;
    vec.push_back(a);
    ll tmp = a;
    for(int i = 1; i < Lg; i++){
        tmp = mul(tmp, tmp);
        vec.push_back(tmp);
    }
    ll res = 1;
    for(int i = Lg - 1; i >= 0; i--){
        if((b >> i) & 1){
            res = mul(res, vec[i]);
        }
    }
    return res;
}
ll inv(ll a, ll b){
    return mul(a, power(b, MOD - 2));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < MAXN; i++){
        ch[i][0] = 1;
    }
    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j < MAXN; j++){
            ch[i][j] = sum(ch[i - 1][j - 1], ch[i - 1][j]);
        }
    }
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 50){
            cnt[0]++;
        }
        else{
            cnt[1]++;
        }
    }
    dp[0][cnt[0]][cnt[1]] = 1;
    for(int i = 0; i < (MAXN * 3) - 1; i++){
        for(int j = 0; j <= cnt[0]; j++){
            for(int x = 0; x <= cnt[1]; x++){
                if(i % 2 == 1){
                    for(int v1 = 0; v1 <= cnt[0] - j; v1++){
                        for(int v2 = 0; v2 <= cnt[1] - x; v2++){
                            if(v1 + v2 > 0 && (v1 * 50) + (v2 * 100) <= k){
                                dp[i + 1][v1 + j][v2 + x] = sum(dp[i + 1][v1 + j][v2 + x], 
                                mul(dp[i][j][x], mul(ch[cnt[0] - j][v1], ch[cnt[1] - x][v2])));
                            }
                        }
                    }
                }
                else{
                    for(int v1 = 0; v1 <= j; v1++){
                        for(int v2 = 0; v2 <= x; v2++){
                            if(v1 + v2 > 0 && (v1 * 50) + (v2 * 100) <= k){
                                dp[i + 1][j - v1][x - v2] = sum(dp[i + 1][j - v1][x - v2], 
                                mul(dp[i][j][x], mul(ch[j][v1], ch[x][v2])));
                            }
                        }
                    }
                }
            }
        }
    }
    ll ans = 1;
    while(ans < (MAXN * 3) && dp[ans][0][0] == 0){
        ans += 2;
    }
    if(ans < (MAXN * 3)){
        cout << ans << '\n' << dp[ans][0][0] << '\n';
        return 0;
    }
    cout << "-1\n0\n";//*/
}