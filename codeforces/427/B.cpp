#include <bits/stdc++.h>
using namespace std;
#define F16 ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define cin(v) for (auto&i:v) cin >> i;
#define all(v) v.begin(), v.end()
#define  int long long
const int n = 1e7+6;
bool isprime[n];
ll fixMod(ll a , ll b){
    return (a%b+b)%b;
}
vector<ll>GetMultiples(int n ,int x){
    vector<long long>v;
    for(int m =x;m<=n;m+=x){
        v.push_back(m);
    }
    return v;
}
bool is_prime(int n){
    if(n==1)return false;
    bool flag = 0;
    for(int i =2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void sieve(){
    // O(N) -- O(log(logN))
    fill(isprime,isprime+n,true);
    isprime[0]= false;
    isprime[1]= false;
    for(int i=2;i*i<n;i++){
        if(isprime[i]){
            for(int m  = i*i;m<n ;m+=i){
                isprime[m] = false;
            }
        }
    }
}
ll LCM(ll a,ll b){
    return a*(b/__gcd(a,b));
}
long long nCr(int n , int r){
    if(r>n)return 0ll;
    long long res = 1;
    for(int i =0;i<r;i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}
vector<int> get_divisors(int m) {
    vector<int> v;
    for (int i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            v.push_back(i);
            if (i * i != m)v.push_back(m / i);
        }
    }
    return v ;
}
string GetBinary(int x){
    string s = "";
    while(x>0){
        s+= to_string(x%2);
        x/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
vector<int> primeFactorization(int n) {
    vector<int> factors;
    for (int i = 2 ; i  <= n/i ; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}
int32_t main(){
    F16
    int n , t , c;cin>>n>>t>>c;
    vi v(n);
    cin(v);
    int  counter =  0 , res =0 ;
    for(int i =0;i<n;i++){
        if(v[i]<=t){
            counter++;
        }else {
            counter = 0;
        }
        if(counter>=c)res++;
    }
    cout<<res;
    return 0;
}