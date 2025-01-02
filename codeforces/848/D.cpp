// LUOGU_RID: 156957735
#include <bits/stdc++.h>
#define File(name) freopen(#name".in", "r", stdin); freopen(#name".out", "w", stdout);
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<typename T>
inline T read(){
    T n = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return f * n;
}
template<typename T>
void write(T n){
    if(n < 0) return putchar('-'), write(-n);
    if(n / 10) write(n / 10);
    putchar(n % 10 + '0');
}
void input() {}
template<typename Type, typename... Types>
void input(Type &arg, Types &...args){
    arg = read<Type>();
    input(args...);
}
namespace Main{
    const int MOD = 1e9 + 7;
    const int N = 55;
    int n, m;
    ll inv[N], f[N][N], g[N][N], sf[N][N], sg[N][N], g_binom[N][N][N];
    void Main(){
        inv[1] = 1;
        for(int i = 2; i < N; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        input(n, m);
        f[0][1] = 1, sf[0][1] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = i; j >= 1; j--){
                for(int k = 0; k < i; k++){
                    (sg[i][j] += sf[k][j] * sf[i - 1 - k][j]) %= MOD;
                }
                g[i][j] = (sg[i][j] - sg[i][j + 1] + MOD) % MOD;
                g_binom[i][j][0] = 1;
                for(int k = 1; k <= n; k++){
                    g_binom[i][j][k] = g_binom[i][j][k - 1] * (g[i][j] + k - 1) % MOD * inv[k] % MOD;
                }
                // fprintf(stderr, "g[%d][%d] = %lld\n", i, j, g[i][j]);
                for(int a = n; a >= i; a--) for(int b = n + 1; b >= j; b--){
                    for(int k = 1; a - k * i >= 0 && b - k * j >= 1; k++){
                        (f[a][b] += f[a - k * i][b - k * j] * g_binom[i][j][k]) %= MOD;
                    }
                }
            }
            for(int j = i + 1; j >= 1; j--){
                // fprintf(stderr, "f[%d][%d] = %lld\n", i, j, f[i][j]);
                sf[i][j] = (sf[i][j + 1] + f[i][j]) % MOD;
            }
        }
        write(f[n][m]);
        return;
    }
} // namespace Main
int main(){
#ifdef Liuxizai
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif // Liuxizai
    Main::Main();
    return 0;
}