#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


#define int long long
#define ll long longSSSS
#define endl "\n"
#define pb push_back
#define ppb pop_back 
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountint
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(),x.rend()
#define loop(it,b,c,x) for(int it=b;it<c;it+=x)
#define rloop(it,b,c,x) for(int it=b;it>=c;it-=x)
#define loope(it,b,c,x) for(int it=b;it<=c;it+=x)
#define loopp(it,b,c) for(int it=b;it<=c;++it)
#define loopl(a,b,c,x) for(long long a=b;a<c;a+=x)
#define fsort(v) sort(v.begin(),v.end())
#define rsort(v) sort(v.rbegin(),v.rend())
#define True(b) cout<<(b?"YES\n":"NO\n")
#define maxx(v) *max_element(v.begin(),v.end())
#define minx(v) *min_element(v.begin(),v.end())
#define search_fpair(query,num) find_if(query.begin()+i+1, query.end(), [&](const auto& pair)  { return pair.second == num; })!=query.end()
#define search_spair(query,num) find_if(query.begin()+i+1, query.end(), [&](const auto& pair)  { return pair.second == num; })!=query.end()
#define index_fpair(v,num) distance(v.begin(),find_if(v.begin(), v.end(), [&](const auto& pair)  { return pair.first == num; }))
#define index_spair(v,num) distance(v.begin(),find_if(v.begin(), v.end(), [&](const auto& pair)  { return pair.second == num; }))
#define vindex(vec,num) distance(vec.begin(),find(vec.begin(),vec.end(),num))
#define gsum(a) accumulate(a.begin(), a.end(), 0LL)
#define fastio
using i64=long long;

struct trei
{
    int s,k,ind;
};

// typedef pair<ll, ll> pi;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order, order_of_key
// To erase an element from ordered_set with less_equal I used lower_bound on
//  (element to be erased — 1) and then erased the iterator I got from lower_bound and it
//  works only if the element to be erased is present in the set.
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(bool t) {cerr<<t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
// void _print(set t){cerr<<t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
int MOD = 1e6 + 3;
int N1 = 1e9 + 7;
int inf = 1e18;

/******************************************/
int reverseBits(int z) {int rev = 0; int n = z; while (n > 0) {rev <<= 1; if (n & 1 == 1)rev ^= 1; n >>= 1;} return rev;}
int strtoint(const string &s) {int n = s.length(); int num = 0; for (int i = 0; i < n; i += 1) num = num * 10 + (s[i] - '0'); return num;}
string inttostr(int n) {string s; if (n < 10) {s.pb('0' + n); return s;} s = inttostr(n / 10); s.pb('0' + n % 10); return s;}
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int lcm(int a, int b) {return (a * b) / gcd(a, b);}
int countDivisors(int n) {int cnt = 0; for (int i = 1; i <= sqrt(n); i++) {if (n % i == 0) {if (n / i == i)cnt++; else cnt = cnt + 2;}} return cnt;}
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
bool revsort(int a, int b) {return a > b;}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
// vector<int> prime(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = ((int)(i) * (int)(i)); j <= n; j += i)arr[j] = 1;} return vect;}
int countnumber(int n) {int cnt = 0; while (n > 0) {cnt++; n /= 10;} return cnt;}
// vector<int>countSmainterRight(vector<int>arr){pbds s;int n = arr.size();vector<int> ans;for (int i = n - 1; i >= 0; i--) {if (i == n - 1) { ans.push_back(0);}else {ans.push_back(s.order_of_key({ arr[i], i }));}s.insert({ arr[i], i });}reverse(ans.begin(), ans.end());return ans;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int getupper(int k) {int x = 8 * k + 1; int sqr = sqrt(x); if ((sqr * sqr) == x) {sqr--; return (sqr / 2);} sqr--; return (sqr / 2) + 1;}
int get2upper(int n, int rem) {int a = (2 * n) + 1; int s = ((4 * n * n) + (4 * n) + 1) - (8 * rem); int sqr = sqrt(s); if ((sqr * sqr) == s) {return ((a - sqr) / 2) - 1;} sqr++; return ((a - sqr) / 2);}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
int modPower(int x, int y) {int res = 1; x = x % MOD; if (x == 0)return 0; while (y > 0) {if (y & 1)res = (res * x) % MOD; y = y / 2; x = (x * x) % MOD;} return res;}
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
int modFact(int n) {if (n >= MOD)return 0; int result = 1; for (int i = 1; i <= n; i++)result = (result * i) % MOD; return result;}
int power(int x, int y) {int res = 1; while (y > 0) {if (y & 1)res = res * x; y = y >> 1; x = x * x;} return res;}
int negMOD(int x) {x = -x; int s = x / MOD; if (x % MOD)s++; return (MOD * s) - x;}
void precision(int a) {cout << setprecision(a) << fixed;}

vector<int> primeFactors(int n){
  vector<int>ret; 
  while (n % 2 == 0){
    ret.pb(2); 
    n = n / 2;
  } 
  for(int i = 3; i <= sqrt(n); i = i + 2){
    while (n % i == 0){
      ret.pb(i); 
      n = n / i;
    }
  }
  if (n > 2){
    ret.pb(n);
  } 
  return ret;
}
vector<int>divisor(int n){
  vector<int>res; 
  for (int i = 1; i <= sqrt(n); i++){
    if (n % i == 0){
      if (n / i == i)
        res.pb(i);
      else{
        res.pb(i); 
        res.pb(n / i);
      } 
    }
  } 
  return res;
}
set<int> sieve(int MAXN){
  // int MAXN = 1e7;
  vector<int> sieveprimefact(MAXN);
  sieveprimefact[1]=1;
  vector<int> spf=sieveprimefact;
  for(int i=2;i<MAXN;i++){
    spf[i]=i;
  }
  for(int i=4;i<MAXN;i+=2){
    spf[i]=2;
  }
  for(int i=3;i*i<MAXN;i++){
    if(spf[i]==i){
      for(int j=i*i;j<MAXN;j+=i){
        if(spf[j]==j){
          spf[j]=i;
        }
      }
    }
  }
  set<int> spfset;
  for(auto it:spf) spfset.insert(it);
  return spfset;
}


/*--------------------------------------LETSSSS GRINDDDD------------------------------------------------------------------------------------*/


int binary_srch(vector<int> &dp, int key){
  int s=0;
  int f=dp.size()-1;
  
  while(s<=f){
    int mid = floor(s + (f-s)/2);
    if(mid==0 && key==dp[mid]){
      return mid;
    }
    if(mid==0 && key<dp[mid]){
      return -1;
    }
    
    if(key>dp[mid-1] && key<=dp[mid]){
      return mid;
    }
    // else if(key==dp[mid-1] && key<dp[mid]){
    //   return mid-1;
    // }
    else if(key>dp[mid]){
      s=mid+1;
    }
    else if(key<=dp[mid-1]){
      f=mid;
    }
  }
  return -1;
}

bool isPalindrome(string &s,int n){
  bool flag=false;
  for(int i=0;i<n/2;i++){
    if(s[i]!=s[n-1-i]){
      flag=true;
      break;
    }
  }
  return flag==false;
}


//---------------------------code starts here--------------------------//
// vector<int> hp(400010,0);
// vector<int> dp(400010,0);

void solve(){
  int n;cin>>n;
  // string s;cin>>s;
  vector<int> vec(n);
  for(int i=0;i<n;i++) cin>>vec[i];          
  // vector<pair<int,int>> query(m);
  // for(int i=0;i<m;i++){cin>>query[i].ff>>query[i].ss;}
  priority_queue<pair<int,int>> pqueue;
  unordered_map<int,int> hashmap;
  map<int,int> hmaps;
  unordered_set<int> sett;
  set<int> sets;
  queue<int> que;
  // sort(vec.begin(),vec.end()); 
  int count=0;
  int cnt=INT_MIN;
  bool flag = true;
  bool flag2 = false;
  int res=0;
  int ans=0;
  // vector<vector<int>> mat(n,vector<int>(n));  
  vector<int> dp(n+1,0);
  fsort(vec);
  rloop(i,n-2,1,1){
    if(vec[i]+vec[i-1]>vec[n-1]){
      res=i-1;
      flag=false;
      break;
    }
  }
  if(flag==false){
    cout<<"YES"<<endl;
    loop(i,0,res+1,1){cout<<vec[i]<<" ";}
    cout<<vec[n-1]<<" ";
    loop(i,res+1,n-1,1){cout<<vec[i]<<" ";}
    cout<<"\n";
    return;
  }
  cout<<"NO"<<endl;
  
  
  
} 
signed main() 
{
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fastio;
  int t1=1;
  // cin >> t1;
  for (int k11 = 1; k11 <= t1; k11++)
  {
    solve();
  }
  return 0;

}







