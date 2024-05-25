#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define sort(v) sort(v.begin(),v.end())
#pragma GCC optimize("unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
long long binpower(long long a, long long b, long long M) {
    if (b == 0)
        return 1;
    long long res = binpower(a, b / 2, M);
    if (b % 2)
        return (res%M * res%M * a%M)%M;
    else
        return (res%M * res%M)%M;
}
void pv(vector<ll> v){
    fr(i,0,v.size()){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
vector<ll> SieveOfEratosthenes(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<ll> e;
    for (ll p = 2; p <= n; p++){
        if (prime[p]){
            e.push_back(p);
        }
    }
    return e;
}
ll MAXN=1.1*1e7;
vector<ll> spf(MAXN + 1, 1);
void sieve(){
    spf[0] = 0;
    for (ll i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) {
            for (ll j = i; j <= MAXN; j += i) {
                if (spf[j]== 1)
                    spf[j] = i;
            }
        }
    }
}
vector<ll> getFactorization(ll x){
    vector<ll> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res%p * x%p)%p;
        y = y >> 1;
        x = (x%p * x%p)%p;
    }
    return res % p;
}
vector<vector<ll>> matrixMult(vector<vector<ll>> a, vector<vector<ll>> b, ll MOD){
    ll k=a[0].size();
    vector<vector<ll>> x(k, vector<ll>(k,0));
    fr(i,0,k){
        fr(j,0,k){
            ll temp=0;
            fr(z,0,k){
                temp=(temp%MOD+((a[i][z])%MOD*(b[z][j])%MOD)%MOD)%MOD;
            }
            x[i][j]=temp%MOD;
        }
    }
    return x;
}

vector<vector<ll>> mpower(vector<vector<ll>> a, ll y, ll MOD){
    ll k=a.size();
    vector<vector<ll>> d(k, vector<ll>(k,0));
    fr(i,0,k){
        fr(j,0,k){
            if(i==j){
                d[i][j]=1;
            }
        }
    }
    while (y > 0) {
        if (y % 2 == 1){
            d = matrixMult(d,a,MOD);
            y-=1;
        }
        y = y / 2;
        a = matrixMult(a,a,MOD);
    }
    return d;
}
void printMatrix(vector<vector<ll>> a){
    ll k=a.size();
    fr(i,0,k){
        fr(j,0,k){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
ll lcm(ll a,ll b){
    return a*b/__gcd(a,b);
}
ll M=1e9;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL);
int main(){
    fast
    ll n,k;
    cin>>n>>k;
    ll temp=1;
    fr(i,0,n){
        ll x; cin>>x;
        temp=__gcd(k,lcm(temp,x));
    }
    if (temp==k){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
	   			 	  	   	 		 		   	 	 	