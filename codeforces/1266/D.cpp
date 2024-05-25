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

    ll n, m; cin >> n >> m;
    vector<ll> vals(n, 0);

    for(ll i = 0; i < m; i++) {
        ll u, v, d;  cin >> u >> v >> d; u--; v--;
        vals[u] += d;
        vals[v] -= d;
    }


    // print(vals);

    vector<pair<ll, ll>> outgoing;
    vector<pair<ll, ll>> incoming;

    for(ll i = 0; i < n; i++) {
        if(vals[i] > 0) {
            outgoing.push_back({abs(vals[i]), i});
        } else if (vals[i] < 0) {
            incoming.push_back({abs(vals[i]), i});
        }
    }

    ll ptr_outgoing = 0;
    vector<vector<ll>> ans;
    for(auto x : incoming) {
        vector<ll> temp;

        ll wt_incoming = x.first; // reqd
        ll node_incoming = x.second;

        while(true) {
            ll curr_wt_outgoing = outgoing[ptr_outgoing].first; // available
            ll node_outgoing = outgoing[ptr_outgoing].second;

            ll wt_reqd = wt_incoming;
            ll wt_available = curr_wt_outgoing;

            if(wt_reqd <= wt_available) {

                temp.push_back(node_outgoing + 1);
                temp.push_back(node_incoming + 1);
                temp.push_back(wt_incoming);

                ans.push_back(temp);
                temp.clear();

                outgoing[ptr_outgoing].first -= wt_reqd;
                wt_incoming -= wt_available;
                
                if(outgoing[ptr_outgoing].first == 0) {
                    ptr_outgoing++;
                }

                break;

            } else {

                temp.push_back(node_outgoing + 1);
                temp.push_back(node_incoming + 1);
                temp.push_back(wt_available);

                ans.push_back(temp);
                temp.clear();

                outgoing[ptr_outgoing].first -= wt_available;
                wt_incoming -= wt_available;
                ptr_outgoing++;

            }
        }
        
    }

    cout << ans.size() << endl;
    for(auto v : ans) {
        vout(v);
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

