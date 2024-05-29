#include<bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 110;
const int mod = 1e9 + 7;

ll f[N][N][N];
ll fib[N], p[N];

ll qpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void work(){
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    fib[0] = fib[1] = 1;
    p[0] = p[1] = 2;

    for(int i = 2; i <= m; i++){
        fib[i] = (fib[i - 1] + fib[i - 2]) % (mod - 1);
        p[i] = qpow(2, fib[i]);
    }

    for(int i = 1; i <= n; i++){
        f[0][i][i] = (s[i - 1] == '0');
        f[1][i][i] = (s[i - 1] == '1');
    }

    for(int i = 2; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = j; k <= n; k++){
                f[i][j][k] = (f[i][j][k] + f[i - 1][j][k] * ((k == n) ? p[i - 2] : 1) % mod) % mod;
                f[i][j][k] = (f[i][j][k] + f[i - 2][j][k] * ((j == 1) ? p[i - 1] : 1) % mod) % mod;

                for(int l = j; l < k; l++){
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j][l] * f[i - 2][l + 1][k] % mod) % mod;
                }
            }
        }
    }

    cout << f[m][1][n] << '\n';
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr);

    int T = 1; //cin >> T;
    while(T--) work();

    return 0;
}