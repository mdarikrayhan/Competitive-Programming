#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define PB push_back
#define FS first
#define SD second
#define ary(k) array<int,k>
template<class A,class B> void cmx(A& x, B y) {x=max<A>(x,y);}
template<class A,class B> void cmn(A& x, B y) {x=min<A>(x,y);}
typedef pair<int, int> pii;
typedef vector<int> vi;
struct SievePrimeFactoring {
  vector<bool> isPrime; vector<int> primes, SPF, phi; vector<char> mobius;
  SievePrimeFactoring(int N)
      : isPrime(N + 1, true), SPF(N + 1, 0), phi(N + 1, 0), mobius(N + 1, 1) {
    isPrime[0] = isPrime[1] = false; phi[1] = 1; for (int i = 2; i <= N; i++) {
      if (isPrime[i]) {
        primes.push_back(SPF[i] = i); phi[i] = i - 1; mobius[i] = -1;
      }
      for (int p : primes) {
        if (i * p > N) break;
        isPrime[i * p] = false; SPF[i * p] = p;
        if (i % p == 0) { phi[i * p] = phi[i] * p; mobius[i * p] = 0; break; }
        phi[i * p] = phi[i] * phi[p]; mobius[i * p] = mobius[i] * -1;
      }
    }
  }
  vector<int> primeFactor(int x) {
    vector<int> ret; while (x > 1) { ret.push_back(SPF[x]); x /= SPF[x]; }
    return ret;
  }
  vector<pair<int, int>> primeFactorWithCount(int x) {
    vector<pair<int, int>> ret; while (x > 1) {
      ret.emplace_back(SPF[x], 0);
      for (int spf = SPF[x]; x % spf == 0; x /= spf) ret.back().second++;
    }
    return ret;
  }
};
const int MM = 3e5+5;
int n,a[MM],pos[MM],dp[MM];
signed main() {
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    SievePrimeFactoring pf(MM);
    cin >> n;
    rep(i,1,n+1){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    rep(i,1,n+1){
        pos[a[i]] = i;
    }
    int ans = 0;
    for(int d = MM-1; d >= 1; d--){
        int cur = 0,num = 0;
        for(int i = d; i < MM; i += d)if(pos[i]){
            cur += pos[i]*num;
            num++;
        } 
        for(int i = d; i < MM; i += d)if(pos[i]){
            num--;
            cur += -(pos[i]+1)*num;
        } 
        dp[d] = cur;
        for(int i = 2*d; i < MM; i += d) dp[d] -= dp[i];
    }
    cout << dp[1] << "\n";
}
