#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
#define PI 3.141592653589793238462
#define int long long
#define endl '\n'
#define double long double
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define all v.begin(),v.end()
#define loop(i,n) for(ll i=0;i<n;i++)
#define loop2(i,s,n) for(ll i=s;i<n;i++)
void ha(){ cout<<"YES\n"; }
void na(){ cout<<"NO\n"; }
void pt(vector<ll>& v){ for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout<<endl; }
void in(vector<ll>& v){ for(int i=0;i<v.size();i++) cin>>v[i]; }
ll lcm(ll a,ll b){return (a*b)/__gcd(a,b);}
ll pow(ll a,ll b){ll ans=1; while(b>0){if(b%2==0){b=b/2;a=(a*a)%mod;}else{b--;ans=(ans*a)%mod;}}return ans;}

// ll power(ll x,ll y,int p=mod){
//     ll res=1;
//     x=x%p;
//     while(y>0){
//         if(y&1){
//             res=(res*x)%p;
//         }
//         y=y>>1;
//         x=(x*x)%p;
//     }
//     return res;
// }

// ll modinv(ll a,ll p=mod){
//     return power(a,p-2,p);
// }

// ll nCr(ll n,ll r,int p=mod){
//     if(n<r)return 0;
//     if(r==0)return 1;
//     vector<int>fac(n+1,0);
//     fac[0]=1;
//     for(int i=1;i<=n;i++){
//         fac[i]=(fac[i-1]*i)%p;
//     }
//     return (fac[n]*modinv(fac[r],p)%p*modinv(fac[n-r],p)%p)%p;
// }

// bool isprime(ll n){
//     for(ll i=2;i*i<=n;i++){
//         if(n%i==0)return 0;
//     }
//     return 1;
// }

// int prime[1000001];

// void primefactor(){
//   for(int i=0;i<=1000000;i++){
//     prime[i]=1;
//   }
//   prime[1]=0;
//   for (int p = 2; p * p <=1000000; p++) {
//         if (prime[p]==1) {
//             for (int i = p * p; i <= 1000000; i += p)
//                 prime[i] = 0;
//         }
//     }
// }


//int present[100001];

// map<ll,ll>mp;
// void precomp(){
//   for(ll i=0;i*i<=100000;i++){
//     mp[i*i]++;
//   }
// }



void solve(){    
    //here we calculate the top of each tower and then proceed
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    in(v);
    int cnt=0;
    sort(all);
    if(k>v[n/2]){
      for(int i=n/2;i<n;i++){
      if(v[i]<k){
        cnt=cnt+k-v[i];
      }
    }
    }
    else{
      for(int i=n/2;i>=0;i--){
      if(v[i]>k){
        cnt=cnt+v[i]-k;
      }
    }
    }
    cout<<cnt<<endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t=1;
 // cin>>t;
 // precomp();
 //primefactor();
  for(int i=0;i<t;i++){
   solve();
    }
  return 0;
  }