#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define fore(i,e)  for(ll i=0;i<e;i++)
#define forn(i,d,e) for(ll i=d;i<e;i++)
#define test  int t;cin>>t; while(t--)
#define el endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long
#define INF 2e18
typedef pair<int,int>         pii;
typedef pair<ll,ll>           pll;
typedef vector<ll>            vl;
typedef vector<pll>           vpl;
typedef vector<pii>           vpi;
typedef vector<int>           vi;
//functions:
             
int count_primes(int n) {
    const int S = 10000;
                        
    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }
    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}
          
vector<long long> segmentedSieve(long long L, long long R) {
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
                     
    vector<long long> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
                         
    return isPrime;
}
            
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
               
void solve(){
    ll n,k;
    cin>>n>>k;
    if(n==k){
        cout<<"YES"<<endl;
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }
    if(n<k){
        cout<<"NO"<<endl;
        return;
    }
    if(k>(n+1)/2){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<2<<endl;
    cout<<n-k+1<<" "<<1<<endl;
}
               
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cout<<fixed<<setprecision(0);
test
{
     solve();
}
}