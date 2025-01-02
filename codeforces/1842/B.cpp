#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pi;
#define fr(i,a,n) for(int i=a;i<n;i++)
#define rfr(i,n,a) for(int i=n;i>=a;i--)
#define pb push_back
#define in insert
#define mx LLONG_MAX


// #define ll long long int
//----------------------------------------------------------------------------------------------------------
// min heap
// priority_queue<ll, vector<ll>, greater<ll> >pq;
//----------------------------------------------------------------------------------------------------------
// insert at begin
// v.insert(v.begin(), 6);

// gives index of just greater value of target
// ll ind=upper_bound(v.begin(),v.end(),target)-v.begin

// sort the pair on basis of first element of pair in ascending order
// sort(a1.begin(), a1.end(), comparePairs);
//  sort(b1.begin(), b1.end(), comparePairs);
//---------------------------------------------------------------------------------------------------------
// bitwise {
//  (left shift) 1<<x= 1*pow(2,x); 00001 to 00100=4 7=111 7<<3=111000;
//  right shift n>>x=n/pow(2,x);
//  count setbits __builtin_popcount(n);
// }

// pow(2,x)==1ll<<x;
//=========================================================================================================
//{a,b} pair making
bool comparePairs(const pair<int, int> &a, const pair<int, int> &b)
{
  return a.first < b.first;
}

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

bool compare(string &a, string &b)
{
  if (a.length() < b.length())
    return true;
  if (b.length() < a.length())
    return false;
  return a < b;
}

// sort(v.begin(),v.end(), compare);

//===========================================================================================================

 bool isprime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0)return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)  return false;
    }
    return true;
}
// prime factors
vector<ll> primeFac(ll n) {
    vector<ll> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) factors.push_back(n);
    return factors;
}
// non repeating prime factors
vector<ll>nrpfac(ll n){
set<ll> factors;
    while (n % 2 == 0) {
        factors.insert(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.insert(i);
            n /= i;
        }
    }
    if (n > 2) factors.insert(n);
    vector<ll>factor;
    for(auto x:factors){
       factor.push_back(x);
    }
    return factor;
}
// All factors
vector<ll> allFac(int n) {
  vector<ll>factors;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) { // Avoid duplicate if n is a perfect square
            factors.push_back(n/i);
            }
        }
    }
    return factors;
}
//============================================================================================================
// pair<ll,ll> p={a,b};
// vector.push( {a,b} )

// auto maxii = max_element(candies.begin(), candies.end()); //This returns an iterator to the maximum element
//*maxii valur of maxii;

// min_element for minimum
//-------------------------------------------------------------------------------------------------------------
// rotate
//  ll x;cin>>x;
//     auto it = find(a.begin(), a.end(), x);
//         if (it != a.end()) {
//             int p = it - a.begin();
//             cout << p + 1 << " ";
//             rotate(a.begin()+i, a.begin() + p, a.begin() + p + 1);
//         }

// x ko find karega aur i index pe dalega,, i=0 agar starting me dalna ho to
//----------------------------------------------------------------------------------------------------------------

// vector<ll>a(n);
// for(int i=0;i<n;i++)cin>>a[i];

int main() {
    ll t;
    cin >> t;
 while(t--){
 ll n,x;cin>>n>>x;
 ll e = 0;
 vector<ll>a(n);
for (int i=0; i<3;i++) {
  for (int j=0; j<n;j++) cin>>a[j];
         for (int j = 0; j < n; j++) {
                if ((x | a[j]) != x) break;
                e|= a[j];
            }
        }
        if (e == x) cout << "Yes";
        else cout << "No";
        cout<<endl;
    }
  return 0;
}