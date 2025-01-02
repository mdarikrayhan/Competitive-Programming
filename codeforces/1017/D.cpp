#include <bits/stdc++.h>
using namespace std;

using ll = long long; using ld = long double;
#define int long long
#define double long double
#define endl '\n'
#define Hi_I_am_Subham_Pan ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define vin(a) for(auto&XX:a)cin>>XX;//idk y but it restricts my thought process at times
#define vout(v) for (auto XX: v)cout<<XX<<' ';cout<<endl;
#define meh {cout<<"NO"<<endl;return;}
#define yay {cout<<"YES"<<endl;return;}
//=======================================================------------------------------------------------------
void print(int t) {cout << t;} 
void print(string t) {cout << t;}
void print(char t) {cout << t;}
void print(double t) {cout << t;}
template <class T, class V> void print(pair <T, V> p);
template <class T> void print(vector <T> v);
template <class T> void print(set <T> v);
template <class T, class V> void print(map <T, V> v);
template <class T> void print(multiset <T> v);
template <class T, class V> void print(pair <T, V> p) {cout << "{"; print(p.first); cout << ","; print(p.second); cout << "}";}
template <class T> void print(vector <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T> void print(set <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T> void print(multiset <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T, class V> void print(map <T, V> v) {cout << "[ "; for (auto i : v) {print(i); cout << " ";} cout << "]\n";}
//=======================================================------------------------------------------------------
// #define pow2(x) (1ll<<(x))
template <typename T, typename U> T cdiv(T x, U y) {assert(y!=0);return (x > 0 ? (x + y - 1) / y : x / y);}
template <typename T, typename U> T fdiv(T x, U y) {assert(y!=0);return (x > 0 ? x / y : (x - y + 1) / y);}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));} //sgn(x) gives -1/0/1
//returns integer, only works if a is a guarantee perfect square
long long sqroot(long long a){long long b = (long long) sqrtl(a);if ((b + 1) * (b + 1) == a){b++;}return b;}
constexpr ll inf = 1E18;
//(raise(a,b) = a^b) [a,b > 0].
long long raise(long long a, long long b) {long long res = 1;for(int i = 0; i<b; i++) {if(inf/res < a) return 0;res *= a;}return res;}
bool isSquare(int n) {int r = sqrtl(1.0L * n);return r*r == n;}
//=======================================================----------------------------------
const int MAX = 200007; //2*10^5 + 7
const int mod = 1000000007; //1e9+7, comment it out if u want to use the other MOD
// // const int MOD = 998244353;
// const double EPS=1E-9;
// const int MAXN = 10000010; //1e7+10
//----------------



void solve() {

    
    ll n, m, Q; cin >> n >> m >> Q;
    const ll k_max = 100;

    vector<ll> w(n); vin(w);

    // precompute wu for every subset (state). set bits in the state mean s[i] == t[i], so add their 'w' value.
    vector<ll> wu(1LL << n);
    for(ll i = 0; i < (1LL << n); i++) {

        for(ll j = 0; j < n; j++) {
            // if jth bit is set in state 'i', add their 'w' to the wu value of state i
            if(i & (1LL << j)) {wu[i] += w[j];}
        
        }

    }

    // convert all strings to integers (which will be indirectly used to obtain the state later) and store their count.
    vector<ll> str_count(1LL << n);
    for(ll i = 0; i < m; i++) {
        string s; cin >> s;
        
        ll val = 0;
        for(ll j = 0; j < n; j++) {if(s[j] == '1') {val += (1LL << j);}}

        str_count[val]++;
    }


    // precompute wu value every possible k for a string.
    // pref_wu[i][j] stores prefix of count up to k = j for string i.
    vector<vector<ll>> pref_wu(1LL << n, vector<ll>(k_max + 1, 0));
    for(ll i = 0; i < (1LL << n); i++) {

        // here 'i' represents the type of string 't' is. And j represents the type of available string 's'.
        // so iterating over all the available string types (j / s) for each (i / t).
        for(ll j = 0; j < (1LL << n); j++) {

            ll all_same = (1LL << n) - 1;
            ll diff = i ^ j;
            ll wu_value = wu[all_same] - wu[diff];
            // cout << i << " " << j << " " << wu_value << endl;
            if(wu_value <= k_max) {pref_wu[i][wu_value] += str_count[j];}

        }

        // accumulate prefix sums of count
        for(ll j = 1; j <= k_max; j++) {pref_wu[i][j] += pref_wu[i][j-1];}

    }


    for(ll q = 0; q < Q; q++) {
        string t; cin >> t;
        ll k; cin >> k;
        
        ll val = 0;
        for(ll j = 0; j < n; j++) {if(t[j] == '1') {val += (1LL << j);}}

        cout << pref_wu[val][k] << endl;

    }




    
    // cout<<"===="<<endl;

}

/*ngu, lesgo*/
int32_t main() {
    Hi_I_am_Subham_Pan
    //cout<<fixed<<setprecision(20)<<x; //-> for printing a double 'x'.

    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
    
    int TT=1;
    // cin>>TT; //comment out this line if only 1 test case is needed
    while(TT--) {
        solve();
    }
 
    return 0;
}

