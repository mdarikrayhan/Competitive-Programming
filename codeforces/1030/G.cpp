#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int maxn = 2e6 + 5;
bool isPrime[maxn];
int primes[maxn], minp[maxn], id[maxn], cnt;
int mx1[maxn], mx2[maxn], c[maxn];
void init(){
    isPrime[1] = 1;
    for(int i = 2; i < maxn; i++){
        if (!isPrime[i]){
            id[i] = cnt;
            primes[cnt++] = i;
            minp[i] = i;
        } 
        for(int j = 0; i * primes[j] < maxn; j++){
            isPrime[i * primes[j]] = 1;
            minp[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}	

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    const int mod = 1e9 + 7;
    init();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        c[id[x]] += 1;
    }
    int ans = 1;
    int add = 0;
    for(int i = cnt - 1; i >= 0; i--){
        if (mx1[i] != 0){
            for(int j = 0; j < mx1[i]; j++){
                ans = 1LL * ans * primes[i] % mod;
            }
            if (c[i] >= 1){
                int t = primes[i] - 1;
                while(t != 1){
                    int p = minp[t], c = 0;
                    while(t % p == 0) t /= p, c += 1;
                    if (c >= mx1[id[p]]){
                        mx2[id[p]] = mx1[id[p]];
                        mx1[id[p]] = c;
                    }
                    else if (c > mx2[id[p]]){
                        mx2[id[p]] = c;
                    }
                }
            }
        }
        else{
            if (c[i] >= 1){
                ans = 1LL * ans * primes[i] % mod;
            }
            if (c[i] >= 2){
                int t = primes[i] - 1;
                while(t != 1){
                    int p = minp[t], c = 0;
                    while(t % p == 0) t /= p, c += 1;
                    if (c >= mx1[id[p]]){
                        mx2[id[p]] = mx1[id[p]];
                        mx1[id[p]] = c;
                    }
                    else if (c > mx2[id[p]]){
                        mx2[id[p]] = c;
                    }
                }
            }
        }
    }
    for(int i = cnt - 1; i >= 0; i--){
        if (mx1[i] != 0){
            if (c[i] >= 1){
                bool ok = true;
                int t = primes[i] - 1;
                while(t != 1){
                    int p = minp[t], c = 0;
                    while(t % p == 0) t /= p, c += 1;
                    if (c > mx2[id[p]]){
                        ok = false;
                    }
                }
                if (ok) add = 1;
            }
            if (c[i] >= 2) add = 1;
        }
        else{
            if (c[i] >= 2){
                bool ok = true;
                int t = primes[i] - 1;
                while(t != 1){
                    int p = minp[t], c = 0;
                    while(t % p == 0) t /= p, c += 1;
                    if (c > mx2[id[p]]){
                        ok = false;
                    }
                }
                if (ok) add = 1;
            }
            if (c[i] >= 3) add = 1;
        }
    }
    cout << ans + add << '\n';

}