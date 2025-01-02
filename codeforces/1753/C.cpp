// __builtin_clz(x): the number of zeros at the beginning of the number 
// __builtin_ctz(x): the number of zeros at the end of the number
// __builtin_popcountll(x): the number of ones in the number
// __builtin_parity(x): the parity (even or odd) of the number of ones
// __builtin_ffs(int) finds the index of the first (most right) set bit
// *find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
// order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define nl "\n"
#define pb push_back
#define eb emplace_back
#define Sort(a) sort(a.begin(),a.end())
#define vi vector<int>
#define vll vector<long long>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define inf numeric_limits<long long>::max()
#define int ll
// const long long MOD = 1000000007;
// const long long mod = 998244353;
ll modInverse(ll a, ll m);
ll power(ll x, ll y, ll M);

const int MOD = 998244353;
struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, mod_int &m) {
        return stream>>m.val;   
    }
};

// Problem solving without learning is pointless
// Always have contest mindset

void solve()
{
    int n;
    cin>>n;
    int a[n];
    int c0=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c0+=a[i]==0;
    }


    int dp[c0+1];
    dp[c0]=0;
    int x=0;
    for(int i=0;i<c0;i++){
        if(a[i] == 0)
            x++;
    }

    for(int i=c0-1;i>=x;i--){
        int y = ((c0-i)*(c0-i))%MOD;
        y *= modInverse((n*(n-1)/2)%MOD, MOD);
        y %= MOD;
        dp[i] = (modInverse(y, MOD)+dp[i+1]);
        dp[i] %= MOD;
    }

    cout << dp[x] << nl;

}



signed main(){
    clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    cin>>tt;
    while(tt--)
    {
        //cout<<"TEST # "<<tt<<nl;
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"Time taken: "<<setprecision(10)<<((double)(clock()-tStart)/CLOCKS_PER_SEC)<<" s"<<endl;    
    #endif
}



ll modInverse(ll a,ll m)
{
    return power(a, m-2, m);
}

ll power(ll x, ll y, ll M)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2, M) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}