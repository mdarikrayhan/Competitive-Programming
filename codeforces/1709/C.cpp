    #include <bits/stdc++.h> 
    using namespace std;
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll,ll> p64;
    typedef vector<ll> v64;
    typedef vector<pair<ll,ll> > vop;
    typedef map<ll,ll> mp64;
    #define fo(i,a,b) for(i = a; i <= b; i++)
    #define forsn(i,s,e) for(ll i = s; i < e; i++)
    #define rforn(i,s) for(ll i = s; i >= 0; i--)
    #define pb push_back
    #define pp pop_back
    #define ln  "\n"
    #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
    #define all(x) (x).begin(), (x).end()
    #define f first
    #define s second
    #define yeah  cout<<"Yes"<<endl
    #define nope  cout<<"No"<<endl
    #define mp make_pair
    #define input(a) for(auto &x:a) cin>>x
    #define sz(x) (int)(x).size()
    #define lb lower_bound
    #define ub upper_bound
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
    template<typename T> using QP=priority_queue<T,vector<T>,greater<T>>; 
    template<typename T, typename V>
    void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
    template<typename T>
    void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
    void _print() {cerr << "]\n";}
    template <typename T, typename... V>
    void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
    #ifdef DEBUG
    #define dbg(x...) cerr <<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr<< endl;
    #else
    #define dbg(x...)
    #endif
    const ll MOD=1e9+7;   
    const ll MOD1=998244353;
    const ll INF=1e18;
    ll binpow(ll a,ll b,ll MOD){
        ll ans=1;
        a%=MOD;
        while(b){
            if(b&1)
                ans=(ans*a)%MOD;
            b/=2;
            a=(a*a)%MOD;
        }
        return ans;
    } 
    ll modInverse(ll a, ll M)
    {
        ll m0 = M;
        ll y = 0, x = 1;
        if (M == 1)return 0;
        while(a>1) {
            ll q = a/ M;
            ll t = M;M = a % M, a= t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0)x += m0;
        return x;
    }
    // LOSE YOURSELF
    void solve(){
        string s ;
        cin>>s;
        ll n = s.size(); 
        ll open = n/2  , close = n/2;
        bool ans =  true;
        v64 pos ; 
        forsn(i,0,n){
            if(s[i] == '(') open--;
            if(s[i] == ')') close--;
            if(s[i]=='?') pos.pb(i);
        }
        // dbg(s);
        forsn(i,0,pos.size()){
            // dbg(pos.size());
            if(i<open) s[pos[i]] = '(';
            else s[pos[i]] = ')';
        }
        // dbg(open,close);
        // dbg(s);
        if(open>0 && close>0){
            swap(s[pos[open-1]],s[pos[open]]);
            dbg(s);
            ll  l = 0 ;
            bool ok = true;
            forsn(i,0,n){
                if(s[i] == '(') l++;
                if(s[i] == ')') l--;
                if(l<0) ok=false;
            }
            if(l!=0) ok=false;
            if(ok) ans = false; 
        }
        if(ans) yeah;
        else nope;
    }
    int main()
    {
    fast_cin();
    ll t;
    cin>>t;
    cout<<fixed<<setprecision(0);
    while (t--)
    { 
       solve();
    }
    
    return 0;

    }

   