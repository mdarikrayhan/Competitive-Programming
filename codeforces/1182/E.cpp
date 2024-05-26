#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7, MOD2 = 1e9 + 6;
ll n, f1, f2, f3, c;

ll sum(ll x, ll y){
    return (x + y + MOD2) % MOD2;
}
ll mul(ll x, ll y){
    return (x * y) % MOD2;
}
ll mul2(ll x, ll y){
    return (x * y) % MOD;
}
ll power(ll x, ll y){
    if(y == 0){
        return 1ll;
    }
    ll res = power(x, y / 2);
    return (y % 2 == 0)? mul2(res, res): mul2(mul2(res, res), x);
}
ll up(ll x, ll y){
    if(x % y == 0){
        return (x / y);
    }
    return ((x / y) + 1);
}

struct Matrix{
    int n, m;
    vector<vector<ll>> M;

    Matrix(){}
    Matrix(int sz, int v){
        n = sz;
        m = sz;
        M.resize(n);
        for(int i = 0; i < n; i++){
            M[i].clear();
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    M[i].push_back(v);
                }
                else{
                    M[i].push_back(0);
                }
            }
        }
    }

    void makke(vector<vector<ll>> vec){
        n = (int)vec.size();
        m = 0;
        if(n > 0){
            m = (int)vec[0].size();
        }
        M = vec;
    }
    void upd(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                M[i][j] %= MOD;
            }
        }
    }
    void output(){
        cout << "--------------------\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << M[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << "--------------------\n";
    }
    
    vector<ll> &operator [] (int idx){
        return M[idx];
    }
};
Matrix operator* (Matrix a, Matrix b){
    vector<vector<ll>> vec;
    vec.resize(a.n);
    for(int i = 0; i < a.n; i++){
        for(int j = 0; j < b.m; j++){
            ll tmp = 0;
            for(int k = 0; k < a.m; k++){
                tmp = sum(tmp, mul(a[i][k], b[k][j]));
            }
            vec[i].push_back(tmp);
        }
    }
    Matrix res;
    res.makke(vec);
    res.upd();
    return res;
}
Matrix operator^ (Matrix a, ll b){
    if(b == 0){
        return Matrix(a.n, 1);
    }
    Matrix res = a ^ (b / 2);
    return (b % 2 == 0)? res * res: res * res * a;
}
Matrix operator% (Matrix a, Matrix b){
    vector<vector<ll>> vec;
    vec.resize(a.n);
    for(int i = 0; i < a.n; i++){
        for(int j = 0; j < b.m; j++){
            ll tmp = 1;
            for(int k = 0; k < a.m; k++){
                tmp = mul2(tmp, power(a[i][k], b[k][j]));
            }
            vec[i].push_back(tmp);
        }
    }
    Matrix res;
    res.makke(vec);
    res.upd();
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> f1 >> f2 >> f3 >> c;
    Matrix base;
    vector<vector<ll>> tmp1;
    tmp1.push_back(vector<ll>());
    tmp1[0].push_back(f3);
    tmp1[0].push_back(f2);
    tmp1[0].push_back(f1);
    tmp1[0].push_back(1);
    tmp1[0].push_back(c);
    base.makke(tmp1);
    Matrix update(5, 0);
    update[0][0] = 4;
    update[0][1] = 2;
    update[0][2] = 1;
    update[1][0] = 3;
    update[1][1] = 2;
    update[1][2] = 1;
    update[2][0] = 2;
    update[2][1] = 1;
    update[2][2] = 1;
    update[3][0] = 4;
    update[3][1] = 2;
    update[3][2] = 1;
    update[3][3] = 1;
    update[4][0] = 14;
    update[4][1] = 6;
    update[4][2] = 2;
    update[4][3] = 6;
    update[4][4] = 1;
    Matrix res = (base % (update ^ (up(n, 3) - 1)));
    if(n % 3 == 0){
        cout << res[0][0] << '\n';
    }
    else if(n % 3 == 1){
        cout << res[0][2] << '\n';
    }
    else{
        cout << res[0][1] << '\n';
    }
}