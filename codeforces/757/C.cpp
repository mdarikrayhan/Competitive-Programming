// FREE palastine 7 / 10 / 2023
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ll long long
#define ld long double
#define ull unsigned long long
#define fix(x) setprecision(x) << fixed
#define ceil1(w, m) (((w) / (m)) + ((w) % (m) ? 1 : 0))
#define all(x) x.begin(), x.end()
#define add_mod(a , b , m) ( (a % m) + (b % m) ) % m
#define mul_mod(a , b , m) ( (a % m) * (b % m) ) % m
#define PI acos(-1)
#define endl "\n"
#define sz size()
ll const INF = 1LL << 60;
//*************************************************************************
void RAGNAR()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
template<typename T >istream& operator>>(istream &in, vector<T> &v)
{
    for (T &i : v)
        cin >> i;
    return in;
}
//***********************************************************************
constexpr ll mod1 = 1e9 + 7;
constexpr ll mod2 = 1e9 + 9;
constexpr ll p1 = 31;
constexpr ll p2 = 37;
constexpr ll N = 1e6 + 1;
ll p_pow[2][N] , inv[2][N];
ll fact[N];
constexpr ll p_1inv = 233333335;
constexpr ll p_2inv = 972222231;

ll power(ll a , ll b , ll m){ // O(logb)
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

void pre(){
    p_pow[0][0] = p_pow[1][0] = 1;
    inv[0][0] = inv[1][0] = 1;
    int p1inv = power(p1 , mod1 - 2 , mod1);
    int p2inv = power(p2 , mod2 - 2 , mod2);
    for(int i = 1; i < N; i++){
        p_pow[0][i] = (p_pow[0][i - 1] % mod1 * p1 % mod1) % mod1;
        p_pow[1][i] = (p_pow[1][i - 1] % mod2 * p2 % mod2) % mod2;
        inv[0][i] = (inv[0][i - 1] % mod1 * p1inv % mod1) % mod1;
        inv[1][i] = (inv[1][i - 1] % mod2 * p2inv % mod2) % mod2;
    }
    fact[0] = 1;
    for(ll i = 1; i < N; i++){
        fact[i] = (fact[i - 1] % mod1 * i % mod1) % mod1;
    }
}

pair<ll , ll> hash_function(vector<int>& v){
    ll hash1 = 0 , hash2 = 0;
    for(int i = 0; i < v.size(); i++){
        hash1 = (hash1 + (v[i] * p_pow[0][i] % mod1)) % mod1;
        hash2 = (hash2 + (v[i] * p_pow[1][i] % mod2)) % mod2;
    }
    return {hash1 , hash2};
}



void nane(){
    pre();

    int n , m;
    cin >> n >> m;
    vector<vector<int>> v(m + 1);
    for(int i = 1; i <= n; i++){
        int g;
        cin >> g;
        while(g--){
            int x;
            cin >> x;
            v[x].push_back(i);
        }
    }
    map<pair<ll , ll> , ll> mp;
    for(int i = 1; i <= m; i++){
        if(v[i].size() == 0){
            mp[{0 , 0}]++;
            continue;
        }
        pair<ll , ll> hash = hash_function(v[i]);
        mp[hash]++;
    }
    ll ans = 1;
    for(auto x : mp){
        ans = (ans % mod1 * fact[x.second] % mod1) % mod1;
    }
    cout << ans << endl;
    

    
    

}

signed main()
{
    RAGNAR();
    ll t = 1;
    //cin >> t;  
    int i = 1;
    while (t--)
    {
        // cout << "Case #" << i++ << ": ";
        // cout << "Case " << i++ << ":\n";
        nane();
        // timee;
    }
    return 0;
}