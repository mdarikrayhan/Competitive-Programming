#include<bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define int long long
#define vi vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define bck(i,a,b) for(int i=a;i>=b;i--)
#define trav(a,x) for (auto& a : x)
#define nl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define fr first
#define sc second
#define vpi vector<pair<int,int>>
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
#define bitcount(x) __builtin_popcount(x)
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pneg cout<<"-1"<<endl
int M = 1e9+7;
const int N = 1e5+10;

int inv(int i) {if (i == 1) return 1; return (M - ((M / i) * inv(M % i)) % M) % M;}
int mod_mul(int a, int b) {a = a % M; b = b % M; return (((a * b) % M) + M) % M;}
int mod_add(int a, int b) {a = a % M; b = b % M; return (((a + b) % M) + M) % M;}
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
int ceil_div(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}
int pwr(int a, int b) {a %= M; int res = 1; while (b > 0) {if (b & 1) res = res * a % M; a = a * a % M; b >>= 1;} return res;}

void solve(){
    int n,x;
    cin>>n>>x;
    vi a(n);
    trav(A,a)
    cin>>A;
    auto b = a;
    sort(all(b));
    if(b==a){py; return;}
    
        rep(i,n-x,x){
            if(a[i]!=b[i]){
                pn;
                return;
            }
        }
        py;
    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt=1; cin>>tt; while(tt--)
        solve();
    return 0;
}