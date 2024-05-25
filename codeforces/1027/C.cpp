#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define M 1000000007
#define sort(v) sort(v.begin(),v.end())
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    unordered_map<ll,ll> mp;
    vector<ll> valid;
    for(ll i=0; i<n; i++)
    {
        cin>>v[i];
        mp[v[i]]++;
    }
    vector<ll> nv;
    ll ans1=0, ans2=1, mn=INT_MAX;
    for(ll i=0; i<n; i++){
        if(mp[v[i]]>=2){
            nv.push_back(v[i]);
            mp[v[i]]-=2;
        }
    }
    n=nv.size();
    sort(nv);
    ll a1=(nv[1]*nv[0]);
    ll p1=(nv[1]+nv[0])*(nv[1]+nv[0]);
    ans1=0, ans2=1;
    for(ll i=2; i<n; i++){
        ll p2=(nv[i]+nv[i-1])*(nv[i]+nv[i-1]);
        ll a=(nv[i]*nv[i-1]);
        if(p1*a>p2*a1){
            ans1=i-1;
            ans2=i;
            a1=a;
            p1=p2;
        }
    }
    cout<<nv[ans1]<<" "<<nv[ans1]<<" "<<nv[ans2]<<" "<<nv[ans2]<<"\n";
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