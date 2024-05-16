#include<bits/stdc++.h>
using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// Define
#define ld long double
#define double long double
#define fo(i,a,b)   for(ll i=a;i<b;i++)
#define rfo(i,a,b)  for(ll i=a;i>=b;i--)
#define pb push_back
#define ff first
#define ss second
#define vin(temp,n)    vector<ll>temp(n);fo(i,0,n){cin>>temp[i];}
#define sorting(v) sort(v.begin(),v.end())
#define sortingr(v) sort(v.begin(),v.end(),greater<ll>())
#define all(v)    v.begin(),v.end()
#define rev(v) reverse(all(v));
#define maxa(v) *max_element(v.begin(),v.end())
#define mina(v) *min_element(v.begin(),v.end())
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define lcm(a,b) ((a*b)/(__gcd(a,b)))
#define print(v,n)    fo(i,0,n){cout<<v[i]<<" ";}cout<<"\n";
#define in(n) ll n;cin>>n;
#define sin(s) string s;cin>>s;
#define in2(a,b) ll a,b;cin>>a>>b;
#define vn(temp,n) vector<ll> temp(n,0);
#define mkm(mp) map<ll,ll>mp;
#define on(n) cout<<n<<"\n";
#define yes  cout<<"YES"<<"\n";
#define no cout<<"NO"<<"\n";
#define nope  cout<<-1<<"\n";
#define mod 1000000007
#define PI (3.141592653589)

// Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<char,int> mci;
typedef set<int> st;

// Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}

// Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

// Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

set<ll> fac(ll n){
    set<ll> ans;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            ans.insert(i);
            ans.insert(n/i);
        }
    }
    return ans;
}


void solve(){
    in(n)
    vector<ll> setbit(32,0);
    fo(i,0,n)
    {
        in(x)
        bitset<32> a(x);
        fo(i,0,32){
            if(a[i]) setbit[i]++;
        }
    }

    ll g=0;
    fo(i,0,32){
        g=__gcd(g,setbit[i]);
    }

    set<ll> facot = fac(g);
    if(facot.size()==0){
        fo(i,1,n+1){
            cout<<i<<" ";

        }
        cout<<"\n";
    }
    
    else{
        for(auto x : facot){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    fastio()

    ll t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}