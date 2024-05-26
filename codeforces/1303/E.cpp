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


    // dp[a_len][b_len] = length of minimal appropriate prefix of 's' that will allow us to construct a_len of 'a' and b_len of 'b'
    // suppose we want to add the next character of a (which is a[a_len] {zero based indexing}), 
    // .. that is we are trying to make a_len to a_len + 1
    //         it is optimal to choose the first occurrence of a[a_len] in s[s_len, .... |s|).
            
    //         you are probably wondering this might not be optimal,
    //            because there might be an occurence of a[a_len] before s_len index of s which we have not yet used in constructing a_len and b_len
    //         consider this example: s = x x x x x y x. 
    //         a_len = 2 (x x), b_len = 2 (x y). so in this case the next a_len will be taken from the last char in s,
    //         whereas we could have picked up an x from before 'y'. 
    //         but that more optimal case wud be covered in dp[4][2], where we pick up the all the x's before y and we pick up y as well.

    string s, t; cin >> s >> t;

    vector<vector<ll>> next_pos(s.size() + 1, vector<ll>(26, inf));
    for(ll i = s.size() - 1; i >= 0; i--) {
        next_pos[i] = next_pos[i+1];
        next_pos[i][s[i] - 'a'] = i;
    }

    auto calc = [&](string a, string b) -> bool {

        vector<vector<ll>> dp(s.size()+2, vector<ll>(s.size()+2, inf));
        dp[0][0] = 0;

        for(ll i = 0; i <= a.size(); i++) {
            for(ll j = 0; j <= b.size(); j++) {

                if(dp[i][j] > s.size()) {continue;}

                ll s_len = dp[i][j];

                if(i < a.size() && next_pos[s_len][a[i] - 'a'] < inf) {dp[i+1][j] = min(dp[i+1][j], 1 + next_pos[s_len][a[i] - 'a']);}
                if(j < b.size() && next_pos[s_len][b[j] - 'a'] < inf) {dp[i][j+1] = min(dp[i][j+1], 1 + next_pos[s_len][b[j] - 'a']);}

            }
        }

        return (dp[a.size()][b.size()] <= s.size());
    };


    for(ll i = 0; i < t.size(); i++) {
        if(calc(t.substr(0, i), t.substr(i, t.size() - i))) {
            yay;
        }
    }
    meh;

    
    // cout<<"===="<<endl;

}

/*ngu, lesgo*/
int32_t main() {
    Hi_I_am_Subham_Pan
    //cout<<fixed<<setprecision(20)<<x; //-> for printing a double 'x'.

    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
    
    int TT=1;
    cin>>TT; //comment out this line if only 1 test case is needed
    while(TT--) {
        solve();
    }
 
    return 0;
}

