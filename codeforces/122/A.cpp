#include <bits/stdc++.h>
using namespace std;


#define endl '\n'
#define int long long
#define vi vector<int>
#define ms multiset<int>
#define vs vector<string>
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vector<int>,greater<int>>
#define mod 1000000007
#define mod1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define vpi vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define uset unordered_set<ll>
#define umap unordered_map<ll,ll>



//vector
void viin(vi &a){for(int i=0;i<a.size();i++) cin>>a[i];}
void viout(vi &a){for(int i=0;i<a.size();i++) cout<<a[i] << ' ';cout << endl;}
ll visum(vi &a){ll res=0;for(auto x:a) res+=x;return res;}
ll vimin(vi &a){ll res=a[0];for(auto x:a) res=min(res,x);return res;}
ll vimax(vi &a){ll res=a[0];for(auto x:a) res=max(res,x);return res;}
vb sieve(int n){vb is_prime(n+1, true);is_prime[0] = is_prime[1] = false;for (int i = 2; i <= n; i++) {if (is_prime[i] && (i*i) <= n) {for (int j = i * i; j <= n; j += i)is_prime[j] = false;}}return is_prime;}
vi prefixSum(vi a){int n=a.size();for(int i=1;i<n;i++) a[i]+=a[i-1];return a;}
vi suffixSum(vi a){int n=a.size();for(int i=n-2;i>=0;i--) a[i]+=a[i+1];return a;}
ll ncr(int n, int k) {double res = 1;for (int i = 1; i <= k; ++i)res = res * (n - k + i) / i;return (int)(res + 0.01);}
ll apowb(ll a, ll b) {ll res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}
ll modpow(ll a, ll b, ll m) {a %= m;ll res = 1;while (b > 0) {if (b & 1)res = res * a % m;a = a * a % m;b >>= 1;}return res;}
vector<int> primes(int n){vector<int> p(n+1, 1);for(int i = 2; i*i <= n; i++){if(p[i]){for(int j = i*i; j <= n; j += i){p[j] = 0;}}}vector<int> ans;for(int i = 2; i <= n; i++) {if(p[i])    ans.push_back(i);}return ans;}
multiset<int> primefactors(int n){multiset<int> ans;while(n%2 == 0){ans.insert(2);n = n/2;}for(int i = 3; i <= sqrt(n); i+=2){while(n % i == 0){ans.insert(i);n = n/i;}}if(n > 2)   ans.insert(n);return ans;}
int gcd (int a, int b) { while (b) {a %= b;swap(a, b);}return a;}
int lcm (int a, int b) {return a / gcd(a, b) * b;}
int countSetBits(int n){int count = 0;while (n){n = n & (n - 1);count++;}return count;}
bool isDivisibleByPowerOf2(int n, int k) {int powerOf2 = 1 << k;return (n & (powerOf2 - 1)) == 0;}
bool isPowerOfTwo(int n) {return n && !(n & (n - 1));}



// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************


int ok(int x){
    while(x){
        int rem = x % 10;
        if(rem == 4 or rem == 7)    {
            x /= 10;
        }
        else    return 0;
    }
    return 1;
}

void solve(){
    int n;
    cin >> n;

    for(int i = 4; i <= n; i++){
        if(ok(i) and (n%i) == 0){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}



// ME A NOOB, ALWAYS A NOOB