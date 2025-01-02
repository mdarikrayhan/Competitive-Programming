#include <bits/stdc++.h>

#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define M 1000000007
#define INFL 1000000000000000000
// #define INF 1000000000
#define pi 3.141592653589793238462643383279
// #define maxn 100000
#define forn(i, n) for (int i = 0; i < int(n); i++)
// #define endl '\n'
#define mp make_pair
#define pb push_back
#define FF(i,a,b) for(ll i=a;i<b;i++)
#define FB(i,a,b) for(ll i=a;i>=b;i--)
#define popb pop_back
#define GCD(x, y) __gcd(x, y)
#define all(x) x.begin(), x.end()
#define fix(n) std::fixed<<std::setprecision(n)
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<pair<long long, long long>> vpll;
typedef map<ll,ll> mpll;
typedef map<int,int> mpii;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x == 1); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';_print(x.first);cerr << ',';_print(x.second);cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;cerr << '{';
      for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ",";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x);
#else
#define debug(x...) ;
#endif
 
// this returns the max value less than x//
int bin_s(int a[], int n, int x)
{
      int i = 0;
      int j = n - 1;
      while (i < j)
      {
            if (x < a[(i + j) / 2])
                  j = (i + j) / 2;
            else
                  i = (i + j) / 2;
            if (j - i == 1)
            {
                  if (a[j] <= x)
                        return j;
                  else
                        return i;
            }
      }
      return 0;
}
 
//---binary exponentiation---//
const ll reme = 998244353;
 
ll expon(ll a, ll n)
{
      ll ans = 1;
      while (n)
      {
            if (n & 1)
            ans = (ans * a)% reme;
            a = (a * a)% reme;
            n >>= 1;
      }
      return ans;
}
 
//-----NUMBER THEORY-----//
bool isprime(ll x)
{
    if(x==1){return false;}
    if(x==2){return true;}
      if(x&1)
      {
            for(int i = 3; i*i <= x; i+=2)
            {
                  if(x%i == 0)
                  {
                        return 0;
                  }
            }
            return 1;
      }
      return 0;
}
 
ll gcdExtended(ll a, ll b, ll *x, ll *y);
 
 
// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
 
      // Base Case
      if (a == 0)
      {
            *x = 0, *y = 1;
            return b;
      }
 
      // To store results of recursive call
      ll x1, y1;
      ll gcd = gcdExtended(b % a, a, &x1, &y1);
 
      // Update x and y using results of recursive
      // call
      *x = y1 - (b / a) * x1;
      *y = x1;
 
      return gcd;
}
 
//-------sieve--------//
const ll maxn = 1000001;
vll prim;
ll lpf[maxn+5] = {0};
void sieve()
{
      lpf[2] = 2;
      prim.pb(2);
      for(ll i = 2; i <= maxn; i+=2)
      {
            lpf[i] = 2;
      }  
      for(ll i = 3; i*i <= maxn; i+=2)
      {
            if(lpf[i] == 0)
            {
                  lpf[i] = i;
                  for(ll j = 2*i; j <= maxn; j+=i)
                        lpf[j] = i;
                  prim.pb(i);
 
            }
      }
      for(ll i = sqrt(maxn); i <= maxn; i++)
      {
            if(lpf[i])
                  continue;
            else 
            {
                  lpf[i] = i;
                  prim.pb(i);
            }
      }
}
 
// // use maps when necessary else use array
// bool valid(string &t)
// {
//       stack<char> st;
//       st.push(t[0]);
//       if(t[0] == ')')
//             return false;
//       for(int i = 1; i < t.size(); i++)
//       {
//             if(t[i] == ')')
//             {
//                   if(st.empty())
//                         return false;
//                   else st.pop();
//             }
//             else st.push('(');
//       }
//       if(st.empty())
//       return true;
//       else return false;
// }
 
// function to print arr of long long------------------
 
void shoar(vector<ll> arr){
    for(auto st: arr){
        cout<<st<<" ";
    }
    cout<<endl;
}
 
//------------------------------------------------------
 
 
// const ll p =998244353;
 
 
//seg tree----------------------------------------------
 
 
// //-----------------------------------------------------
 
 
 
 
 
//    union boiler plat
 
//end of function
 
ll modInverse(ll A, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        // q is quotient
        ll q = A / m;
        ll t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m= A % m, A = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}
 
/*
Tips for soliving question if got stuck
1. Check for sorting and greedy
2. Check for binary search (choose answer check if condtion can be obtained)
3. check for Parity 
4. Check for recurrsion 
*/
// bool isOverflow(long long a, long long b)
// {
//     // Check if either of them is zero
//     if (a == 0 || b == 0) 
//         return false;
     
//     long long result = a * b;
//     if(result>1e18){
//         return true;
//     }
//     if (a == result / b)
//         return false;
//     else
//         return true;
// }
 
 
 
bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
    // Compare based on the first element
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        // If the first elements are the same, compare based on the second element
        return a.second < b.second;
    }
    return false;
}


class DisjointSet{ public:
    vector<int> parent;
    DisjointSet(int n): parent(n) {
         for(int i=0; i<n; i++) parent[i] = i; 
    }
    void join(int a, int b){
        parent[find(b)] = find(a); 
    }
    int find(int a){ 
        return a == parent[a] ? a : parent[a] = find(parent[a]); 
    }
    bool is_same(int a, int b){ 
        return find(a) == find(b); 
    }
};


 
// const int N = 100001;
 
// ll a[N];
// ll t[4 * N];
// ll mult[4 * N];
// ll addn[4 * N] = { 0 };
 
 
// void build(int v, int tl, int tr) {
//       if (tl == tr) {
//             t[v] = a[tl];
//             mult[v] = 1;
//       }
//       else {
//             int tm = (tl + tr) / 2;
//             build(v * 2, tl, tm);
//             build(v * 2 + 1, tm + 1, tr);
//             t[v] = (t[2 * v] | t[2 * v + 1]);
//             mult[v] = 1;
//       }
// } 
// void push(int v, int tl, int tm, int tr) {
 
//       t[2 * v] *= mult[v];
//       t[2 * v + 1] *= mult[v];
//       mult[2 * v] *= mult[v];
//       mult[2 * v + 1] *= mult[v];
//       addn[2 * v] *= mult[v];
//       addn[2 * v + 1] *= mult[v];
//       mult[v] = 1;
//       t[2 * v] += (tm - tl + 1) * addn[v];
//       t[2 * v + 1] += (tr - tm) * addn[v];
//       addn[2 * v] += addn[v];
//       addn[2 * v + 1] += addn[v];
//       addn[v] = 0;
// }
 
// void update(int v, int tl, int tr, int l, int r, ll p, ll q) {
      
//       if (l > r)
//             return;
//       if (tl==l && tr==r) {
//             t[v] *= p;
//             t[v] += (tr - tl + 1) * q;
//             mult[v] *= p;
//             addn[v] *= p;
//             addn[v] += q;
//             return;
//       }
//       int tm = (tl + tr) / 2;
//       push(v, tl, tm, tr);
//       update(2 * v, tl, tm, l, min(tm, r), p, q);
//       update(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, p, q);
//       t[v] = (t[2 * v] | t[2 * v + 1]);
// }
 
 
// ll query(int v, int tl, int tr, int l, int r) {
 
//       if (l > r)
//             return 0;
//       if (l == tl && r == tr)
//             return t[v];
//       int tm = (tl + tr) / 2;
//       push(v, tl, tm, tr);
//       return (query(2 * v, tl, tm, l, min(r, tm)) | query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
// } 


void solve(){
    ll z=2;
    forn(i,25){
        cout<<"? "<<1<<" "<<z<<endl;
        ll x;cin>>x;
        cout<<"? "<<z<<" "<<1<<endl;
        ll y;cin>>y;
        if(x==-1){
            cout<<"! "<<z-1<<endl;return;
        }
        if(x!=y){
            cout<<"! "<<x+y<<endl;return; 
        }
        z++;
    }
}

 
 



 
 
int main()
{
      #ifndef ONLINE_JUDGE
            freopen("input.txt", "r" , stdin);
            freopen("aoutput.txt", "w", stdout);
      #endif
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
//-----------------------------------------//    
 
 
int tc=1;
// cin >> tc;
// sieve();
while (tc--){
      solve();
      debug("endtc");
}
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
return 0;
}