#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using ll = long long; using ld = long double; 
using pii = pair<int,int>; using pll = pair<ll,ll>;
using vi = vector<int>; using vl = vector<ll>; using vc = vector<char>; using vb = vector<bool>;
const int INF = 1e9+10; const ll INF_LL = 2e18; const ld PI = atan2(0,-1);
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define forn(i,a,b) for(auto i=a; i<b; ++i)
#define forr(i,a,b) for(auto i=a; i>b; --i)

#ifdef LOCAL
    #include "/home/dulustan/disk/projects/LIBR/Debug/debug.hpp"
#else
    #define deb(...) 0
#endif


template<int mod>
struct Modint{
	int val;
	Modint() : val(0){};
    Modint(int v) : val(v < 0 ? v + mod : v){};
	Modint(ll v) : val(v % mod){if(val < 0) val += mod;}   

	friend istream& operator>>(istream& in, Modint& a){return in >> a.val;}
	friend ostream& operator<<(ostream& out, Modint a){return out << a.val;}
	friend Modint operator+(Modint a, Modint b){return a.val + b.val >= mod ? a.val + b.val - mod : a.val + b.val;}
	friend Modint operator-(Modint a, Modint b){return a.val - b.val < 0 ? a.val - b.val + mod : a.val - b.val;}
	friend Modint operator*(Modint a, Modint b){return 1ll * a.val * b.val % mod;}
	friend Modint operator/(Modint a, Modint b){return a * inv(b);}
	friend Modint powm(Modint a, ll k){
        Modint res = 1;
        for(; k; k >>= 1, a *= a)
            if(k & 1) res *= a;
        return res; 
    }
	friend Modint inv(Modint a){return powm(a, mod - 2);}
	friend Modint operator-(Modint a){return a.val ? mod - a.val : 0;}
	friend Modint& operator+=(Modint& a, Modint b){return a = a + b;}
	friend Modint& operator-=(Modint& a, Modint b){return a = a - b;}
	friend Modint& operator*=(Modint& a, Modint b){return a = a * b;}
	friend Modint& operator/=(Modint& a, Modint b){return a = a / b;}
	friend Modint& operator++(Modint& a){return a += 1;}
	friend Modint operator++(Modint& a, int){Modint val = a; a += 1; return val;}
	friend Modint& operator--(Modint& a){return a -= 1;}
	friend Modint operator--(Modint& a, int){Modint val = a; a -= 1; return val;}
	friend bool operator==(Modint a, Modint b){return a.val == b.val;}
	friend bool operator!=(Modint a, Modint b){return !(a == b);}
    friend bool operator<(Modint a, Modint b){return a.val < b.val;}
	friend bool operator>(Modint a, Modint b){return a.val > b.val;}

	explicit operator int() const {return val;}
    explicit operator ll() const {return val;}
};

const int mod = 998244353;
using mint = Modint<mod>;

void solve(){
    int n,m; cin >> n >> m;
    string s; cin >> s;
    s = "$$" + s;
    mint ans = 1;
    for(int i=n; i>2; --i){
        if(s[i]=='?')
            ans *= (i-2);
    }
    if(s[2]=='?') cout << "0\n";
    else cout << ans << "\n";

    while(m--){
        int i; char x; cin >> i >> x; ++i;
        if(i==2){
            s[2] = x;
        }
        else{
            if(s[i]!='?' && x!='?') s[i] = x;
            else if(s[i] != x){
                if(s[i]!='?'){
                    s[i] = x;
                    ans *= (i-2);
                } 
                else{
                    s[i] = x;
                    ans /= (i-2);
                }
            }
        }
        if(s[2]=='?') cout << "0\n";
        else cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef LOCAL
        freopen("_in.txt", "r", stdin);
        freopen("_out.txt", "w", stdout);
    #endif    

    int T=1; //cin >> T;
    while(T--){
        solve();
        #ifdef LOCAL
            cout << "\n";
        #endif    
    }
}