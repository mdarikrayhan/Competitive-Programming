//****KUSHAL PUJARI****
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<long long >
#define st set<ll>;
#define f(i, a, b) for (ll i = a; i < b; i++)
#define fors(n) for (ll  i = 0; i < n; i++)
#define show(c) cout << c << "\n";
#define spcshow(c) cout << c << ' ';
#define newline cout<<endl;
#define ip(v) for(ll i = 0; i < v.size(); i++) cin>>v[i];
#define srt(v) sort(v.begin(), v.end())
 

 
const int MOD = 1e9+7;
const int MAXN = 10000001;
 
using namespace std;
  
vector<ll> spf(MAXN + 1, 1);
 
 
 
//***************************SIEVE*******************************8*
 
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
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
 
vector<ll> getFactorization(ll x)
{
    vector<ll> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
//**************************SIEVE***********************************
 
 
//**************************FIBONACCI NUMBBERS**********************
 
struct matrix {
    long long mat[2][2];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
              c.mat[i][j] = 0;
              for (int k = 0; k < 2; k++) {
                  c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
              }
          }
        }
        return c;
    }
};
 
matrix matpow(matrix base, long long n) {
    matrix ans{ {
      {1, 0},
      {0, 1}
    } };
    while (n) {
        if(n&1)
            ans = ans*base;
        base = base*base;
        n >>= 1;
    }
    return ans;
}
 
long long fib(int n) {
    matrix base{ {
      {1, 1},
      {1, 0}
    } };
    return matpow(base, n).mat[0][1];
}

 
 ll power(ll a, ll b, ll mod = 0){
    ll result = 1;
    if(mod == 0){
        while(b){
            if(b & 1) result *= a;
            a *= a;
            b = b >> 1;
        }
    }
    else {
        while(b){
            if(b & 1){
                result *= a;
                result  = result % mod;
            }
            a *= a;
            a = a % mod;
            b = b >> 1;
        }
    }
    return result;
}
bool checkprime(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
            if(n==4)
            {return false;}
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
 
//Code starts Here
//Dont forget while(t--) for questions which donot involve it.
//made by kushal.
void solve()
{
  ll n;
  cin>>n;
  ll k=2*n;
  vi a(k);
  ip(a);
  ll ans=0;
  fors(k){
    // if(i==3){
    //     for(ll m=0;m<k;m++){
    //         spcshow(a[m])
    //     }
    //     newline
    // }
    for(ll j=i+1;j<k;j++){
         if(a[j]==a[i] && (j-i)!=1){
            // cout<<i<<" "<<j<<endl;
            ll temp=a[j];
            ll c=j-1;
            while(c>i){
                a[c+1]=a[c];
                c--;
            }
            a[c+1]=temp;
            ans+=(j-i-1);
         }
    }
  } 
  show(ans)
}
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
 
ll t =1;	
//cin>>t;
while(t--)
{
solve();
}
    return 0;
}