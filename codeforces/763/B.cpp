/*   /\_/\
*   (= ._.)
*   / >  \>
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair <int,int> pi;
typedef set<int> si;
typedef set<long long> sll;
typedef unordered_map<long long,long long> ull;
#define f first
#define s second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;i++)
void printvec( vector<int> v){
     for(int i=0;i<v.size();i++){ cout<<v[i]<<" "; }
     cout<<endl;
}
ll gcd(ll a, ll b){
if(b == 0) return a;
return gcd(b, a % b);
}
ll lcm(ll a, ll b){

return a*b/gcd(a,b);
}
bool isPrime(ll n)
{
     if (n <= 1)
        return false;
for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 return true;
}
//Finding The Minimum x Such That f(x) = true
//returns the first x in the range [lo,hi] such that f(x) = true.
//if no such x exists,return hi+1.be careful
int first_true(int lo, int hi, function<bool(int)> f) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

//modint
const int MOD = 1e9 + 7;

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inver(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inver(b); }
//couting functions
const int MAXN = 1e6;


ll fac[MAXN + 1];
ll inv[MAXN + 1];

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

ll choose(int n, int r) { return fac[n] * inv[r] % MOD * inv[n - r] % MOD; }
//


	







void solve(){
	int n;
	cin>>n;
	cout<<"YES"<<endl;
	FOR(i,0,n){
		int x0,y0,x1,y1;
		cin>>x0>>y0>>x1>>y1;
		x0=abs(x0);
		y0=abs(y0);
		if(x0%2==1 && y0%2==1){
			cout<<1<<endl;
		}
		if(x0%2==1 && y0%2==0){
			cout<<2<<endl;
		}
		if(x0%2==0 && y0%2==1){
			cout<<3<<endl;
		}
		if(x0%2==0 && y0%2==0){
			cout<<4<<endl;
		}

	}
	 




	

}

    




   

    

    





    

int main(){
    fast;
    // ifstream read("revegetate.in");
    // ofstream out("revegetate.out");
	int sura=1;
    //cin>>sura;
	//cout << fixed << setprecision(7);
     while(sura--){
        solve();
        }
    return 0;
}
/*   /\_/\
*   (= ._.)
*   / >  \>
*/