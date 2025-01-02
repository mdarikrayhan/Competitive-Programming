#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//using namespace chrono;
using namespace std;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int             long long
#define ld              long double
#define fr(i,n)         for(int i=0;i<n;i++)
#define fro(i,k,n)      for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define py              cout<<"YES"<<endl;
#define pn              cout<<"NO"<<endl;
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ull             unsigned long long
#define in              cin>>
#define o(x)            cout<<x<<endl;
#define pi              3.1415926535897932
#define mod             1000000007
#define inf             1e18
#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define all(x)          x.begin(), x.end()
#define allr(x)          x.end(), x.begin()
#define clr(x)          memset(x, 0, sizeof(x))
#define sortall(x)      sort(all(x))
#define tr(it, a)       for(auto it = a.begin(); it != a.end(); it++)
#define mk(a,n,type)    type *a=new type[n];
#define ps(x,y)         fixed<<setprecision(y)<<x
#define setbits(x)      __builtin_popcountll(x)
#define lead(x)         __builtin_clzll(x)
#define trail(x)        __builtin_ctzll(x)

typedef pair< int,int >                 pll;
typedef vector<int>                     vll;
typedef vector<pll>                     vpll;
typedef vector<string>                  vs;
typedef unordered_map<int,int>          umll;
typedef map<int,int>                    mll;
typedef priority_queue<int>             pqllmax;
typedef priority_queue<int,vector<int>,greater<int>>             pqllmin;
typedef pair<int32_t,int32_t>           pii;
typedef vector<int32_t>                 vi;
typedef vector<pii>                     vpi;
typedef vector<string>                  vs;
typedef unordered_map<int32_t,int32_t>  umi;
typedef map<int32_t,int32_t>            mi;
typedef priority_queue<int>             pqimax;
typedef priority_queue<int,vector<int>,greater<int>>             pqimin;

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

template <typename T>
void print(T &&t)  { cout << t << endl; }
template<typename T>
void printvec(vector<T>v){int n=v.size();fr(i,n){cout<<v[i]<<" ";cout<<endl;}}
template<typename T>
int sumvec(vector<T>v){int n=v.size();int s=0;fr(i,n){s+=v[i];}return s;}

bitset<64> dtob(int n) {bitset<64> binaryNum;int i = 0;while (n > 0) {binaryNum[i] = n % 2;n = n / 2;i++;}return binaryNum;}
void pa(int* a,int n){for (int i = 0; i < n ; i++){cout<<a[i]<<" ";}}
int count(int* a,int n,int ele){int c=0;for(int i=0;i<n;i++){if(a[i]==ele){c+=1;}}return c;}
int index(int* a,int n,int ele){for(int i=0;i<n;i++){if(a[i]==ele){return i;}}return -1;}
int sum(int* a,int n){int s=0;for(int i=0;i<n;i++){s+=a[i];}return s;}
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}
// Mathematical functions
int lcm(int a, int b){return (a/__gcd(a,b)*b);}
int expmod(int x, int y, int p){int res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
bool twop(int n){if(n==0){return false;}return ((n&(n-1))==0);}
bool sq(int x){if(x >= 0){int sr = sqrt(x);return (sr * sr == x);}return false;}
bool prime(int n) {if(n==1){return false;}for(int i=2;i*i<=n;i++){if(n%i==0){return false;}}return true;}
int modadd(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int modmul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int modsub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int power(int a,int b) {if(b==0){return 1;}int res=power(a, b / 2);if (b % 2){return res*res*a;}else{return res*res;}}
template<typename T>
void printmat(T a,int n,int m){for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<*(*(a+i)+j)<<" ";}cout<<endl;}}







void ans(){
    int n;
    in n;
    vll a(n);
    fr(i,n){
        in a[i];
    }
    int inc=1e9,dec=0;
    fr(i,n-1){
        if(a[i]>a[i+1]){
            dec=max(dec,(a[i]+a[i+1]+1)/2);
        }else if(a[i]<a[i+1]){
            inc=min(inc,(a[i]+a[i+1])/2);
        }
    }
    if(inc>=dec){
        o(dec);
    }
    else{
        o(-1)
    }

}
int32_t main(){
    fast
    int t;cin>>t;
    //int t=1;
    for(int i=0;i<t;i++){ans();}
    return 0;
}
