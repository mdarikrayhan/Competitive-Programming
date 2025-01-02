#include <bits/stdc++.h>
// #include <sys/resource.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;
#define ll long long
const int N=1e5+5;

// vector<int> mark(N+5,1);
// vector<ll> primes;
// void Sieve(){
//     mark[0]=0;
//     mark[1]=0;mark[2]=1;
//     for(ll i=4;i<=N;i+=2LL){
//         mark[i]=0;
//     }
//     for(ll i=3;i*i<=N;i+=2LL){
//         if(mark[i]){
//             for(ll j=i*i;j<=N;j+=i){
//                 mark[j]=0;
                
//             }
            
//         }
//         }
//     primes.push_back(2);
//     for(ll i=3;i<=N;i+=2){
//         if(mark[i]){
//             primes.push_back(i);
//         }
        
        
//     }
    
    
    
// }
#define mod 1000000007
 
// vector<pair<int, int> > factors;
// void getFactors(int n) {
//     factors.clear();
//     int d = 1;
//     for (int i = 2; i * i <= n; i += d, d = 2)
//         if (n % i == 0) {
//             factors.push_back(make_pair(i, 0));
//             while (n % i == 0) {
//                 n /= i;
//                 factors.back().second++;
//             }
//         }
//     if (n != 1)
//         factors.push_back(make_pair(n, 1));
// }
// vector<int> divisors;
// void getDivisors(int ind = 0, int res = 1) {
//     if (ind == (int) factors.size()) {
//         divisors.push_back(res);
//         return;
//     }
//     for (int i = 0; i <= factors[ind].second; i++) {
//         getDivisors(ind + 1, res);
//         res *= factors[ind].first;
//     }
// }

//  set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(),inserter(cd,
//             cd.begin()));  push the intersection of two vectors in the vector cd


 
// ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
// ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}

// ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
// ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
// ll modInverse(ll a,ll mod){return powermod(a,mod-2,mod);}
// ll ncr(ll n,ll r,ll mod){if(n<r)return 0;if(r==0)return 1;vector<ll> fact(n+1,0);fact[0]=1;for(ll i=1;i<=n;i++){fact[i]=(fact[i-1]*i)%mod;}return(fact[n]*modInverse(fact[r],mod)%mod*modInverse(fact[n-r],mod)%mod)%mod;}
// ll ncr(ll n,ll r){r=max(r,n-r);ll ans=1;for(int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

// bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
// bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
// bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

// ll binpowmod(ll a,ll b){
//     ll ans=1;
//     while(b>0){
//         if((b&1)==1){ans*=a;ans%=mod;}
//         a*=a;
//         a%=mod;
//         b=b>>1;
//     }
//     return ans;
// }
//  ll mult(ll a,ll b){
//      return ((a*b)%mod);
//  }
//  ll inv(ll a){
//      return binpowmod(a,mod-2);
//  }
//  ll sub(ll a,ll b){
//      return ((a-b)%mod+mod)%mod;
//  }

//   ll divide(ll a,ll b){
//       return mult(a,inv(b));
//   }
// minimum subarray sum-ans
//  ll sum=arr[0],curr=arr[0],ans=0;
// 	     for(int i=1;i<n;i++){
// 	         sum+=arr[i];
// 	         ans=min(ans,curr+arr[i]);
// 	         curr=min(curr+arr[i],arr[i]);}

void interact(int i,vector<int>& used){
  cout<<i<<endl;
    used[i]=1;return;
    
}
void find(int chance,map<int,int> &mp,vector<int> &used,vector<int> &arr,int &x,int n){
   
    if(chance==2){
       cin>>x;used[x]=1;
        return ;
        
    }
    if(x>0 && mp[x]>0 && !used[mp[x]]){
        interact(mp[x],used);
        return;
        
    }
    int maxi=0,maxip=0;
    for(int i=1;i<=2*n;i++){
        if(used[i])continue;
        if(arr[i]>arr[maxi])maxi=i;
        
        if(mp[i]>0 && arr[i]>arr[maxip])maxip=i;
        
    }
    if(maxip>0)interact(maxip,used);
    else interact(maxi,used);return;
    
    
}


int main()
{
int n,m;cin>>n>>m;
vector<int> arr(2*n+1);
for(int i=1;i<=2*n;i++)cin>>arr[i];
map<int,int> mp;
for(int i=0;i<m;i++){
    int x,y;cin>>x>>y;
    mp[x]=y;
    mp[y]=x;
    
    
}
vector<int> used(2*n+1,0);
int chance;
cin>>chance;
int prev=0;
for(int i=1;i<=2*n;i++){
    find(chance,mp,used,arr,prev,n);
    chance=3-chance;
}



 return 0;
}

 