// Smit fefar //
// Lets start the code // 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define SMIT_FEFAR                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvc vector<vector<char>>
#define vi vector<int>
#define vc vector<char>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvpll vector<vector<pll>>
#define mp make_pair
#define f first
#define s second
#define PI 3.141592653589793238462
#define setbits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vll vector<ll>
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define fi(l, r) for (ll i = l; i < r; i++)
#define fj(l, r) for (ll j = l; j < r; j++)
#define fk(l, r) for (ll k = l; k < r; k++)
#define fir(r, l) for (ll i = r; i >= l; i--)
#define fjr(r, l) for (ll j = r; j >= l; j--)
#define in cin>> 
#define print cout<<
#define nline "\n"

int binarySearch(vi v, ll l, ll r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m] == x)
            return m;
        if (v[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
struct triplet{
    ll x,y,gcd;
};

// struct triplet extended_Euclid(ll a, ll b){
//     if(b == 0){
//         triplet ans;
//         ans.gcd = a;
//         ans.x = 1;
//         ans.y = 0;
//         return ans;
//     }
    
//     triplet ans2 = extended_Euclid(b, a%b);
//     triplet finalAns;
//     /*
//     ax + by = gcd(a, b)
//     gcd(a, b) = gcd(b, a%b)
//     gcd(b, a%b) = bx1 + (a%b)y1
//     a%b = a − (a/b) ∗ b 
//     so...
//     ax + by = bx1 + (a%b)y1
//     ax + by = bx1 + (a − (a/b) ∗ b)y1
//     ax + by = ay1 + b(x1 − (a/b) ∗ y1)
    
//     so...

//     x = y1
//     y = x1 − (a/b) ∗ y1
//     */
//     finalAns.gcd = ans2.gcd;
//     finalAns.x = ans2.y;
//     finalAns.y = (ans2.x) - (a/b)*(ans2.y);
//     return finalAns;
// }

// ll moduloInverse(ll num1, ll modulo){
// triplet ans = extended_Euclid(num1,modulo);
// //return ans.x; // for negative values allowed
// return (ans.x + modulo)%modulo; // for only positive values
// }

int endNumber = 2*10000+1;
vi smallestPrimeFactors(endNumber,0);
// O(N*log(log(n)))
void sieveMethodSmallesPrimeFactors(){
    fi(1,endNumber){
        smallestPrimeFactors[i] = i;
    }
    for(int j = 2; j <= endNumber-1 ; j++){
        if(smallestPrimeFactors[j] == j){
            for(int k = j*j;k < endNumber; k += j){
                if(smallestPrimeFactors[k] == k)
                smallestPrimeFactors[k] = j;
            }
        }
    }
}
ll expo(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1){res=res*a;}
        b=b>>1;
        a*=a;
    }
    return res;
}
// ll divide(vll &v,int start,int end,ll &m){
//   if(start==end){
//     return v[start]%m;
//   }
//   ll num1,num2;
//   int mid = start + (end-start)/2;
//   num1 = divide(v,start,mid,m);
//   num2 = divide(v,mid+1,end,m);
//   // cout<<(num1*num2)%m<<endl;
//   return (num1*num2)%m;
// }
bool Comparator(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first <= b.first) { 
        return a.second > b.second;
    }
    else{
      return a.first < b.first;
    }
}

void solve()
{
  //sieveMethodSmallesPrimeFactors();
  ll n;
  cin>>n;
  vll v(n);
  fi(0,n)cin>>v[i];
  map<int,int> m;
  fi(0,n)
  {
    if(v[i]%2 == 0)
    m[0]++;
    else
    m[1]++;
  }
  if(m[0]%2 == 0){
    if(m[1]%2 == 0){
      if((m[1]/2)%2 == 0){
        print "Alice" << nline;
      }
      else
      print "Bob" << nline; 
    }
    else{
      if((m[1]/2+1)%2 == 0){
        print "Alice" << nline;
      }
      else
      print "Bob" << nline; 
    }
  }
  else{
    if(m[1]%2 == 0){
      if((m[1]/2)%2 == 0){
        print "Alice" << nline;
      }
      else
      print "Bob" << nline; 
    }
    else{
      print "Alice" << nline;
    }
  }
} 

int main()
{
  SMIT_FEFAR;
  bool test_case_there_or_not = 1;
  if (test_case_there_or_not == 1)
  {
    ll t = 1;
    cin >> t;
    while (t--)
    {
      //cout<<"hii"<<endl;
      solve();
    }
  }
  else
  {
    solve();
  }

  return 0;
}
// End of code
// Smit Fefar // 