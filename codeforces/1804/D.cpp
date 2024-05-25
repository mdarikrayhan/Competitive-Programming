#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define all(v) v.begin(), v.end()
#define MAX 200000
#define MOD 1000000007
#define nl '\n'
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int inf = 1e9;

void takeinput(vector<int> &a, int start, int end){for(int i=start;i<=end;i++)cin>>a[i];}
void yes(){cout<<"YES"<<nl;}
void no(){cout<<"NO"<<nl;}
void testcase(int t){cout<<"Case #"<<t<<" : ";}

int exp(int ,int);
int ceildiv(int, int);
int modinv(int);

void solve(int t){
    int n, m; cin>>n>>m;
    
    auto getmn = [](string &s)->int{
        int n = s.size();
        int ans = 0;
        int doublect = 0;
        int i = 0;
        for(;i < n;){
            if(s[i] == '1'){
                if(i < n - 1 && s[i + 1] == '1' && doublect < n / 4){
                    ans++;
                    i += 2;
                    doublect++;
                }else{
                    ans++;
                    i += 1;
                }
            }else{
                i++;
            }
        }
        return ans;
    };
    auto getmx = [](string &s)->int{
        int n = s.size();
        vector<int> segments;
        int currlen = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i - 1] && s[i] == '1'){
                segments.pb(currlen);
                currlen = 1;
            }else currlen++;
        }
        segments.pb(currlen);
        int t2 = 0;
        for(auto segment : segments){
            if(segment > 1){
                t2 += segment/2;
            }
        }
        t2 = max(0ll, n/4 - t2);
        return count(all(s), '1') - t2;
    };
    
    int mn = 0, mx = 0;
    for(int i = 0; i < n; i++){
        string line; cin>>line;
        // debug(line, getmx(line));
        mn += getmn(line); mx += getmx(line);
    }
    cout<<mn<<" "<<mx<<nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    freopen("error.out","w",stderr);
    #endif
    int t = 1;
    //int t; cin>>t; 
    for(int i=1;i<=t;i++){
        solve(i);
    }
}

int exp(int a, int b){
    int res = 1;
    while(b > 0){
        if( b % 2 == 1){
            res = (res * a) % MOD;
        }
        a = (a*a)%MOD;
        b /= 2;
    }
    return res;
}

int ceildiv(int a, int b){
    return (a + b - 1)/b;
}

int modinv(int a){
    return exp(a, MOD - 2);
}