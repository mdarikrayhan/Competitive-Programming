








#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define               int long long
#define               ld  long double 
#define               inf 1e18
#define               pb push_back
#define               F first
#define               S second
#define               pii pair<int,int>
#define               vpii vector<pair<int,int>>
#define               vi vector<int>
#define               vvi vector< vector<int> >
#define               vii vector< pair<int,int> >
#define               f(i,a,b) for(int i=a;i<b;i++)
#define               Sort(a) sort(a.begin(),a.end())
#define               all(x) (x).begin(), (x).end()
#define               mii  map<int,int> 
#define               mvi  map<int,vi>
#define               yes  cout<<"YES\n"
#define               no   cout<<"NO\n"
#define               sz(x) (int)(x).size()

const int mod=1e9+7;
                                       
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // *find_by_order(idx), order_of_key(key)
                                        
void input(vector<int>&v){
for(int i=0;i<v.size();i++) cin>>v[i];
}

int cel(int a,int b){
    int res=a/b;
    if(b*res!=a)res+=(a>0)&(b>0);
    return res;
}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int binmult(int a , int b , int  m){
    // for calculating a*b without making an overflow
    int ans=0;
    while(b){
        if(b&1){
            ans=(ans+a)%m;
        }
        a=(a+a)%m;
        b>>=1;
    }
    return ans;
}

int binexp(int a , int b , int M){
    a%=M ;// for large a
    int ans=1;
    while(b){
        if(b&1){
            ans=binmult(ans,a,M);
        }
        a=binmult(a,a,M);
        b>>=1;
    }
    return ans;
}

void primefac(int n , map<int,int> &m){
    while(n%2==0){
            n/=2;
            m[2]++;
        }
        for(int j=3;j<=sqrt(n);j+=2){
            while(n%j==0){
                n/=j;
                m[j]++;
            }
        }
        if(n!=1) m[n]++;
}


void solve(){
    int n,s;
    cin>>n>>s;
    if(s/n==1){
        no;
        return;
    }
    yes;
    f(i,0,n){
        if(i==0) cout<<s/n+s%n<<" ";
        else cout<<s/n<<" ";
    }
    cout<<'\n';
    cout<<1<<"\n";
}

int32_t main(){
ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

int t=1;
// cin>>t;
while(t--) solve();
return 0;
}