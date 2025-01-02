#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define ull unsigned long long
#define loop(i,a,n) for(ll i=a;i<n;i++)
#define rloop(j,n)  for(ll j=n-1;j>-1;j--)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define sort(v) sort(v.begin(),v.end());
#define dsort(v)  sort(arr, arr + n, greater<long long>());
#define pb push_back
#define ppb pop_back
#define vi  vector<ll> vi
#define si set<ll> si
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll> > vpll;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; deb(x); cerr << endl;
#else
#define debug(x)
#endif
ll factorial(ll n)
{
    ll product = 1;
    for (int i = 1; i <= n; i++) product = product * i; return product;
}
 
bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++){ if (n % i == 0) return true;} return false;
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b) ; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b ; }
unsigned long long fibonacci(unsigned long long k) {
    double phi = (1 + sqrt(5)) / 2;
   return round((pow(phi, k) - pow(1 - phi, k)) / sqrt(5));
}
const long long M = 1000000007;

/* Start From Here*/
void karan_sabka_papa() {
    ll n;
    cin>>n;
    vector<ll> arr(4*n,0);
    loop(i,0,4*n){
        cin>>arr[i];
    }
    sort(arr);
   for(ll i=0;i<4*n;i=i+2){
   if(arr[i]!=arr[i+1]){
    no;
    return ;
   }
   }

   ll area=arr[0]*arr[4*n-1];
   for(ll i=0 ,j=4*n-1;i<2*n ;i=i+2,j=j-2){
   if(arr[i]*arr[j]!=area){
    no;
    return ;
   }





   }

   yes;
return ;
}

int main() {
  #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;

    while (t--) {
 karan_sabka_papa();
 

    }
    return 0;
}
