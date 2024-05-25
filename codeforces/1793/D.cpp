#include<bits/stdc++.h>
using namespace std;
#define int long long


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// // order_of_key(k) : no. of elements < k
// // *find_by_order(i) : value at index i (0-based)

//typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef map<char,int> mc;
#define py cout<<"Yes\n";
#define pn cout<<"No\n";
#define endl "\n";
#define all int i=0;i<n;i++
#define allj int j=0;j<n;j++
#define all1 int i=1;i<=n;i++
#define all1j int j=1;j<=n;j++
#define allm int i=0;i<m;i++
#define sorti(v) sort(v.begin(),v.end());
#define sortig(v) sort(v.begin(),v.end(),greater<int>());
#define take int n;cin>>n;int a[n]; for(all){cin>>a[i];}
#define show(v) for(auto x:v){cout<<x<<" ";}cout<<endl;
#define mnv(v) *min_element(v.begin(), v.end());
#define mxv(v) *max_element(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
#define set_bits __builtin_popcountll
#define debug(x) cerr<<#x<<" is "; _print(x); cerr<<endl;

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 

const int N=1e9+7; //largeprime
//int N=998244353;
const int inf=1e18;
const int NN=1e5+10;
const int sis=2e5+7;

int get(int x){
    return (x*(x + 1)/2);
}
void solve(){
    int n;
    cin>>n;
    int p[n + 1];
    int posp[n + 1];
    for(all1){
        cin>>p[i];
        posp[p[i]] = i;
    }

    int q[n + 1];
    int posq[n + 1];
    for(all1){
        cin>>q[i];
        posq[q[i]] = i;
    }

    int l1 = min(posp[1], posq[1]);
    int r1 = max(posp[1], posq[1]);
    
    int ans = 0;

    if(l1 > 1){
        ans += get(l1 - 1);
    }
    if(r1 < n){
        ans += get(n - r1);
    }
    ans += get(r1 - l1 - 1);

    int m1[n + 1] = {0};
    int m2[n + 1] = {0};

    for(int i = l1; i <= r1; i ++){
        m1[p[i]] = 1;
        m2[q[i]] = 1;
    }

    for(int mex = 2; mex < n; mex ++){
        int prevl1 = l1;
        int prevr1 = r1;
        if(m1[mex] == 0){
            l1 = min(l1, posp[mex]);
            r1 = max(r1, posp[mex]);
        }
        if(m2[mex] == 0){
            l1 = min(l1, posq[mex]);
            r1 = max(r1, posq[mex]);
        }

        int k1 = min(posp[mex], posq[mex]);
        int k2 = max(posp[mex], posq[mex]);

        // debug(prevl1)
        // debug(prevr1)
        // debug(k1)
        // debug(k2)
        // debug(l1)
        // debug(r1)
        if(!m1[mex] && !m2[mex]){
            // debug(ans)
            if(k2 < prevl1){
                ans += (prevl1 - k2) * (n - prevr1 + 1);
            }
            else if(k1 > prevr1){
                ans += prevl1 * (k1 - prevr1);
            }
            else{
                ans += (prevl1 - k1) * (k2 - prevr1);
            }
            // debug(ans)
        }

        for(int i = l1; i <= prevl1; i ++){
            m1[p[i]] = 1;
            m2[q[i]] = 1;
        }
        for(int i = prevr1; i <= r1; i ++){
            m1[p[i]] = 1;
            m2[q[i]] = 1;
        }
    }

    ans ++;

    cout<<ans<<endl;
}

int t=1;

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int t; cin>>t;
    while(t--){
        solve();
    }
}

