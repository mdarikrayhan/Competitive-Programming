//AshrafSustS19


#include<bits/stdc++.h>

using namespace std;
using ll = long long int;


ll MOD = 998244353;


//memorization for factorial
vector<ll> fac(2000001, 0), facinv(2000001, 0);


ll power(ll num, ll pow)
{
    ll res = 1;
    num = num % MOD;
    while (pow > 0)
    {
        if (pow & 1)
            res = (res * num) % MOD;
        pow >>= 1;
        num = (num * num) % MOD;
    }
    return res;
}   

ll modInverse(ll num)
{
    return power(num, MOD - 2);
}

ll getFac(ll n)
{
    if (n == 0) return 1;
    if (fac[n] != 0)
        return fac[n];
    else
        return fac[n] = (n * getFac(n - 1)) % MOD;
}

ll getFacInv(ll n){
    if (n == 0) return 1;
    if (facinv[n] != 0)
        return facinv[n];
    else 
        return facinv[n] = modInverse(getFac(n));
}

ll ncr(ll n, ll r)
{
    if (n < r || r < 0 || n < 0)
        return 0;
    if (r == 0)
        return 1;
    return (getFac(n) * ((getFacInv(r) * getFacInv(n - r)) % MOD)) % MOD;
}



ll N, n;
vector<vector<ll>> MEM;
vector<ll> lp2((1ll << 20) + 5, -1);

ll getP2(ll p){
    if (lp2[p] != -1){
        return lp2[p];
    }
    if (p == 0){
        return lp2[p] = 1;
    }
    return lp2[p] = (getP2(p - 1) * 2) % MOD;
}

ll dp(ll ind, ll cnt){
    if (ind > n){
        return (cnt == N + 1);
    }
    if (MEM[cnt][ind] != -1){
        return MEM[cnt][ind];
    }
    ll p1 = 0, p2 = 0;
    ll totnd = (1ll << cnt);
    if (ind >= totnd){
        ll cnd = (1ll << (cnt - 1)) - 1;
        ll av = ind - totnd + cnd;
        ll mul = getFac(cnd + 1) * ncr(av, cnd) % MOD;
        // ll mul = getFac(cnd + 1);
        mul = (mul * 2) % MOD;
        p1 = dp(ind + 1, cnt + 1) * mul % MOD;
    }
    p2 = dp(ind + 1, cnt);
    return MEM[cnt][ind] = (p1 + p2) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    n = 1ll << N;
    MEM.resize(N + 2, vector<ll> (n + 1, -1));
    for (int i = 0; i < n; i++){
        ll res = dp(n - i + 1, 1);
        cout << res << "\n";
    }   
    

    
    
}