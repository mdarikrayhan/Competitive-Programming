// LUOGU_RID: 160637647
#include <bits/stdc++.h>
using namespace std;
namespace Slongod{
constexpr int N = 4111 , M = 82222 , maxn = 8192 , mod = 998244353;
int pre[M] , inv[M];
inline int qkpow(int x , int y){int s; for(s=1;y;y/=2,x=1ll*x*x%mod){if(y&1){s=1ll*s*x%mod;}}return s;}
inline void init()
{
    pre[0] = 1; for (int i = 1; i <= maxn; i++){pre[i] = 1ll * pre[i-1] * i % mod;}
    inv[maxn] = qkpow(pre[maxn] , mod - 2); for (int i = maxn - 1; i >= 0; i--){inv[i] = 1ll * inv[i+1] * (i+1) % mod;}
}

//Poly
using poly = vector<int>;
int dp[M];
void initdp(){for (int i = 1; i < maxn; i++){dp[i] = ((dp[i>>1]>>1)|((i&1)<<(12)));}}
void ntt(poly &f , int opt)
{
    for (int i = 0; i < maxn; i++){if (dp[i] < i){swap(f[dp[i]] , f[i]);}}
    for (int i = 1; i < maxn; i <<= 1) {
        int w = qkpow(qkpow(3 , (mod - 1) / (i << 1)) , opt == -1 ? mod - 2 : 1);
        for (int j = 0; j < maxn; j += (i << 1)) {
            for (int l = 0 , now = 1; l < i; l++ , now = 1ll * now * w % mod) {
                int x = f[j+l] , y = 1ll * f[i+j+l] * now % mod;
                f[j+l] = (x + y) % mod; f[i+j+l] = (x - y + mod) % mod;
            }
        }
    }
    if (opt == -1) {
        int invv = qkpow(maxn , mod - 2);
        for (int i = 0; i < maxn; i++) {
            f[i] = 1ll * f[i] * invv % mod;
        }
    }   
}
constexpr int mud = 1e9+7 , mmaxn = 4096;
inline int fastpow(int x , int y){int s;for(s=1;y;y/=2,x=1ll*x*x%mud){if(y&1){s=1ll*s*x%mud;}}return s;}
poly mul(int f[] , int g[])
{
    poly F; F.resize(maxn); for (int i = 0; i < mmaxn; i++){F[i] = f[i];} ntt(F , 1);
    poly G; G.resize(maxn); for (int i = 0; i < mmaxn; i++){G[i] = g[i];} ntt(G , 1);
    for (int i = 0; i < maxn; i++){F[i] = 1ll * F[i] * G[i] % mod;} ntt(F , -1); return F;
}
int n , x , ans , f[N][N] , g[N] , h[N];
void solve(int op)
{
    memset(f , 0 , sizeof(f)); f[1][0] = 1;
    for (int i = 2; i <= mmaxn; i++) {
        for (int j = 0; j <= (i - 2);j++) {
            if ((i & 1) == op) { //小数
                if (j){f[i][j-1] = (f[i][j-1] + 1ll * f[i-1][j] * j) % mod;}
                f[i][j] = (f[i][j] + 1ll * f[i-1][j] * (i - j)) % mod;
            } else { //大数
                f[i][j+1] = (f[i][j+1] + 1ll * f[i-1][j] * (j+2)) % mod;
                f[i][j+2] = (f[i][j+2] + 1ll * f[i-1][j] * (i - 2 - j)) % mod;
            }
        }
    }
    for (int m = 4-op; m <= n + 1; m += 2) {
        int i = m - 1 , k = n - i;
        memset(g , 0 , sizeof(g));
        memset(h , 0 , sizeof(h));
        for (int j = 0; j <= k; j++){g[j] = 1ll * inv[j] * inv[k-j] % mod;}
        for (int j = 0; j <= i - 1; j++){h[j] = 1ll * f[i][j] * pre[i-1-j] % mod * pre[j+1+k] % mod;}

        auto P = mul(g , h);
        for (int j = 0; j <= n - 1; j++) {
            P[j] = 1ll * P[j] * pre[k] % mod;
            if (i - 1 - j >= 0) {
                P[j] = 1ll * P[j] * inv[i-1-j] % mod * inv[j+1] % mod;
            } else {
                P[j] = 0;
            }
        }
        for (int j = k; j <= n - 1; j++) {
            ans = (ans + 1ll * P[j-k] * fastpow(x , n * m + j)) % mud;
        }
    }
}

int test[M] , tset[M];
void tt()
{
    initdp(); test[0] = 1; test[1] = 2; tset[0] = 2;
    auto p = mul(test , tset);
    for (int i = 0; i < 2; i++) {
        cerr << p[i] << ' ';
    }
}

void main()
{
    init(); initdp();
    cin >> n >> x;
    solve(0); solve(1);
    cout << ans << '\n';
}
}int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    return Slongod :: main(),0;
}