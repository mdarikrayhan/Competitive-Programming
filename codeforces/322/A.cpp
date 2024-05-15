#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pq priority_queue
#define vct vector
#define fixed(n) fixed << setprecision(n)
#define int128 number<cpp_int_backend<128, 128, unsigned_magnitude, unchecked, void>>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sumv(v) accumulate(all(v), 0LL)
#define minv(v) *min_element(all(v))
#define sumeven(x,y) (y/2)*((y/2)+1)-(x/2*(x/2-1))
#define sumrange(x,y) (y*(y+1)/2)-((x-1)*(x)/2)
#define maxv(v) *max_element(all(v))
#define umap unordered_map
#define ci(v) for(auto&it:v){cin>>it;}
#define sall(s) s.begin(),s.end()
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define print(v) for(auto i:v)cout<<i<<ln;
#define ln "\n"
#define yes cout<<"YES"<<ln
#define no cout<<"NO"<<ln
#define isagi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PI 3.141592653589793238462643383279502884197
#define ret return void
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define f(i,a,b) for(ll i=a;i<b;i++)
#define presum(a, n) {for (int i = 1; i <= n and cin>>a[i]; i++) a[i]+=a[i-1];}
#define fi(x) for(int i=0;i<x;i++)
#define sz(x) int(x.size())
#define MOD 1000000007
#define EPS 1e-9
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
ll fact(ll n)
{
    ll fact=1;
    for(ll i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}
bool prime(ll num)  //O(sqrt(n))
{
    if (num == 1) return false;
    ll ch = 2;
    while (ch * ch <= num)
    {
        if (!(num % ch)) return false;
        ch++;
    }return true;
}
bool isPalindrome(string str) {
    stack<char> s;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        s.push(str[i]);
    }
    for (int i = 0; i < n; i++) {
        if (s.top() != str[i]) {
            return false;
        }
        s.pop();
    }
    return true;
}
vct<ll> sieve(ll n) {
    vct<bool> prime(n+1,true);
    prime[0]=prime[1]=false;  //1,0 arent primes
    int it=2;
    while(it*it<=n){
        if(prime[it]){
            for(int i=it*it;i<=n;i+=it){
                prime[i]=0;
            }
        }
        it++;
    }
    vct<ll> res;
    for(int i=2;i<n;i++){
        if(prime[i])res.push_back(i);
    }
    return res;
}
ll nPr(ll n, ll r) { return fact(n) / fact(n - r); }
ll nCr(ll n, ll r) { return fact(n) / (fact(r) * fact(n - r)); }
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcmm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll ToInt(string s){
    ll num;
    istringstream iss(s);
    iss>>num;
    return num;
}
template<class T>
string ToStr(T val){
    ostringstream oss;
    oss<<val;
    return oss.str();
}
ll modforbign(string s,int mod){
    ll res=0;
    for(auto& i:s){
        res=res*10+int(i-'0');
        if(res>=mod){
            res%=mod;
        }
    }
    return res;
}
ll BinExp(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2==1){
            res*=a;
            res%=MOD;
        }
        a*=a;
        a%=MOD;
        b/=2;
    }
    return res;
}
double BinExpDouble(double a,int b){
    double res=1;
    while(b){
        if(b%2==1){
            res*=a;
        }
        a*=a;
        b/=2;
    }
    return res;
}
vct<ll> getdiv(ll x){
    vct<ll> res;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            res.push_back(i);
            res.push_back(x/i);
        }
    }
    if(sqrt(x)==int(sqrt(x))){
        res.pop_back();
    }
    return res;
}
set<ll> primefactors(ll x){
    set<ll> res;
for(int i=2;i*i<=x;i++){
    if(x%i==0)res.emplace(i);
    while(x%i==0){
x/=i;
    }
}
if(x>1)res.emplace(x);
    return res;
}
struct cmp{
    int a,b,c,d;
    bool operator<(const cmp& tmp){
        if(tmp.a==a and tmp.b==b and tmp.c==c){
            return tmp.d<d;
        }
        return tmp.a>a and tmp.b>b and tmp.c>c and tmp.d<d;
    }
};

int ssum(string s){
    int sum=0;
    for(char ch:s){
        sum+=(ch-'0');
    }
    return sum;
}

vct<string> GenerateSubStrings(string s){
    vct<string> ss;
    for(int i=1;i<=s.size();i++){
        for(int j=0;j<=s.size()-i;j++){
            ss.push_back(s.substr(j,i));
        }
    }
    return ss;
}
ll sum(ll x){
    ll s=0;
    while(x){
        s+=x%10;
        x/=10;
    }
    return s;
}

bool lucky(ll x){
    int cnt=0;
    for(char ch: to_string(x)){
        if(ch=='4' or ch=='7')cnt++;
    }
    return cnt== to_string(x).size();
}

int maxsubarray(vct<int>& arr,int x){
    int mx=0,sum=0;
    for(int i=0;i<x;i++){
        sum=max(arr[i],arr[i]+sum);
        mx=max(mx,sum);
    }
    return mx;
}

bool vowel(char ch){
    return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
}

ll fromVecToInt(vct<ll>& sent){
    ll res=0;
    for(ll& i:sent){
        res=res*10+i;
    }
    return res;
}

int cap=1e5+10;

int val;

void answer() {
int x,y;
cin>>x>>y;
cout<<x+y-1<<ln;
for(int i=1;i<=y;i++){
    cout<<1<<' '<<i<<ln;
}
for(int i=2;i<=x;i++){
    cout<<i<<' '<<y<<ln;
}
}

bool testat = 0;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("errors.txt","w",stderr);
#endif
    isagi;
    int tests = 1;
    if (testat) cin >> tests;
    for (int test = 1; test <= tests; test++)
    {
        answer();
    }
    Time
    return 0;
}