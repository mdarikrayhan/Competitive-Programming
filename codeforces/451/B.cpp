#include <bits/stdc++.h>
using namespace std;

/* TYPES  */
#define ll long long
#define ld long double
const int M = 1e9+7;
const long long V=1e18;
// #define gcd(a,b) __gcd(a,b)
// #define lcm(a,b) (a*(b/gcd(a,b)))
#define all(a) (a).begin(),(a).end()
typedef std::vector<int> vi;
typedef std::vector<std::pair<ll,ll> > vpll;
typedef std::vector<std::vector<std::vector<ll> > > vvvll;
typedef std::vector<string> vstr;
typedef std::vector<ll> vll;
typedef std::vector<ld> vld;
typedef std::pair<ll,ll> pll;
typedef std::vector<string> vstr;
typedef std::vector<std::vector<ll> > vvll;
typedef std::vector<std::vector<ld> > vvld;

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define l length();

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; return;}

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;




//------------------------------------FACTORIAL-----------------------------------------
ll fact(int n)
{
    ll res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}
//------------------------------------FACTORIAL-----------------------------------------




//-----------------------------------PERMUTATION AND COMBINATION-------------------------------------
ll nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
ll nPr(int n, int r)
{
    return fact(n) / fact(n - r);
}
//-----------------------------------PERMUTATION AND COMBINATION-------------------------------------




//---------------------------------CODE HERE--------------------------------------------
void code()
{
    ll n;
 cin>>n;
 vll v(n);
 
 
 f(i,0,n)
 {
    cin>>v[i];
 }
 
 
 
 ll s=-1;
 ll e=-1;
 bool flag=false;
 
 f(i,0,n-1)
 {
    if(v[i]>v[i+1])
    {
        if(flag)
        {
            cout<<"no"<<endl;
            return;
        }
        if(s==-1)
        {
        s=i;
        }
       
    }
 
    else 
    {
        if(s!=-1&&!flag)
        {
            e=i;
            flag=true;
        }
    }
 }
    
      
 
       if(s!=-1&&!flag)
        {
            e=n-1;
            flag=true;
        }
 
      if(s==-1&&e==-1)
      {
        cout<<"yes"<<endl;
        cout<<"1"<<" "<<"1"<<endl;
        return;
      }
 
  if(e!=n-1)
  {
    if(v[s]>v[e+1])
    {
        cout<<"no"<<endl;
        return;
    }
  }
 
    if(s!=0)
  {
    if(v[e]<v[s-1])
    {
        cout<<"no"<<endl;
        return;
    }
  }
 
  cout<<"yes"<<endl;
  cout<<s+1<<" "<<e+1<<endl;
 
 
 
	


}

   
   
//---------------------------------END HERE----------------------------------------------












/* Main()  function */
int main()
{

	int tc=1;
    //cin>>tc;


	while(tc--){
		
        code();
	}
	return 0;
}
/* Main() Ends Here */