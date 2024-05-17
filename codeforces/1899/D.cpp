
#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define ll long long
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define fr1(i, a, b) for (ll i = a-1; i>=b; i--)
#define fi first
#define show(a) fr(i,0,a.size()) cout<<a[i]<<" "
#define se second
#define mp(j, k) make_pair(j, k)
#define pb(x) push_back(x)
#define in(x) insert(x)
#define vec vector<ll>
 
#define acc(x) accumulate(all(x),(ll)0)
#define N 1000000007
using namespace std;
bool checkbinary(string n){
       fr(i,0,n.length())
       {
        if(n[i]>'1')
        return false;
       }
    return true;    
}
 

bool compare(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.first > b.first; 
}
bool isPrime(ll int n)
{
  if (n <= 1)
  {
    return false;
  }
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}
struct T 
{ 
   ll x, y, z; 
}; 
bool cp(const T& t1, const T& t2) {
  // Sort by the first element of the triplet.
    if (t1.x != t2.x) {
    return t1.x > t2.x;
  }

   else if (t1.y != t2.y) {
        return t1.y < t2.y;
    }
    // If the first and second elements are the same, sort by the third element.
    else {
        return t1.z < t2.z;
}
}




string sbs(const string& x, const string& str) {
    int len1 = x.length();
    int len2 = str.length();

    if (len1 < len2 || (len1 == len2 && x < str))
        return "-" + sbs(str, x);

    string result;
    int carry = 0;

    for (int i = len1 - 1, j = len2 - 1; i >= 0; --i, --j) {
        int digit1 = x[i] - '0';
        int digit2 = j >= 0 ? str[j] - '0' : 0;
        int diff = digit1 - digit2 - carry;
        carry = diff < 0;
        diff += carry * 10;
        result = to_string(diff) + result;
    }

    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos)
        return result.substr(pos);
    return "0";
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(vector<ll> v, ll n)
{
   
    ll ans = v[0];
   fr(i,1,n)
       { ans = (((v[i] * ans)) /
                (gcd(v[i], ans)));
       }
    return ans;
}
bool Pali(ll x)
{ ll a=x;
ll b=0;
while(x>0)
{
ll mod=x%10;
b=b*10+mod;
x/=10;

}
if(a==b)
{
  return true;
}
else
{
  return false;
}
}
void dive(ll a,map<ll,ll> mp)
{
  ll i=2;
  while(i*i<=a)
  {
    while(a%i==0){
      mp[i]++;
      a=a/i;
    }
    i++;
  }
  if(a>1) mp[a]++;
}
int main()

{
   ll t; cin>>t;
   while(t--)
   {
    ll n;
    cin>>n;
    vec v(n);
    map<ll,ll> mp;
    fr(i,0,n) cin>>v[i];
    fr(i,0,n) mp[v[i]]++;
    ll ans=0;
    ll n1=0;
    ll n2=0;
    for(auto i:mp)
    {
        if(i.se>1) ans+=(i.se*(i.se-1))/2;
        
    }
    for(auto i:mp)
    {
        if(i.fi==1) n1=i.se;
        if(i.fi==2) n2=i.se;
    }
    ans+=n1*n2;
    
    cout<<ans<<endl;
   }}