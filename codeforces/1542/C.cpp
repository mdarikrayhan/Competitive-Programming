#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define M 1000000007
#define sort(v) sort(v.begin(),v.end())
void solve(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<2<<"\n";
        return;
    }
    ll lcm=1, i=2;
    ll ans=0;
    for(ll i=2; i<=100; i++){
        ll prev=n/lcm;
        lcm=(lcm*i)/__gcd(lcm, i);
        ll x=n/lcm;
        ans+=(((prev-x)%M)*i)%M;
        ans=ans%M;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
/*ll BinExp(ll a, ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}*/
/*vector<ll> primes;
const ll N=1e7+10;
vector<bool> isPrime(N,1);
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(ll i=2; i<N; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(ll j=2*i; j<N; j+=i){
                isPrime[j]=false;
            }
        }
    }
}*/