#include <bits/stdc++.h>
#include <algorithm>
#include <limits>
#include <cstring>
 
using namespace std;
 
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define PRAYAG cout.tie(NULL);
 
#define ll  long long
#define lld  long double
#define ull unsigned long long
 
const lld pi= 3.141592653589793238;
const ll INF= LONG_LONG_MAX;
const ll mod=1e9+7; 
 
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vvs vector<vector<string>>
#define vpi vector<pair<int,int>>
#define vv(T) vector<vector<T>>
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T>>
#define mem(n,i) memset(n, i,sizeof n)
#define p(A,B) pair<A,B>
 
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}  
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
 
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}
 
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
 
#define py cout<<"YES";
#define pm cout<<"-1"<<endl ;
#define pn cout<<"NO";
 
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define rv(v) v.end(),v.begin()
 
#define ps(x,y) fixed<<setprecision(y)<<x;
 
#define o(x) cout<<(x) <<" ";
#define o2(x,y) cout<<(x) <<" "<<(y)<<" ";
#define o3(x,y,z) cout<<(x) <<" "<<(y)<<" "<<(z)<<" ";
 
#define oe(x) cout<<(x)<<endl;
#define oe2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define oe3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
 
#define i1(A,a) A a; cin >> a;
#define i2(A,a,b) A a, b; cin >> a >> b;
#define i3(A,a,b,c) A a, b, c; cin >> a >> b >> c;
#define i4(A,a,b,c,d) A a, b, c, d; cin >> a >> b >> c >> d;
#define i5(A,a,b,c,d,e) A a, b, c, d, e; cin >> a >> b >> c >> d >> e;
#define i6(A,a,b,c,d,e,f) A a, b, c, d, e, f; cin >> a >> b >> c >> d >> e>> f;
 
#define fl(i, n) for(ll i=0;i<n;i++)
#define Fl(i,k, n) for(ll i=k;i<n;i++)
#define bl(i, n) for(ll i=n;i>=0;i--)
#define Bl(i,k, n) for(ll i=n;i>=k;i--)
 
void solve() {
 
ll int  n;
cin >> n;
float x=(n-1)/2;
// o(x)
// oe2(one,min)
for(ll int i=1;i<=n;i++)
{
     for(ll int j=i+1;j<=n;j++)
     {
        // o2(i,j)
        if(n%2==0&&j-i==x+1)
        o(0)
        else if(j-i<=x)
        {
            o(-1)
        }
        else
        {
            o(1)
        }
    //  cout<<endl;
     }
}cout<<endl;
}
 
 
int main() {
 
Code By PRAYAG
 
int tt=1; cin >> tt; while(tt--){solve();}
 
}